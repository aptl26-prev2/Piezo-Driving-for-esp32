//
// Description: Driving Example
//
// Copyright (c) 2020 Boréas Technologies Inc. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//


/********************************************************
*						Includes
********************************************************/

#include "example.h"

#ifdef EXAMPLE_DRIVING

#include <stdint.h>
#include "spi.h"
#include "math.h"
#include "utils.h"
#include "ledEx.h"
#include "timeEx.h"


/********************************************************
*			        DEFINES / PARAMETERS
********************************************************/
//Channels
#define BOS1901_CHANNEL_A   0
#define BOS1901_CHANNEL_B   1
#define NB_CHANNELS         1

//Reference Values
#define REFERENCE_ZERO       0x0000
#define REFERENCE_PLUS_1LSB  0x0001
#define REFERENCE_MINUS_1LSB 0x0FFF
//Sensing
#define PRESS_HOLD_TIME     180 // Cycles of 125us (8kHz)
#define RELEASE_HOLD_TIME   30  // Cycles of 125us (8kHz)
#define PRESS_THRESHOLD     12  // in LSBs of VFEEDBACK
#define RELEASE_THRESHOLD   0   // in LSBs of VFEEDBACK

//Feedback
#define SIGNAL_SIZE_MAX             256 // Maximum table size
#define PRESS_SIGNAL_VOLTAGE        60  // Volts
#define PRESS_SIGNAL_FREQ           180 // Hertz
#define RELEASE_SIGNAL_VOLTAGE      45  // Volts
#define RELEASE_SIGNAL_FREQ         180 // Hertz
#define REG_READ_VFEEDBACK_MASK     0x03FF

// Piezo Creep
#define CREEP_HOLD_TIME     40 // Cycles of 125us (8kHz)

// Timer
#define TIMER_PERIOD_ACCEL  3 // 3 ticks faster than 125-1

// Trimming
#define FIFO_SPACE_MASK (0x7F)
#define MAX_TRY         10800
#define TRIM_OSC_MAX_POS 0x1F
#define TRIM_OSC_MASK    0x3F


/********************************************************
*						STRUCTURES
********************************************************/

// Sensing Phases
typedef enum  
{
    DrivingState_A_init,
    DrivingState_B_press_setup,
    DrivingState_B_press,
    DrivingState_C_press_feedback,
    DrivingState_D_creep,
    DrivingState_E_release_setup,
    DrivingState_E_release,
    DrivingState_F_release_feedback,
    DrivingState_G_creep
} DrivingState;

// Container for sensing variables
typedef struct {
   DrivingState state;     // current sensing state
   int16_t offset;              // ADC offset for sensing
   uint16_t counter;            // counts time in 8kHz cycles
   uint8_t led;		// associated LED
} Bos1901;

/********************************************************
*						VARIABLES
********************************************************/

// one container of variables per channel
static Bos1901 bos1901[NB_CHANNELS] = 
{
    {DrivingState_A_init, 0, 0, 0}, // Channel A
    // {DrivingState_A_init, 0, 0, 0}  // Channel B
};
static uint16_t press_waveform[SIGNAL_SIZE_MAX];   // Press feedback waveform data points
static uint16_t press_waveform_size = 0;           // Press feedback waveform number of data points
static uint16_t release_waveform[SIGNAL_SIZE_MAX]; // Release feedback waveform data points
static uint16_t release_waveform_size = 0;         // Release feedback waveform number of data points

// Period variables associated with interrupt timer2
extern volatile uint32_t timer2DefaultPeriod;
extern volatile uint32_t timer2NewPeriod;
/*
 * Private Section
 */

/********************************************************
*				 FUNCTIONS DEFINTION
********************************************************/

/////////////////////////////////////////////////////////
//              SUPPORT FUNCTIONS
/////////////////////////////////////////////////////////




// Change to next sensing phase
static void drivingNextState(uint8_t channel) 
{
    // Check current sensing state
    switch(bos1901[channel].state) 
    {
        case DrivingState_A_init:
            bos1901[channel].state = DrivingState_B_press_setup;
            break;
        case DrivingState_B_press_setup:
            bos1901[channel].state = DrivingState_B_press;
            break;
        case DrivingState_B_press:
            bos1901[channel].state = DrivingState_C_press_feedback;
            break;
        case DrivingState_C_press_feedback:
            bos1901[channel].state = DrivingState_D_creep;
            break;
        case DrivingState_D_creep:
            bos1901[channel].state = DrivingState_E_release_setup;
            break;
        case DrivingState_E_release_setup:
            bos1901[channel].state = DrivingState_E_release;
            break;
        case DrivingState_E_release:
            bos1901[channel].state = DrivingState_F_release_feedback;
            break;
        case DrivingState_F_release_feedback:
            bos1901[channel].state = DrivingState_G_creep;
            break;
        case DrivingState_G_creep:
            bos1901[channel].state = DrivingState_B_press_setup;
            break;
        default:
            bos1901[channel].state = DrivingState_A_init;
            break;
    }      
}

// Calculate Press and Release Feedback Waveforms
static void drivingCalculateWaveforms(void)
{

    // Press Feedback Waveform : single sine pulse
    press_waveform_size = PLAY_SAMPLING_RATE / PRESS_SIGNAL_FREQ;
    for(uint8_t i = 0; i < press_waveform_size; i++)
    {
        press_waveform[i] = utilsVolt2Amplitude(PRESS_SIGNAL_VOLTAGE / 2 * (sin(2*M_PI*i/(press_waveform_size) - M_PI/2)+1));
    }
    
    // Release Feedback Waveform : single sine pulse
    release_waveform_size = PLAY_SAMPLING_RATE / RELEASE_SIGNAL_FREQ;
    for(uint8_t i = 0; i < release_waveform_size; i++)
    {
        release_waveform[i] = utilsVolt2Amplitude(RELEASE_SIGNAL_VOLTAGE / 2 * (sin(2*M_PI*i/(release_waveform_size) - M_PI/2)+1));
    }
}

// Wait until BOS1901 internal FIFO is empty
static void drivingWaitFifoEmpty(uint8_t channel)
{
    bool fifoempty = 0;

    //Set up broadcast to read IC_STATUS
    spiReadWriteReg(channel, 0x5617);  // Set BC = IC_STATUS

     // loop until FIFO is empty
    while(!fifoempty)
    {
        uint16_t ic_status_reg = spiReadWriteReg(channel, 0xC000); // dummy write, get IC_STATUS value
        fifoempty = (ic_status_reg >> 6) & 0x1; // extract EMPTY value.
    }
}

// Software trimming element function
bool drivingSoftwareTrim(uint8_t channel)
{
	uint16_t reg = 0;
    bool succeed = 0;
	
	//Need to disable the channel to do software trim
    spiReadWriteReg(channel, 0x5607);

    //Set the mode to read trim values from register. Value will be available in TRIM_REGISTER and can be read from CONFIG BC
    spiReadWriteReg(channel, 0xE800); // TRIMRW = 2, SDOBP = 0, TRIM_OSC = 0, TRIM_REG = 0
	
    //Sets the CONFIG BC to read TRIM register
    spiReadWriteReg(channel, 0x5707);

    //Read TRIM register and add 1 to TRIM_OSC
    reg = spiReadWriteReg(channel, 0x5707);
    uint16_t regMask = 0x3 << 10 | 0x3F << 3;  // mask to manipulate register paramters TRIMRW and TRIM_OSC
    uint16_t TRIM_OSC = ((reg >> 3)  + 0x1) & TRIM_OSC_MASK; // gets TRIM_OSC value and increments 1
    succeed = (((reg >> 3) & TRIM_OSC_MASK) & TRIM_OSC_MAX_POS) != TRIM_OSC_MAX_POS; // check if reached maximum TRIM_OSC value
    reg &= ~regMask; // set TRIM_OSC bits to 0
    reg |= 0x3 << 10; // set TRIMRW to write mode
    reg |= TRIM_OSC << 3; // set new TRIM_OSC value

	//Write the register with new TRIM_OSC parameter
    if(succeed)
    {
        // printf("reg: %x\n\n\n\n\n\n\n\n", reg);
        spiReadWriteReg(channel, reg);
    }
    
	// Reenable output and set BC back to IC_STATUS
    spiReadWriteReg(channel, 0x5617);
    // Clear fifo before exiting
    drivingWaitFifoEmpty(channel);
    
    timeWaitMs(1); // temp
    
    return succeed;
}


// Trim internal oscillator to fit MCU sampling rate
static void drivingTrimming(void) {

    // ledExWrite(LEDEX_D2, color_yellow); // show error.

    // Initialization
	 for(uint8_t channel = 0; channel < NB_CHANNELS; channel++)
     {
        // Reset IC
        spiReadWriteReg(channel, 0x56A7);  // Reset IC, set SDO broadcast to SENSE register to read VFEEDBACK, set PLAY sampling rate to 8kSPS.
        timeWaitMs(1);

        //Set the mode to latch hardware fuses to trim block. Data are available in TRIM register. Trimming will start at factory-trimmed value.
        spiReadWriteReg(channel, 0xE400); // TRIMRW = 1, SDOBP = 0, TRIM_OSC = 0, TRIM_REG = 0

        //sets BC to IC_STATUS & enables output, PLAY = 8kSPS
        spiReadWriteReg(channel, 0x5617);
	}

  	//set the timer at 8.2kHz to have BOS1901 FIFO clear faster than 8kHz
	 timer2NewPeriod = timer2DefaultPeriod - TIMER_PERIOD_ACCEL;

    //For each channel : perfom trimming
    for(int channel = 0; channel < NB_CHANNELS; channel++)
    {
		uint16_t nbTry = 0;
		uint16_t FifoSpacePrev = 0;
        uint16_t FifoSpace = 0;
        bool FifoFull = 0;
        bool FifoEmpty = 0;
    
		for(;;) 
		{
            //try to fill the IC FIFO
			if(timeIsTimerExpired())  // enter everytime timer1 expires (8.2kHz)
			{					
				timeResetTimerFlag();
                					
				//Send 0 V and try to fill the fifo
                // printf("\n\n\nBefore 0\n\n\n");
                uint16_t reg = spiReadWriteReg(channel, 0x0000);
				FifoSpace = reg & FIFO_SPACE_MASK;
                FifoFull = (reg >> 7) & 1;
                FifoEmpty = (reg >> 6) & 1;

                // printf("\n\nReg:%x\n\n", reg);
				// printf("\n\nFifo empty:%d\n\n", FifoEmpty);
                // printf("\n\nFifo Full:%d\n\n", FifoFull);
                // printf("\n\nFifo space:%d\n\n", FifoSpace);
                // printf("\n\nFifo space prev:%d\n\n", FifoSpacePrev);				//First time the fifo will be the initial value (should be 0)
				if(nbTry == 0) 
				{
					FifoSpacePrev = FifoSpace;
				}
				nbTry++;
				printf("\n\nnbTry: %d\n\n", nbTry);          
				//If FIFO has less space than before, data is accumulating in the FIFO
                if ((FifoSpace < FifoSpacePrev && !FifoEmpty) || FifoFull)
                {	
                    // printf("\n\n\n\n inside if \n\n\n\n");  
					if(drivingSoftwareTrim(channel)) // increase oscillator speed
                    {
                        // printf("insinde if \n\n\n\n\n");
    					nbTry = 0;	// redo the loop until the trimming is OK																							
                    }
                    else // error
                    {
                        // ledExWrite(LEDEX_D2, color_red); // show error.
                        while(1);
                    }
				}
				
                
				//If you tried for a long time and did not succeed accumulating points in the fifo
				if(nbTry > MAX_TRY) 
				{
					break; // exit trimming loop
				}
			}
            
        }								
        spiReadWriteReg(channel, 0x5607); // disable output once trimming is done.
    }		

	//set the timer back to 8kHz
    timer2NewPeriod = timer2DefaultPeriod;
    // ledExWrite(LEDEX_D2, color_black); // show error.
}


/////////////////////////////////////////////////////////
//            SENSING PHASES FUNCTIONS
/////////////////////////////////////////////////////////

// Phase A - Sensing Initialization
// Single entry function - executed once when called
static void drivingInit(uint8_t channel)
{
    // Reset
    spiReadWriteReg(channel, 0x56A7);  // Reset IC, set SDO broadcast to SENSE register to read VFEEDBACK, set PLAY sampling rate to 8kSPS.
    timeWaitMs(50);
    
    // Get ADC offset value
    spiReadWriteReg(channel, 0x77E7);  // Set SENSE = 0 & VDD = 31 (5V supply), TI_RISE = default
    spiReadWriteReg(channel, 0x5697);  // Set OE = 1, uses same values as before for other parameters
    spiReadWriteReg(channel, REFERENCE_ZERO);  // Write 0x0000 to set the output to 0V
    timeWaitMs(50);                        // wait 50ms
    uint16_t reg_read = spiReadWriteReg(channel, REFERENCE_ZERO);  // Write 0x0000 again to get the ADC offset value.
    bos1901[channel].offset = reg_read & REG_READ_VFEEDBACK_MASK;    // save for later

    drivingNextState(channel);          // to go next phase   
}

// Entering Phase B - Press Sensing Setup
// Single entry function - executed once when called
static void drivingPressSetup(uint8_t channel)
{
    spiReadWriteReg(channel, 0x7FE7);  // set SENSE = 1
    spiReadWriteReg(channel, 0x5697);  // Set BC = SENSE
    spiReadWriteReg(channel, REFERENCE_PLUS_1LSB);  // write 0x0001 to set the bridge to positive polarity

    drivingNextState(channel);          // go to next phase
}

// Phase B - Press Sensing
// Multiple entry function - entered every time the timer expires
static void drivingPress(uint8_t channel)
{
    int16_t vfeedback = spiReadWriteReg(channel, REFERENCE_PLUS_1LSB) & REG_READ_VFEEDBACK_MASK;  // Write 0x0001 and read VFEEDBACK
    int16_t vsense = vfeedback - bos1901[channel].offset; // subtract the ADC offset value
    // printf("sensing %d\n\n", vsense);
    if(vsense >= PRESS_THRESHOLD) // compare to threshold
    {
        printf("\n\n\n\n Sensing \n\n\n\n");
        bos1901[channel].counter++; // increase counter value to implement hold time check
        if(bos1901[channel].counter >= PRESS_HOLD_TIME) { // detection successful
            bos1901[channel].counter = 0; // reset counter 
            // ledExWrite(bos1901[channel].led, color_green);
            drivingNextState(channel);  // go to next phase
        }
    }
}

// Phase C - Press Feedback Waveform
// Multiple entry function - entered every time the timer expires
static void drivingPressFeedback(uint8_t channel)
{
    if(bos1901[channel].counter == 0)  // when starting this phase only
    {
        drivingWaitFifoEmpty(channel); // wait until BOS1901 internal FIFO is empty before sending the waveform points.
        spiReadWriteReg(channel, 0x77E7);  // set SENSE = 0 to drive the output
    }
    
    if(bos1901[channel].counter < press_waveform_size) // playing the waveform
    {
        spiReadWriteReg(channel,press_waveform[bos1901[channel].counter++]);// Timer expired: send a new point
    } 
    else // waveform reached its last point
    {
        bos1901[channel].counter = 0;// cleanup
        spiReadWriteReg(channel,press_waveform[0]); // completing the waveform by playing the initial point again.
        drivingNextState(channel); // to go next phase
    }
}

// Phases D - Press Creep Stabilization
// Single entry function - executed once when called
static void drivingPressCreepStabilization(uint8_t channel)
{
    spiReadWriteReg(channel, REFERENCE_MINUS_1LSB);   // set FIFO to 0x0FFF
    timeWaitMs(1000*CREEP_HOLD_TIME/SAMPLING_RATE); // wait defined time

    drivingNextState(channel); // to go next phase
}

// Entering Phase E - Release Sensing Setup
// Single entry function - executed once when called
static void drivingReleaseSetup(uint8_t channel)
{
    spiReadWriteReg(channel, 0x7FE7);  // set SENSE = 1
    spiReadWriteReg(channel, 0x5697);  // Set BC = SENSE
    spiReadWriteReg(channel, REFERENCE_MINUS_1LSB);  // write 0x0FFF to set the bridge to negative polarity

    drivingNextState(channel);          // go to next phase
}

// Phase E - Release Sensing
// Multiple entry function - entered every time the timer expires
static void drivingRelease(uint8_t channel)
{
    int16_t vfeedback = spiReadWriteReg(channel, REFERENCE_MINUS_1LSB) & REG_READ_VFEEDBACK_MASK;  // Write 0x0FFF and read VFEEDBACK (use on read value)
    int16_t vsense = vfeedback - bos1901[channel].offset; // subtract the ADC offset value
    if(vsense >= RELEASE_THRESHOLD) // compare to threshold, increase counter value
    {
        bos1901[channel].counter++; // increase counter value to implement hold time check
        if(bos1901[channel].counter >= RELEASE_HOLD_TIME) { // detection successful
            bos1901[channel].counter = 0; // reset counter 
            // ledExWrite(bos1901[channel].led, color_black);
            drivingNextState(channel);  // go to next phase
        }
    }
}

// Phase F - Release Feedback Waveform
// Multiple entry function - entered every time the timer expires
static void drivingReleaseFeedback(uint8_t channel)
{
    if(bos1901[channel].counter == 0) // when starting this phase only
    {
        drivingWaitFifoEmpty(channel); // wait until BOS1901 internal FIFO is empty before sending the waveform points.
        spiReadWriteReg(channel, 0x77E7);  // set SENSE = 0 to drive the output
    }
    
    if(bos1901[channel].counter < release_waveform_size) // playing the waveform
    {
        spiReadWriteReg(channel,release_waveform[bos1901[channel].counter++]); // Timer expired: send a new point
    } 
    else // waveform reached its last point
    {
        bos1901[channel].counter = 0; // cleanup
        spiReadWriteReg(channel,release_waveform[0]); // completing the waveform by playing the initial point again.
        drivingNextState(channel); // to go next phase
    }
}
    
// Phases G - Release Creep Stabilization
// Single entry function - executed once when called
static void drivingReleaseCreepStabilization(uint8_t channel)
{
    spiReadWriteReg(channel, REFERENCE_MINUS_1LSB);   // set FIFO to 0x0FFF
    timeWaitMs(1000*CREEP_HOLD_TIME/SAMPLING_RATE); // wait defined time

    drivingNextState(channel); // to go next phase
}

// Enter selected phass
// Multiple entry function - entered every time the timer expires
static void drivingEnterPhase(uint8_t channel)
{
    // check current state and execute associated function
    switch(bos1901[channel].state) {
        case DrivingState_A_init:
            drivingInit(channel);
            break;
        case DrivingState_B_press_setup:
            drivingPressSetup(channel);
            break;
        case DrivingState_B_press:
            drivingPress(channel);
            break;
        case DrivingState_C_press_feedback:
            drivingPressFeedback(channel);
            break;
        case DrivingState_D_creep:
            drivingPressCreepStabilization(channel);
            break;
        case DrivingState_E_release_setup:
            drivingReleaseSetup(channel);
            break;
        case DrivingState_E_release:
            drivingRelease(channel);
            break;
        case DrivingState_F_release_feedback:
            drivingReleaseFeedback(channel);
            break;
        case DrivingState_G_creep:
            drivingReleaseCreepStabilization(channel);
            break;
        default:
            bos1901[channel].state = DrivingState_A_init;
            drivingInit(channel);
            break;
    }      
}


// Executing sensing
static void drivingExecuteSensing()
{
    // Enters every time the 8kHz timer expires
    if(timeIsTimerExpired())
    {
    	// timeResetTimerFlag(); // reset flag for time-based operations
        
        // for each channel
        for(uint8_t i = 0; i < NB_CHANNELS; i++) 
        {
            drivingEnterPhase(i);
        }
    }
}



/*
 * Public Section
 */

/********************************************************
*				    MAIN EXAMPLE
********************************************************/
void example(void)
{
    // Variables initialization
    drivingCalculateWaveforms();

    // Oscillator Trimming
    drivingTrimming();

    printf("\n\n\n\n\n\n Passed Trimming \n\n\n\n\n");
    // Infinite loop
    for(;;) 
    {
        // drivingExecuteSensing();
        // vTaskDelay(1);
        if(bos1901[0].counter < press_waveform_size) // playing the waveform
        {
            spiReadWriteReg(0,press_waveform[bos1901[0].counter++]);// Timer expired: send a new point
        } 
        else {
            bos1901[0].counter = 0;
        }
    }
}



/*
 * Private Section
 */

#endif






// //
// // Description: Driving Example
// //
// // Copyright (c) 2020 Boréas Technologies Inc. All rights reserved.
// //
// // Permission is hereby granted, free of charge, to any person obtaining a copy
// // of this software and associated documentation files (the "Software"), to deal
// // in the Software without restriction, including without limitation the rights
// // to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// // copies of the Software, and to permit persons to whom the Software is
// // furnished to do so, subject to the following conditions:
// //
// // The above copyright notice and this permission notice shall be included in all
// // copies or substantial portions of the Software.
// //
// // THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// // IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// // FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// // AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// // LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// // OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// // SOFTWARE.
// //


// /********************************************************
// *						Includes
// ********************************************************/

// #include "example.h"

// #ifdef EXAMPLE_DRIVING

// #include <stdint.h>
// #include "spi.h"
// #include "math.h"
// #include "utils.h"
// // #include "ledEx.h"
// #include "timeEx.h"


// /********************************************************
// *			        DEFINES / PARAMETERS
// ********************************************************/
// //Channels
// #define BOS1901_CHANNEL_A   0
// #define BOS1901_CHANNEL_B   1
// #define NB_CHANNELS         1

// //Reference Values
// #define REFERENCE_ZERO       0x0000
// #define REFERENCE_PLUS_1LSB  0x0001
// #define REFERENCE_MINUS_1LSB 0x0FFF
// //Sensing
// #define PRESS_HOLD_TIME     180 // Cycles of 125us (8kHz)
// #define RELEASE_HOLD_TIME   30  // Cycles of 125us (8kHz)
// #define PRESS_THRESHOLD     12  // in LSBs of VFEEDBACK
// #define RELEASE_THRESHOLD   0   // in LSBs of VFEEDBACK

// //Feedback
// #define SIGNAL_SIZE_MAX             256 // Maximum table size
// #define PRESS_SIGNAL_VOLTAGE        60  // Volts
// #define PRESS_SIGNAL_FREQ           180 // Hertz
// #define RELEASE_SIGNAL_VOLTAGE      45  // Volts
// #define RELEASE_SIGNAL_FREQ         180 // Hertz
// #define REG_READ_VFEEDBACK_MASK     0x03FF

// // Piezo Creep
// #define CREEP_HOLD_TIME     40 // Cycles of 125us (8kHz)

// // Timer
// #define TIMER_PERIOD_ACCEL  3 // 3 ticks faster than 125-1

// // Trimming
// #define FIFO_SPACE_MASK (0x7F)
// #define MAX_TRY         10800
// #define TRIM_OSC_MAX_POS 0x1F
// #define TRIM_OSC_MASK    0x3F


// /********************************************************
// *						STRUCTURES
// ********************************************************/

// // Sensing Phases
// typedef enum  
// {
//     DrivingState_A_init,
//     DrivingState_B_press_setup,
//     DrivingState_B_press,
//     DrivingState_C_press_feedback,
//     DrivingState_D_creep,
//     DrivingState_E_release_setup,
//     DrivingState_E_release,
//     DrivingState_F_release_feedback,
//     DrivingState_G_creep
// } DrivingState;

// // Container for sensing variables
// typedef struct {
//    DrivingState state;     // current sensing state
//    int16_t offset;              // ADC offset for sensing
//    uint16_t counter;            // counts time in 8kHz cycles
//    uint8_t led;		// associated LED
// } Bos1901;

// /********************************************************
// *						VARIABLES
// ********************************************************/

// // one container of variables per channel
// static Bos1901 bos1901[NB_CHANNELS] = 
// {
//     // {DrivingState_A_init, 0, 0, LEDEX_CHA}, // Channel A
//     // {DrivingState_A_init, 0, 0, LEDEX_CHB}  // Channel B
//     {DrivingState_A_init, 0, 0, 0} // Channel A
//     // {DrivingState_A_init, 0, 0, 0}  // Channel B
// };
// static uint16_t press_waveform[SIGNAL_SIZE_MAX];   // Press feedback waveform data points
// static uint16_t press_waveform_size = 0;           // Press feedback waveform number of data points
// static uint16_t release_waveform[SIGNAL_SIZE_MAX]; // Release feedback waveform data points
// static uint16_t release_waveform_size = 0;         // Release feedback waveform number of data points

// // Period variables associated with interrupt timer2
// extern volatile uint32_t timer2DefaultPeriod;
// extern volatile uint32_t timer2NewPeriod;
// /*
//  * Private Section
//  */

// /********************************************************
// *				 FUNCTIONS DEFINTION
// ********************************************************/

// /////////////////////////////////////////////////////////
// //              SUPPORT FUNCTIONS
// /////////////////////////////////////////////////////////




// // Change to next sensing phase
// static void drivingNextState(uint8_t channel) 
// {

//     printf("inside next state, State: %d \n", bos1901[channel].state);
//     // Check current sensing state

//     switch(bos1901[channel].state) 
//     {
//         case DrivingState_A_init:
//             bos1901[channel].state = DrivingState_B_press_setup;
//             break;
//         case DrivingState_B_press_setup:
//             bos1901[channel].state = DrivingState_B_press;
//             break;
//         case DrivingState_B_press:
//             bos1901[channel].state = DrivingState_C_press_feedback;
//             break;
//         case DrivingState_C_press_feedback:
//             bos1901[channel].state = DrivingState_D_creep;
//             break;
//         case DrivingState_D_creep:
//             bos1901[channel].state = DrivingState_E_release_setup;
//             break;
//         case DrivingState_E_release_setup:
//             bos1901[channel].state = DrivingState_E_release;
//             break;
//         case DrivingState_E_release:
//             bos1901[channel].state = DrivingState_F_release_feedback;
//             break;
//         case DrivingState_F_release_feedback:
//             bos1901[channel].state = DrivingState_G_creep;
//             break;
//         case DrivingState_G_creep:
//             bos1901[channel].state = DrivingState_B_press_setup;
//             break;
//         default:
//             bos1901[channel].state = DrivingState_A_init;
//             break;
//     }      
// }

// // Calculate Press and Release Feedback Waveforms
// static void drivingCalculateWaveforms(void)
// {
//     printf("inside calculating waveforms \n");

//     // Press Feedback Waveform : single sine pulse
//     press_waveform_size = PLAY_SAMPLING_RATE / PRESS_SIGNAL_FREQ;
//     for(uint8_t i = 0; i < press_waveform_size; i++)
//     {
//         press_waveform[i] = utilsVolt2Amplitude(PRESS_SIGNAL_VOLTAGE / 2 * (sin(2*M_PI*i/(press_waveform_size) - M_PI/2)+1));
//     }
    
//     // Release Feedback Waveform : single sine pulse
//     release_waveform_size = PLAY_SAMPLING_RATE / RELEASE_SIGNAL_FREQ;
//     for(uint8_t i = 0; i < release_waveform_size; i++)
//     {
//         release_waveform[i] = utilsVolt2Amplitude(RELEASE_SIGNAL_VOLTAGE / 2 * (sin(2*M_PI*i/(release_waveform_size) - M_PI/2)+1));
//     }
// }

// // Wait until BOS1901 internal FIFO is empty
// static void drivingWaitFifoEmpty(uint8_t channel)
// {
//     printf("inside fifo empty \n");
//     bool fifoempty = 0;

//     //Set up broadcast to read IC_STATUS
//     spiReadWriteReg(channel, 0x5617);  // Set BC = IC_STATUS

//      // loop until FIFO is empty
//     while(!fifoempty)
//     {
//         uint16_t ic_status_reg = spiReadWriteReg(channel, 0xC000); // dummy write, get IC_STATUS value

//         fifoempty = (ic_status_reg >> 6) & 0x1; // extract EMPTY value.
//         printf("fifoEmpty: %d\n", fifoempty);
//     }
//     printf("\n\nend of fifo empty\n ");
// }

// // Software trimming element function
// bool drivingSoftwareTrim(uint8_t channel)
// {
//     printf("inside software trim \n");
// 	uint16_t reg = 0;
//     bool succeed = 0;
	
// 	//Need to disable the channel to do software trim
//     spiReadWriteReg(channel, 0x5607);

//     //Set the mode to read trim values from register. Value will be available in TRIM_REGISTER and can be read from CONFIG BC
//     spiReadWriteReg(channel, 0xE800); // TRIMRW = 2, SDOBP = 0, TRIM_OSC = 0, TRIM_REG = 0
	
//     //Sets the CONFIG BC to read TRIM register
//     spiReadWriteReg(channel, 0x5707);

//     //Read TRIM register and add 1 to TRIM_OSC
//     reg = spiReadWriteReg(channel, 0x5707);
//     printf("reg1: %x\n", reg);
//     uint16_t regMask = 0x3 << 10 | 0x3F << 3;  // mask to manipulate register paramters TRIMRW and TRIM_OSC
//     uint16_t TRIM_OSC = ((reg >> 3)  + 0x1) & TRIM_OSC_MASK; // gets TRIM_OSC value and increments 1
//     succeed = (((reg >> 3) & TRIM_OSC_MASK) & TRIM_OSC_MAX_POS) != TRIM_OSC_MAX_POS; // check if reached maximum TRIM_OSC value
//     reg &= ~regMask; // set TRIM_OSC bits to 0
//     reg |= 0x3 << 10; // set TRIMRW to write mode
//     reg |= TRIM_OSC << 3; // set new TRIM_OSC value
//     printf("reg2: %x\n", reg);
// 	//Write the register with new TRIM_OSC parameter
//     if(succeed)
//     {
//         spiReadWriteReg(channel, reg);
//     }
    
// 	// Reenable output and set BC back to IC_STATUS
//     spiReadWriteReg(channel, 0x5617);
//     // Clear fifo before exiting
//     drivingWaitFifoEmpty(channel);
    
//     timeWaitMs(1); // temp

//     printf("end of software trim\n");

//     printf("Succeed %d\n", succeed);
    
//     return succeed;
// }


// // Trim internal oscillator to fit MCU sampling rate
// static void drivingTrimming(void) {

//     // ledExWrite(LEDEX_D2, color_yellow); // show error.

//     // Initialization
//     printf("inside driving trimming\n");
// 	 for(uint8_t channel = 0; channel < NB_CHANNELS; channel++)
//      {
//         printf("inside first loop\n");
//         // Reset IC
//         // printf("before target function\n");
//         spiReadWriteReg(channel, 0x56A7);  // Reset IC, set SDO broadcast to SENSE register to read VFEEDBACK, set PLAY sampling rate to 8kSPS.
//         timeWaitMs(1);

//         //Set the mode to latch hardware fuses to trim block. Data are available in TRIM register. Trimming will start at factory-trimmed value.
//         spiReadWriteReg(channel, 0xE400); // TRIMRW = 1, SDOBP = 0, TRIM_OSC = 0, TRIM_REG = 0

//         //sets BC to IC_STATUS & enables output, PLAY = 8kSPS
//         spiReadWriteReg(channel, 0x5617);
// 	}
    
//     printf("after first loop\n");
//   	//set the timer at 8.2kHz to have BOS1901 FIFO clear faster than 8kHz
// 	 timer2NewPeriod = timer2DefaultPeriod - TIMER_PERIOD_ACCEL;


//     //For each channel : perfom trimming
//     for(int channel = 0; channel < NB_CHANNELS; channel++)
//     {
//         printf("inside second loop\n");
// 		uint16_t nbTry = 0;
// 		uint16_t FifoSpacePrev = 0;
//         uint16_t FifoSpace = 0;
//         bool FifoFull = 0;
//         bool FifoEmpty = 0;
    
// 		for(;;) 
// 		{
//             //try to fill the IC FIFO
// 			if(timeIsTimerExpired())  // enter everytime timer1 expires (8.2kHz)
// 			{					
//                 printf("inside if(timeIsTimerExpired()) \n");
// 				timeResetTimerFlag();
                					
// 				//Send 0 V and try to fill the fifo
//                 uint16_t reg = spiReadWriteReg(channel, 0x0000);
// 				FifoSpace = reg & FIFO_SPACE_MASK;
//                 FifoFull = (reg >> 7) & 1;
//                 FifoEmpty = (reg >> 6) & 1;
				
// 				//First time the fifo will be the initial value (should be 0)
// 				if(nbTry == 0) 
// 				{
//                     printf("inside nbTry \n");
// 					FifoSpacePrev = FifoSpace;
// 				}
// 				nbTry++;
				          
// 				//If FIFO has less space than before, data is accumulating in the FIFO
//                 if ((FifoSpace < FifoSpacePrev && !FifoEmpty) || FifoFull)
//                 {	
//                     printf("inside FifoSpace < FifoSpacePrev \n");
// 					if(drivingSoftwareTrim(channel)) // increase oscillator speed
//                     {
//     					nbTry = 0;	// redo the loop until the trimming is OK																							
//                     }
//                     else // error
//                     {
//                         printf("\n\n\ninside error\n");
//                         // ledExWrite(LEDEX_D2, color_red); // show error.
//                         while(1);
//                     }
// 				}
				
//                 // printf("\n\n nbTry: ");
//                 // printf("%d\n", nbTry);
// 				//If you tried for a long time and did not succeed accumulating points in the fifo
// 				if(nbTry > MAX_TRY) 
// 				{
// 					break; // exit trimming loop
// 				}
// 			}
            
//         }							
//         spiReadWriteReg(channel, 0x5607); // disable output once trimming is done.
//     }	

//     printf("after second loop\n");

// 	//set the timer back to 8kHz
//     timer2NewPeriod = timer2DefaultPeriod;
//     // ledExWrite(LEDEX_D2, color_black); // show error.
// }


// /////////////////////////////////////////////////////////
// //            SENSING PHASES FUNCTIONS
// /////////////////////////////////////////////////////////

// // Phase A - Sensing Initialization
// // Single entry function - executed once when called
// static void drivingInit(uint8_t channel)
// {
//     printf("inside driving Init \n");
//     // Reset
//     spiReadWriteReg(channel, 0x56A7);  // Reset IC, set SDO broadcast to SENSE register to read VFEEDBACK, set PLAY sampling rate to 8kSPS.
//     // timeWaitMs(50);
    
//     // Get ADC offset value
//     spiReadWriteReg(channel, 0x77E7);  // Set SENSE = 0 & VDD = 31 (5V supply), TI_RISE = default
//     spiReadWriteReg(channel, 0x5697);  // Set OE = 1, uses same values as before for other parameters
//     spiReadWriteReg(channel, REFERENCE_ZERO);  // Write 0x0000 to set the output to 0V
//     timeWaitMs(50);                        // wait 50ms
//     uint16_t reg_read = spiReadWriteReg(channel, REFERENCE_ZERO);  // Write 0x0000 again to get the ADC offset value.
//     bos1901[channel].offset = reg_read & REG_READ_VFEEDBACK_MASK;    // save for later

//     drivingNextState(channel);          // to go next phase   
// }

// // Entering Phase B - Press Sensing Setup
// // Single entry function - executed once when called
// static void drivingPressSetup(uint8_t channel)
// {
//     printf("inside driving press setup \n");
//     spiReadWriteReg(channel, 0x7FE7);  // set SENSE = 1
//     spiReadWriteReg(channel, 0x5697);  // Set BC = SENSE
//     spiReadWriteReg(channel, REFERENCE_PLUS_1LSB);  // write 0x0001 to set the bridge to positive polarity

//     drivingNextState(channel);          // go to next phase
// }

// // Phase B - Press Sensing
// // Multiple entry function - entered every time the timer expires
// static void drivingPress(uint8_t channel)
// {
//     printf("inside driving press \n");
//     int16_t vfeedback = spiReadWriteReg(channel, REFERENCE_PLUS_1LSB) & REG_READ_VFEEDBACK_MASK;  // Write 0x0001 and read VFEEDBACK
//     printf("vfeedback: %d\n", vfeedback);
//     int16_t vsense = vfeedback - bos1901[channel].offset; // subtract the ADC offset value
//     printf("vesense: %d\n", vsense);
//     if(vsense >= PRESS_THRESHOLD) // compare to threshold
//     {
//         printf("\n\n\n\n\n\n\n\n\n\n\nsense activated \n\n\n\n\n\n\n\n\n ");
//         bos1901[channel].counter++; // increase counter value to implement hold time check
//         printf("bos1901[channel].counter: %d\n", bos1901[channel].counter);
//         if(bos1901[channel].counter >= PRESS_HOLD_TIME) { // detection successful
//             bos1901[channel].counter = 0; // reset counter 
//             // ledExWrite(bos1901[channel].led, color_green);
//             drivingNextState(channel);  // go to next phase
//         }
//     }
// }

// // Phase C - Press Feedback Waveform
// // Multiple entry function - entered every time the timer expires
// static void drivingPressFeedback(uint8_t channel)
// {
//     printf("inside driving press feedback \n");
//     if(bos1901[channel].counter == 0)  // when starting this phase only
//     {
//         drivingWaitFifoEmpty(channel); // wait until BOS1901 internal FIFO is empty before sending the waveform points.
//         spiReadWriteReg(channel, 0x77E7);  // set SENSE = 0 to drive the output
//     }
    
//     if(bos1901[channel].counter < press_waveform_size) // playing the waveform
//     {
//         spiReadWriteReg(channel,press_waveform[bos1901[channel].counter++]);// Timer expired: send a new point
//     } 
//     else // waveform reached its last point
//     {
//         bos1901[channel].counter = 0;// cleanup
//         spiReadWriteReg(channel,press_waveform[0]); // completing the waveform by playing the initial point again.
//         drivingNextState(channel); // to go next phase
//     }
// }

// // Phases D - Press Creep Stabilization
// // Single entry function - executed once when called
// static void drivingPressCreepStabilization(uint8_t channel)
// {
//     printf("inside drivingPressCreepStabilization \n");
//     spiReadWriteReg(channel, REFERENCE_MINUS_1LSB);   // set FIFO to 0x0FFF
//     timeWaitMs(1000*CREEP_HOLD_TIME/SAMPLING_RATE); // wait defined time

//     drivingNextState(channel); // to go next phase
// }

// // Entering Phase E - Release Sensing Setup
// // Single entry function - executed once when called
// static void drivingReleaseSetup(uint8_t channel)
// {
//     printf("inside drivingReleaseSetup \n");
//     spiReadWriteReg(channel, 0x7FE7);  // set SENSE = 1
//     spiReadWriteReg(channel, 0x5697);  // Set BC = SENSE
//     spiReadWriteReg(channel, REFERENCE_MINUS_1LSB);  // write 0x0FFF to set the bridge to negative polarity

//     drivingNextState(channel);          // go to next phase
// }

// // Phase E - Release Sensing
// // Multiple entry function - entered every time the timer expires
// static void drivingRelease(uint8_t channel)
// {
//     printf("inside drivingRelease \n");
//     int16_t vfeedback = spiReadWriteReg(channel, REFERENCE_MINUS_1LSB) & REG_READ_VFEEDBACK_MASK;  // Write 0x0FFF and read VFEEDBACK (use on read value)
//     int16_t vsense = vfeedback - bos1901[channel].offset; // subtract the ADC offset value
//     if(vsense >= RELEASE_THRESHOLD) // compare to threshold, increase counter value
//     {
//         bos1901[channel].counter++; // increase counter value to implement hold time check

//         if(bos1901[channel].counter >= RELEASE_HOLD_TIME) { // detection successful
//             bos1901[channel].counter = 0; // reset counter 
//             // ledExWrite(bos1901[channel].led, color_black);
//             drivingNextState(channel);  // go to next phase
//         }
//     }
// }

// // Phase F - Release Feedback Waveform
// // Multiple entry function - entered every time the timer expires
// static void drivingReleaseFeedback(uint8_t channel)
// {
//     printf("inside drivingReleaseFeedback \n");
//     if(bos1901[channel].counter == 0) // when starting this phase only
//     {
//         drivingWaitFifoEmpty(channel); // wait until BOS1901 internal FIFO is empty before sending the waveform points.
//         spiReadWriteReg(channel, 0x77E7);  // set SENSE = 0 to drive the output
//     }
    
//     if(bos1901[channel].counter < release_waveform_size) // playing the waveform
//     {
//         spiReadWriteReg(channel,release_waveform[bos1901[channel].counter++]); // Timer expired: send a new point
//     } 
//     else // waveform reached its last point
//     {
//         bos1901[channel].counter = 0; // cleanup
//         spiReadWriteReg(channel,release_waveform[0]); // completing the waveform by playing the initial point again.
//         drivingNextState(channel); // to go next phase
//     }
// }
    
// // Phases G - Release Creep Stabilization
// // Single entry function - executed once when called
// static void drivingReleaseCreepStabilization(uint8_t channel)
// {
//     printf("inside drivingReleaseCreepStabilization \n");
//     spiReadWriteReg(channel, REFERENCE_MINUS_1LSB);   // set FIFO to 0x0FFF
//     timeWaitMs(1000*CREEP_HOLD_TIME/SAMPLING_RATE); // wait defined time

//     drivingNextState(channel); // to go next phase
// }

// // Enter selected phass
// // Multiple entry function - entered every time the timer expires
// static void drivingEnterPhase(uint8_t channel)
// {
//     printf("inside drivingEnterPhase \n");
//     // check current state and execute associated function
//     switch(bos1901[channel].state) {
//         case DrivingState_A_init: 
//             drivingInit(channel);
//             break;
//         case DrivingState_B_press_setup:
//             drivingPressSetup(channel);
//             break;
//         case DrivingState_B_press:
//             drivingPress(channel);
//             break;
//         case DrivingState_C_press_feedback:
//             drivingPressFeedback(channel);
//             break;
//         case DrivingState_D_creep:
//             drivingPressCreepStabilization(channel);
//             break;
//         case DrivingState_E_release_setup:
//             drivingReleaseSetup(channel);
//             break;
//         case DrivingState_E_release:
//             drivingRelease(channel);
//             break;
//         case DrivingState_F_release_feedback:
//             drivingReleaseFeedback(channel);
//             break;
//         case DrivingState_G_creep:
//             drivingReleaseCreepStabilization(channel);
//             break;
//         default:
//             bos1901[channel].state = DrivingState_A_init;
//             drivingInit(channel);
//             break;
//     }      
// }


// // Executing sensing
// static void drivingExecuteSensing()
// {
//     printf("\ninside drivingExecuteSensing \n");
//     // Enters every time the 8kHz timer expires
//     if(timeIsTimerExpired())
//     {
//     	timeResetTimerFlag(); // reset flag for time-based operations
        
//         // for each channel
//         for(uint8_t i = 0; i < NB_CHANNELS; i++) 
//         {
//             drivingEnterPhase(i);

//         }
//     }
// }



// /*
//  * Public Section
//  */

// /********************************************************
// *				    MAIN EXAMPLE
// ********************************************************/
// void example(void)
// {
//     // Variables initialization
//     drivingCalculateWaveforms();

//     // Oscillator Trimming
//     // drivingTrimming();

//     // Infinite loop
//     for(;;) 
//     {
//         drivingExecuteSensing();
//         // vTaskDelay(1000 / portTICK_PERIOD_MS);
//         // drivingPressFeedback(0);
//     }
// }



// /*
//  * Private Section
//  */

// #endif
