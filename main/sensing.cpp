//
// Description: Sensing Example
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

#ifdef EXAMPLE_SENSING

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
#define NB_CHANNELS         2

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


/********************************************************
*						STRUCTURES
********************************************************/

// Sensing Phases
typedef enum
{
    SensingState_A_init,
    SensingState_B_press_setup,
    SensingState_B_press,
    SensingState_C_press_feedback,
    SensingState_D_creep,
    SensingState_E_release_setup,
    SensingState_E_release,
    SensingState_F_release_feedback,
    SensingState_G_creep
} SensingState;

// Container for sensing variables
typedef struct {
   SensingState state;     // current sensing state
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
    // {SensingState_A_init, 0, 0, LEDEX_CHA}, // Channel A
    // {SensingState_A_init, 0, 0, LEDEX_CHB}  // Channel B
    {SensingState_A_init, 0, 0, 0}, // Channel A
    {SensingState_A_init, 0, 0, 0}  // Channel B
};
static uint16_t press_waveform[SIGNAL_SIZE_MAX];   // Press feedback waveform data points
static uint16_t press_waveform_size = 0;           // Press feedback waveform number of data points
static uint16_t release_waveform[SIGNAL_SIZE_MAX]; // Release feedback waveform data points
static uint16_t release_waveform_size = 0;         // Release feedback waveform number of data points

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
static void sensingNextState(uint8_t channel)
{
    // Check current sensing state
    switch(bos1901[channel].state)
    {
        case SensingState_A_init:
            bos1901[channel].state = SensingState_B_press_setup;
            break;
        case SensingState_B_press_setup:
            bos1901[channel].state = SensingState_B_press;
            break;
        case SensingState_B_press:
            bos1901[channel].state = SensingState_C_press_feedback;
            break;
        case SensingState_C_press_feedback:
            bos1901[channel].state = SensingState_D_creep;
            break;
        case SensingState_D_creep:
            bos1901[channel].state = SensingState_E_release_setup;
            break;
        case SensingState_E_release_setup:
            bos1901[channel].state = SensingState_E_release;
            break;
        case SensingState_E_release:
            bos1901[channel].state = SensingState_F_release_feedback;
            break;
        case SensingState_F_release_feedback:
            bos1901[channel].state = SensingState_G_creep;
            break;
        case SensingState_G_creep:
            bos1901[channel].state = SensingState_B_press_setup;
            break;
        default:
            bos1901[channel].state = SensingState_A_init;
            break;
    }
}

// Calculate Press and Release Feedback Waveforms
static void sensingCalculateWaveforms(void)
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
static void sensingWaitFifoEmpty(uint8_t channel)
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


/////////////////////////////////////////////////////////
//            SENSING PHASES FUNCTIONS
/////////////////////////////////////////////////////////

// Phase A - Sensing Initialization
// Single entry function - executed once when called
static void sensingInit(uint8_t channel)
{
    // Reset
    spiReadWriteReg(channel, 0x56A7);  // Reset IC, set SDO broadcast to SENSE register to read VFEEDBACK, set PLAY sampling rate to 8kSPS.
    timeWaitMs(50);

    // Get ADC offset value
    spiReadWriteReg(channel, 0x77E7);  // Set SENSE = 0 & VDD = 31 (5V supply), TI_RISE = default
    spiReadWriteReg(channel, 0x5697);  // Set OE = 1, uses same values as before for other parameters
    spiReadWriteReg(channel, REFERENCE_ZERO);  // Write 0x0000 to set the output to 0V
    timeWaitMs(50);                       // wait 50ms
    uint16_t reg_read = spiReadWriteReg(channel, REFERENCE_ZERO);  // Write 0x0000 again to get the ADC offset value.
    bos1901[channel].offset = reg_read & REG_READ_VFEEDBACK_MASK;    // save for later

    sensingNextState(channel);          // to go next phase
}

// Entering Phase B - Press Sensing Setup
// Single entry function - executed once when called
static void sensingPressSetup(uint8_t channel)
{
    spiReadWriteReg(channel, 0x7FE7);  // set SENSE = 1
    spiReadWriteReg(channel, 0x5697);  // Set BC = SENSE
    spiReadWriteReg(channel, REFERENCE_PLUS_1LSB);  // write 0x0001 to set the bridge to positive polarity

    sensingNextState(channel);          // go to next phase
}

// Phase B - Press Sensing
// Multiple entry function - entered every time the timer expires
static void sensingPress(uint8_t channel)
{
    int16_t vfeedback = spiReadWriteReg(channel, REFERENCE_PLUS_1LSB) & REG_READ_VFEEDBACK_MASK;  // Write 0x0001 and read VFEEDBACK
    int16_t vsense = vfeedback - bos1901[channel].offset; // subtract the ADC offset value
    if(vsense >= PRESS_THRESHOLD) // compare to threshold
    {
        printf("\n\n\n\n\n\nsensed\n\n\n\n\n");
        bos1901[channel].counter++; // increase counter value to implement hold time check
        if(bos1901[channel].counter >= PRESS_HOLD_TIME) { // detection successful
            bos1901[channel].counter = 0; // reset counter
            // ledExWrite(bos1901[channel].led, color_green);
            sensingNextState(channel);  // go to next phase
        }
    }
}

// Phase C - Press Feedback Waveform
// Single entry function - executed once when called
static void sensingPressFeedback(uint8_t channel)
{
    sensingWaitFifoEmpty(channel); // wait until BOS1901 internal FIFO is empty before sending the waveform to make sure we can write 64 points.
    spiReadWriteReg(channel, 0x77E7);  // set SENSE = 0 to drive the output

    // fill FIFO with table values, wait if more than 64 points sent
	for(uint8_t i = 0; i < press_waveform_size; i++)
	{
        spiReadWriteReg(channel,press_waveform[i]);
        if((i+1) % 64 == 0) // after writing 64 points FIFO will be full
            sensingWaitFifoEmpty(channel); // wait until BOS1901 internal FIFO is empty before sending new points.

	}
    sensingWaitFifoEmpty(channel); // wait until waveform has completed before leaving the function.

    sensingNextState(channel); // to go next phase
}

// Phases D - Press Creep Stabilization
// Single entry function - executed once when called
static void sensingPressCreepStabilization(uint8_t channel)
{
    spiReadWriteReg(channel, REFERENCE_MINUS_1LSB);   // set FIFO to 0x0FFF
    timeWaitMs(1000*CREEP_HOLD_TIME/SAMPLING_RATE); // wait defined time

    sensingNextState(channel); // to go next phase
}

// Entering Phase E - Release Sensing Setup
// Single entry function - executed once when called
static void sensingReleaseSetup(uint8_t channel)
{
    spiReadWriteReg(channel, 0x7FE7);  // set SENSE = 1
    spiReadWriteReg(channel, 0x5697);  // Set BC = SENSE
    spiReadWriteReg(channel, REFERENCE_MINUS_1LSB);  // write 0x0FFF to set the bridge to negative polarity

    sensingNextState(channel);          // go to next phase
}

// Phase E - Release Sensing
// Multiple entry function - entered every time the timer expires
static void sensingRelease(uint8_t channel)
{
    int16_t vfeedback = spiReadWriteReg(channel, REFERENCE_MINUS_1LSB) & REG_READ_VFEEDBACK_MASK;  // Write 0x0FFF and read VFEEDBACK (use on read value)
    int16_t vsense = vfeedback - bos1901[channel].offset; // subtract the ADC offset value
    if(vsense >= RELEASE_THRESHOLD) // compare to threshold, increase counter value
    {
        bos1901[channel].counter++; // increase counter value to implement hold time check
        if(bos1901[channel].counter >= RELEASE_HOLD_TIME) { // detection successful
            bos1901[channel].counter = 0; // reset counter
            // ledExWrite(bos1901[channel].led, color_black);
            sensingNextState(channel);  // go to next phase
        }
    }
}

// Phase F - Release Feedback Waveform
// Single entry function - executed once when called
static void sensingReleaseFeedback(uint8_t channel)
{
    sensingWaitFifoEmpty(channel); // wait until BOS1901 internal FIFO is empty before sending the waveform to make sure we can write 64 points.
    spiReadWriteReg(channel, 0x77E7);  // set SENSE = 0 to drive the output

    // fill FIFO with table values, wait if more than 64 points sent
	for(uint8_t i = 0; i < release_waveform_size; i++)
	{
        spiReadWriteReg(channel,release_waveform[i]);
        if((i+1) % 64 == 0) // after writing 64 points
            sensingWaitFifoEmpty(channel); // wait until BOS1901 internal FIFO is empty before sending new points.
	}
    sensingWaitFifoEmpty(channel); // wait until waveform has completed before leaving the function.

    sensingNextState(channel); // to go next phase
}

// Phases G - Release Creep Stabilization
// Single entry function - executed once when called
static void sensingReleaseCreepStabilization(uint8_t channel)
{
    spiReadWriteReg(channel, REFERENCE_MINUS_1LSB);   // set FIFO to 0x0FFF
    timeWaitMs(1000*CREEP_HOLD_TIME/SAMPLING_RATE); // wait defined time

    sensingNextState(channel); // to go next phase
}

// Enter selected phass
// Multiple entry function - entered every time the timer expires
static void sensingEnterPhase(uint8_t channel)
{
    // check current state and execute associated function
    switch(bos1901[channel].state) {
        case SensingState_A_init:
            sensingInit(channel);
            break;
        case SensingState_B_press_setup:
            sensingPressSetup(channel);
            break;
        case SensingState_B_press:
            sensingPress(channel);
            break;
        case SensingState_C_press_feedback:
            sensingPressFeedback(channel);
            break;
        case SensingState_D_creep:
            sensingPressCreepStabilization(channel);
            break;
        case SensingState_E_release_setup:
            sensingReleaseSetup(channel);
            break;
        case SensingState_E_release:
            sensingRelease(channel);
            break;
        case SensingState_F_release_feedback:
            sensingReleaseFeedback(channel);
            break;
        case SensingState_G_creep:
            sensingReleaseCreepStabilization(channel);
            break;
        default:
            bos1901[channel].state = SensingState_A_init;
            sensingInit(channel);
            break;
    }
}


// Executing sensing
static void sensingExecuteSensing()
{
    // Enters every time the 8kHz timer expires
    if(timeIsTimerExpired())
    {
        timeResetTimerFlag(); // reset flag for time-based operations

        // for each channel
        for(uint8_t i = 0; i < NB_CHANNELS; i++)
        {
            sensingEnterPhase(i);
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
    sensingCalculateWaveforms();

    // Infinite loop
    for(;;)
    {
        sensingExecuteSensing();
    }
}



/*
 * Private Section
 */

#endif
