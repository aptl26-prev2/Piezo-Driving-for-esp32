//
// Description: advSensing Example
//
// Copyright (c) 2021 Boréas Technologies Inc. All rights reserved.
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
#include "functions.h"

#ifdef DRIVING_TEST 

#include <stdint.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include "../components/rapidjson/include/rapidjson/document.h"
#include "spi.h"
#include "math.h"
#include "utils.h"
#include "ledEx.h"
#include "timeEx.h"
#include <math.h>

// #define Button_Press


/********************************************************
*						DEFINES
********************************************************/

uint16_t frequency;
WaveformType waveform;

#define PI 3.14159265
//Channels
#define BOS1901_CHANNEL_A   (0)
#define BOS1901_CHANNEL_B   (1)
#define NB_CHANNELS (2)

// Application
#define SENSING_SAMPLING_RATE		(ADVSENSING_SAMPLING_PERIOD)
// #define SIG_SIZE_MAX             	(1024) // Maximum waveform table size
#define SIG_SIZE_MAX             	(1024 * 4) // Maximum waveform table size
#define DATA_HANDLER_SLOPE_MAX_WINDOW_US  (6250) // us, Slope averaging window duration
#define DATA_HANDLER_SLOPE_MAX_WINDOW_SIZE  (DATA_HANDLER_SLOPE_MAX_WINDOW_US * SENSING_SAMPLING_RATE / 1000000) // Cycles, Slope averaging window size
#define DATA_HANDLER_SLOPE_DELTATIME_US      (1000000/SENSING_SAMPLING_RATE) // us, time between slope values
#define VFEEDBACK_AVERAGE_SAMPLING 	(10) // number of values averaged when capturing VFEEDBACK

// Press feedback waveform
#define PRESS_SIG_VOLTAGE_MAX       (60.0) // V (bipolar amplitude)
#define PRESS_SIG_VOLTAGE_MIN       (-10.0f) // V (bipolar amplitude)
#define PRESS_SIG_FREQ              (frequency) // Hz
#define PRESS_SIG_CYCLE             (1) // warning : SIG_SIZE_MAX might need to be increased
#define WAVEFORM                    (waveform) //    SINE, SQUARE, SAWTOOTH, TRIANGLE

// Release feedback waveform
#define RELEASE_SIG_VOLTAGE_MAX     (0.75f*PRESS_SIG_VOLTAGE_MAX)  // V (bipolar amplitude)
#define RELEASE_SIG_VOLTAGE_MIN     (PRESS_SIG_VOLTAGE_MIN)  // V (bipolar amplitude)
#define RELEASE_SIG_FREQ            (PRESS_SIG_FREQ) // Hz
#define RELEASE_SIG_CYCLE           (1) // warning : SIG_SIZE_MAX might need to be increased

// Press stabiliation waveform (negative sine)
#define PRESS_CREEP_STABILISATION_MS			(2) // MS, duration
#define PRESS_CREEP_STABILISATION_FREQ			(1000/PRESS_CREEP_STABILISATION_MS) // Hz
#define PRESS_CREEP_STABILISATION_MIN			(-5) // V, amplitude

// Release stabilization (negative sine)
#define RELEASE_CREEP_STABILISATION_MS			(2) // MS, duration
#define RELEASE_CREEP_STABILISATION_FREQ		(1000/RELEASE_CREEP_STABILISATION_MS) // Hz
#define RELEASE_CREEP_STABILISATION_MIN			(-10) // V, amplitude

// Press sensing parameters : detection successful if : (value1 AND slode) OR value2
//// value1 : value threshold detection
#define PRESS_DETECTION_VALUE1_ENABLED 		(true)
#define PRESS_DETECTION_VALUE1_THRESHOLD 	(0.2f) // V
#define PRESS_DETECTION_VALUE1_HOLDTIME_US 	(0) // us
#define PRESS_DETECTION_VALUE1_HOLDTIME 	(PRESS_DETECTION_VALUE1_HOLDTIME_US * SENSING_SAMPLING_RATE / 1000000) // cycles
//// slope : slope threshold detection
#define PRESS_DETECTION_SLOPE_ENABLED 		(false)
#define PRESS_DETECTION_SLOPE_THRESHOLD 	(10000) // uV/ms
#define PRESS_DETECTION_SLOPE_HOLDTIME_US   (10000) // us
#define PRESS_DETECTION_SLOPE_HOLDTIME      (PRESS_DETECTION_SLOPE_HOLDTIME_US * SENSING_SAMPLING_RATE / 1000000) // cycles
#define PRESS_DETECTION_SLOPE_MAX_WINDOW_US (DATA_HANDLER_SLOPE_MAX_WINDOW_US) // us, window time
#define PRESS_DETECTION_SLOPE_WINDOW_SIZE (PRESS_DETECTION_SLOPE_MAX_WINDOW_US * SENSING_SAMPLING_RATE / 1000000) // cycles
//// value2 : value threshold detection
#define PRESS_DETECTION_VALUE2_ENABLED 		(false)
#define PRESS_DETECTION_VALUE2_THRESHOLD 	(0)
#define PRESS_DETECTION_VALUE2_HOLDTIME_US 	(0) // us
#define PRESS_DETECTION_VALUE2_HOLDTIME 	(PRESS_DETECTION_VALUE2_HOLDTIME_US * SENSING_SAMPLING_RATE / 1000000) // cycles

// Release sensing parameters : detection successful if : (value1 AND slode) OR value2
//// value1 : value threshold detection
#define RELEASE_DETECTION_VALUE1_ENABLED    (false)
#define RELEASE_DETECTION_VALUE1_THRESHOLD 	(0.25f) // V
#define RELEASE_DETECTION_VALUE1_HOLDTIME_US 	(0) // us
#define RELEASE_DETECTION_VALUE1_HOLDTIME 	(RELEASE_DETECTION_VALUE1_HOLDTIME_US * SENSING_SAMPLING_RATE / 1000000) // cycles
//// slope : slope threshold detection
#define RELEASE_DETECTION_SLOPE_ENABLED 	(true)
#define RELEASE_DETECTION_SLOPE_THRESHOLD 	(1000) // uV/ms
#define RELEASE_DETECTION_SLOPE_HOLDTIME_US (8000) // us
#define RELEASE_DETECTION_SLOPE_HOLDTIME    (RELEASE_DETECTION_SLOPE_HOLDTIME_US * SENSING_SAMPLING_RATE / 1000000) // cycles
#define RELEASE_DETECTION_SLOPE_MAX_WINDOW_US (DATA_HANDLER_SLOPE_MAX_WINDOW_US) // us, window time
#define RELEASE_DETECTION_SLOPE_WINDOW_SIZE (RELEASE_DETECTION_SLOPE_MAX_WINDOW_US * SENSING_SAMPLING_RATE / 1000000) // cycles
//// value2 : value threshold detection
#define RELEASE_DETECTION_VALUE2_ENABLED 	(true)
#define RELEASE_DETECTION_VALUE2_THRESHOLD 	(0.109f*1.5)
#define RELEASE_DETECTION_VALUE2_HOLDTIME_US 	(125) // us
#define RELEASE_DETECTION_VALUE2_HOLDTIME 	(RELEASE_DETECTION_VALUE2_HOLDTIME_US * SENSING_SAMPLING_RATE / 1000000) // cycles

// Piezo actuator specifics
#define PIEZO_RELAXATION_TIME_INIT_MS       (600) // ms, time between first enabling the output and measuring the OFFSET
#define PIEZO_RELAXATION_TIME_SENSING_SETUP_MS  (20) // ms, time between enabling sensing and starting to capture VFEEDBACK
// #define PIEZO_RELAXATION_TIME_SENSING_SETUP_MS  (1000) // ms, time between enabling sensing and starting to capture VFEEDBACK

// Useful values
#define REFERENCE_PLUS_1LSB					(0x0001)
#define REFERENCE_MINUS_1LSB				(0x0FFF)
#define SENSING_PRESS_DETECT_VAL	    (REFERENCE_PLUS_1LSB) // REFERENCE CODE
#define SENSING_RELEASE_DETECT_VAL	    (REFERENCE_MINUS_1LSB) // REFERENCE CODE
#define REG_READ_VFEEDBACK_MASK			(0x03FF) // 10-bits
#define REFERENCE_ZERO							(0x0000) // REFERENCE CODE

// Configuration bits
#define SUP_RISE_SENSE_BIT_ON  (0x1 << 11)
#define MAX_FIFO_SPACE		(64)


/********************************************************
*						STRUCTURES
********************************************************/

// typedef enum {
//     SINE,
//     SQUARE,
//     SAWTOOTH,
//     TRIANGLE
// } WaveformType;

// Sensing Phases
typedef enum
{
    SensingState_A_init,
    SensingState_B_press_setup,
    SensingState_B_press_sensing,
    SensingState_C_press_feedback,
    SensingState_D_press_creep_stab,
    SensingState_E_release_setup,
    SensingState_E_release_sensing,
    SensingState_F_release_feedback,
    SensingState_G_release_creep_stab
} SensingState;

// slope data structure - can be reset
typedef struct
{
    uint8_t historyIndex;
    int32_t slopeHistory[DATA_HANDLER_SLOPE_MAX_WINDOW_SIZE]; //Values in microV/ms
    int32_t prevDataIntMicroVolt;
    uint32_t totalDeltaTimeUs;
    bool windowIsFull;
    bool prevDataInit;
    uint64_t lastDataTimestamp;
} SlopeActiveData;

// Slope detection structure
typedef struct
{
    bool isEnabled;
    bool isSuccessful;
    int32_t slopeThreshold; // uV/ms
    SlopeActiveData activeData;
    uint8_t windowSize;
    uint16_t counter;
    uint16_t holdTime;
} SlopeSensingState;

// Value detection structure
typedef struct
{
    bool isEnabled;
    bool isSuccessful;
    float valueThreshold; // V
    float valueVal; // V
    uint16_t counter;
    uint16_t holdTime;
} ValueSensingState;

// Voltage reading structure - voltage is read once and used by all detectors
typedef struct
{
    bool newValueReady;
	int16_t offset;         // ADC offset for sensing
	int16_t vfeedback;			 // ADC vfeedback value for sensing
    float voltageValue; // sensed voltage.
} VoltageReadState;

// Container for sensing parameters & waveform - one per channel
typedef struct {
	// state
    SensingState state;     // current sensing state
	// sensed voltage
	VoltageReadState	voltageReadState; // sensed voltage
    // sensing structures
	ValueSensingState pressValueSense1; // Value threshold sensing structure
	SlopeSensingState pressSlopeSense; // Slope detection sensing structure
	ValueSensingState pressValueSense2; // Value threshold sensing structure
	ValueSensingState releaseValueSense1; // Value threshold sensing structure
	SlopeSensingState releaseSlopeSense; // Slope detection sensing structure
	ValueSensingState releaseValueSense2; // Value threshold sensing structure
	// feedback waveforms
	uint16_t press_waveform[SIG_SIZE_MAX];   // Press feedback waveform data points
	uint16_t press_waveform_size;           // Press feedback waveform number of data points
	uint16_t press_stab_waveform[SIG_SIZE_MAX];   // Press stabilization waveform data points
	uint16_t press_stab_waveform_size;           // Press stabilization waveform number of data points
	uint16_t release_waveform[SIG_SIZE_MAX]; // Release feedback waveform data points
	uint16_t release_waveform_size;         // Release feedback waveform number of data points
	uint16_t release_stab_waveform[SIG_SIZE_MAX]; // Release stabilization waveform data points
	uint16_t release_stab_waveform_size;         // Release stabilization waveform number of data points
	uint16_t index; 	// sample index of waveform being played
	uint64_t relaxTimeStartUs; // start time mark of relaxation before sensing
	// led
    uint8_t led;		// associated LED
} Bos1901;


/********************************************************
*						VARIABLES
********************************************************/

// bos1901 initialization values
Bos1901 bos1901[NB_CHANNELS] = {
	{
		.state = SensingState_A_init,
		.press_waveform_size = 0,
		.release_waveform_size = 0,
		.relaxTimeStartUs = 0,
		.led = LEDEX_CHA
	},{
		.state = SensingState_A_init,
		.press_waveform_size = 0,
		.release_waveform_size = 0,
		.relaxTimeStartUs = 0,
		.led = LEDEX_CHB
	}
};
// static Bos1901 bos1901[NB_CHANNELS] = {
// 	{
// 		.state = SensingState_A_init,
// 		.press_waveform_size = 0,
// 		.release_waveform_size = 0,
// 		.relaxTimeStartUs = 0,
// 		.led = LEDEX_CHA
// 	}
// };

/*
 * Private Section
 */

/********************************************************
*				 FUNCTIONS DECLARATIONS
********************************************************/


extern size_t waveArrSize;
extern float* waveArr;
extern double* press_waveform;
extern void parse();

bool check = false;
bool sense = false;
bool press = false;
bool release = false;
uint8_t fingerSensing;
uint8_t fingersDriving[5] = {0, 0, 0, 0, 0};

static int advSensingBos1901_DacHsIncrement(uint8_t channel, uint8_t dachsInc);
static int advSensingBos1901_Register_Init(uint8_t channel);
static int16_t advSensingVolt2Amplitude(float volt);
static float advSensingVfeedback2Volt(int16_t vfeedback);
static void advSensingCalculateWaveforms(uint8_t channel);
static bool advSensingPlayWaveformBlocking(uint8_t channel, uint16_t* waveform, uint16_t size);
static bool advSensingPlayWaveformNonBlocking(uint8_t channel, uint16_t* waveform, uint16_t size);
static void advSensingWaitFifoEmpty(uint8_t channel);
static uint8_t advSensingGetFifoSpace(uint8_t channel);
static void advSensingNextState(uint8_t channel);
static void advSensingInit(uint8_t channel);
static void advSensingPressSetup(uint8_t channel);
static void advSensingPress(uint8_t channel);
static void advSensingPressFeedback(uint8_t channel);
static void advSensingPressCreepStabilization(uint8_t channel);
static void advSensingReleaseSetup(uint8_t channel);
static void advSensingRelease(uint8_t channel);
static void advSensingReleaseFeedback(uint8_t channel);
static void advSensingReleaseCreepStabilization(uint8_t channel);
static void advSensingEnterPhase(uint8_t channel);
static void advSensingExexcuteSensing();
static void advSensingSlopeDetectionReset(SlopeSensingState *ptr);
static void advSensingValueDetectionReset(ValueSensingState *ptr);
static void advSensingGetSensingOffset(uint8_t channel);
static void advSensingGetSensingVoltage(uint8_t channel);
static void advSensingSlopeDetection(SlopeSensingState *ptr, VoltageReadState *ptrVoltageReadState);
static void advSensingValueDetection(ValueSensingState *ptr, VoltageReadState *ptrVoltageReadState);
static bool advSensingEvalDetection(ValueSensingState *valueSense1, SlopeSensingState *slopeSense, ValueSensingState *valueSense2, VoltageReadState *ptrVoltageReadState);
static void advSensingConfigureParameters(uint8_t channel);
static void advSensingReset(uint8_t channel);


/********************************************************
*				 FUNCTIONS DEFINTION
********************************************************/

/////////////////////////////////////////////////////////
//              SUPPORT FUNCTIONS
/////////////////////////////////////////////////////////

static int advSensingBos1901_DacHsIncrement(uint8_t channel, uint8_t dachsInc)
{
	int retval = 0;
	uint16_t dacVal = 0,dachsVal;
	uint16_t wReg = 0,rReg = 0;

    wReg = 0x5 << 12 | 0x8 << 7 | 0x7;
    spiReadWriteReg(channel, wReg);
    rReg = spiReadWriteReg(channel, wReg);

    dacVal = rReg & 0x0FFF;
	dachsVal = (dacVal & 0x0fc0) >> 6;

    if(dachsVal > 31 || dachsVal < (32-dachsInc)) // if above max, change to set to max value.
    {
        dachsVal += dachsInc;
        if(dachsVal > 63)
            dachsVal = dachsVal & 0x1F;
    }
    else // above max, set to max value.
		{
			dachsVal = 31;
			retval = -1;
		}
        dacVal = (dacVal & 0x003f) + (dachsVal << 6);

    wReg = 0x8000 | dacVal;
    spiReadWriteReg(channel, wReg);
    timeWaitUs(10);

    wReg = 0x663A;
    rReg = spiReadWriteReg(channel, wReg);
	timeWaitUs(10);

	return retval;
}

static int advSensingBos1901_Register_Init(uint8_t channel)
{
    int retval;

    // software reset
    spiReadWriteReg(channel, 0x5427);
    // SENSE = 1
    spiReadWriteReg(channel, 0x77E7 | SUP_RISE_SENSE_BIT_ON);
    timeWaitUs(10);
    // enable output, launched calibration, wait end of calibration
    spiReadWriteReg(channel, 0x5417);
    timeWaitMs(2);
    // disable output
    spiReadWriteReg(channel, 0x5407);
    timeWaitUs(10);

    retval = advSensingBos1901_DacHsIncrement(channel, 0); // +10 -- increase value if using RC filter

    return retval;
}

// Convert value in volts to Amplitude FIFO code
static int16_t advSensingVolt2Amplitude(float volt)
{
    // printf("volt: %f\n", volt);
    int16_t amplitude = volt*2047/3.6/31;

    return amplitude & 0x0FFF;
}

// Convert sensed value to volts
static float advSensingVfeedback2Volt(int16_t vfeedback)
{
    float volt = (float)vfeedback * 3.6 * 31 / 1023;

    return volt;
}

// Elementary waveform calculation function

static void advSensingCalculateWaveform(uint16_t* table, uint16_t* size, float vMax, float vMin, uint16_t freq, uint8_t cycles, WaveformType waveformType)
{
    if (sense) {
        freq = 500;
        float amplitude = (vMax - vMin)/2;
        float offset = (vMax + vMin)/2;
        uint16_t samplingRateHz = PLAY_SAMPLING_RATE;
        uint16_t nbrOfSamplePerCycle = round(samplingRateHz / (float) freq);
        // uint16_t nbrOfSamplePerCycle = 1;
        double theta0 = 2 * M_PI / nbrOfSamplePerCycle;
        float phaseShift;
        uint16_t endVal;
        
        // calculate phase
        if (vMin >= 0)
        {
            phaseShift = -M_PI;
            endVal = REFERENCE_MINUS_1LSB;
        }
        else if (vMax <= 0)
        {
            phaseShift = 0;
            endVal = REFERENCE_PLUS_1LSB;
        }
        else
        {
            phaseShift = -M_PI - acosf(fabsf(offset) / amplitude);
            endVal = fabsf(vMax) > fabsf(vMin) ? REFERENCE_MINUS_1LSB : REFERENCE_PLUS_1LSB;
        }

        *size = nbrOfSamplePerCycle * cycles;
        for(uint16_t i = 0; i < *size; i++)
        {
            table[i] = advSensingVolt2Amplitude( (vMax - vMin) / 2 * cos((double)(theta0*i + phaseShift)) + (vMax + vMin)/2 );
        }
        // ending value
        (*size)++;
        table[(*size)-1] = endVal;
    }

    else {
        float amplitude = (vMax - vMin)/2;
        float offset = (vMax + vMin)/2;
        // uint16_t samplingRateHz = PLAY_SAMPLING_RATE ;
        uint16_t samplingRateHz = 500;
        
        uint16_t nbrOfSamplePerCycle = round(samplingRateHz / (float) freq);
        // uint16_t nbrOfSamplePerCycle = 1;
        double theta0 = 2 * M_PI / nbrOfSamplePerCycle;
        float phaseShift;
        uint16_t endVal;
        
        // calculate phase
        if (vMin >= 0)
        {
            phaseShift = -M_PI;
            endVal = REFERENCE_MINUS_1LSB;
        }
        else if (vMax <= 0)
        {
            phaseShift = 0;
            endVal = REFERENCE_PLUS_1LSB;
        }
        else
        {
            phaseShift = -M_PI - acosf(fabsf(offset) / amplitude);
            endVal = fabsf(vMax) > fabsf(vMin) ? REFERENCE_MINUS_1LSB : REFERENCE_PLUS_1LSB;
        }

        *size = nbrOfSamplePerCycle * cycles;

        for(uint16_t i = 0; i < *size; i++)
        {
            // table[i] = advSensingVolt2Amplitude( (vMax - vMin) / 2 * 1 + (vMax + vMin)/2 );
            // printf("table[%u]: %u\n", i, (uint16_t) ((vMax - vMin) / 2 * cos((double)(theta0*i + phaseShift)) + (vMax + vMin)/2 ));
            double angle = (double)(theta0*i + phaseShift);
            switch (waveformType) {
                case SINE:
                    table[i] = advSensingVolt2Amplitude((vMax - vMin) / 2 * cos(angle) + (vMax + vMin)/2 );
                    break;
                case SQUARE:
                    table[i] = advSensingVolt2Amplitude((vMax - vMin) / 2 * (fmod(angle, 2 * PI) < PI ? 1 : -1) + (vMax + vMin)/2 );
                    break;
                case SAWTOOTH:
                    table[i] = advSensingVolt2Amplitude((vMax - vMin) / 2 * (fmod(angle, 2 * PI) / (2 * PI) * 2 - 1) + (vMax + vMin)/2 );
                    break;
                case TRIANGLE:
                    table[i] = advSensingVolt2Amplitude((vMax - vMin) / 2 * (4 * fabs(fmod(angle, 2 * PI) / (2 * PI) - 0.5) - 1) + (vMax + vMin)/2 );
                    break;
                default:
                    table[i] = advSensingVolt2Amplitude((vMax - vMin) / 2 * cos(angle) + (vMax + vMin)/2 );
                    break;
            }
        }

        // ending value
        (*size)++;
        table[(*size)-1] = endVal;
    }
}

// Calculate Press and Release Feedback Waveforms
static void advSensingCalculateWaveforms(uint8_t channel)
{
    // parse();

    // ******* Press Feedback Waveform : edge-smoothed sine *******
    // printf("Start of press waveform\n");
    advSensingCalculateWaveform(bos1901[channel].press_waveform, &bos1901[channel].press_waveform_size, PRESS_SIG_VOLTAGE_MAX, PRESS_SIG_VOLTAGE_MIN, PRESS_SIG_FREQ, PRESS_SIG_CYCLE, WAVEFORM);
    // printf("end of press waveform\n");
    // printf("table first: %u", bos1901[channel].press_waveform[0]);

    // ******* Press Stabilization Waveform : negative sine *******
    // printf("Start of press stabalization waveform\n");
    advSensingCalculateWaveform(bos1901[channel].press_stab_waveform, &bos1901[channel].press_stab_waveform_size, 0, PRESS_CREEP_STABILISATION_MIN, PRESS_CREEP_STABILISATION_FREQ, 1, SINE);
    // printf("End of press stabalization waveform\n");
    // ******* Release Feedback Waveform : edge-smoothed sine *******
    // printf("Start of Release  waveform\n");
    advSensingCalculateWaveform(bos1901[channel].release_waveform, &bos1901[channel].release_waveform_size, RELEASE_SIG_VOLTAGE_MAX, RELEASE_SIG_VOLTAGE_MIN, RELEASE_SIG_FREQ, RELEASE_SIG_CYCLE, WAVEFORM);
    // printf("end of release waveform\n");
    // ******* Release Stabilization Waveform : negative sine *******
    // printf("Start of release stabalization waveform\n");
    advSensingCalculateWaveform(bos1901[channel].release_stab_waveform, &bos1901[channel].release_stab_waveform_size, 0, RELEASE_CREEP_STABILISATION_MIN, RELEASE_CREEP_STABILISATION_FREQ, 1, SINE);
    // printf("End of release stabalization waveform\n");
}

static bool advSensingPlayWaveformBlocking(uint8_t channel, uint16_t* waveform, uint16_t size)
{
    advSensingWaitFifoEmpty(channel); // wait until BOS1901 internal FIFO is empty before sending the waveform to make sure we can write 64 points.
    spiReadWriteReg(channel, 0x77E7);  // set SENSE = 0 to drive the output

    // fill FIFO with table values, wait if more than 64 points sent
    for(uint8_t i = 0; i < size; i++)
    {
        spiReadWriteReg(channel, waveform[i]);
        if((i+1) % 64 == 0) // after writing 64 points FIFO will be full
            advSensingWaitFifoEmpty(channel); // wait until BOS1901 internal FIFO is empty before sending new points.
    }
    advSensingWaitFifoEmpty(channel); // wait until waveform has completed before leaving the function.

    return true;
}

static bool advSensingPlayWaveformNonBlocking(uint8_t channel, uint16_t* waveform, uint16_t size)
{
	bool res = false;

	// first entry
	if(bos1901[channel].index == 0)
	{
	    advSensingWaitFifoEmpty(channel); // wait until BOS1901 internal FIFO is empty before sending the waveform to make sure we can write 64 points.
	    spiReadWriteReg(channel, 0x77E7);  // set SENSE = 0 to drive the output
	}

    // fill FIFO with table values, wait if more than 64 points sent
	uint16_t fifospace = advSensingGetFifoSpace(channel);

    // waveform all programmed
    if(bos1901[channel].index == size)
    {
    	// waveform finished playing
    	if(fifospace == MAX_FIFO_SPACE)
    	{
            bos1901[channel].index = 0;
            res = true;
    	}
    }
    else
    {
    	uint16_t sendSize = fifospace <= (size - bos1901[channel].index) ? fifospace : (size - bos1901[channel].index);

    	for(int8_t i = 0; i < sendSize; i++)
    	{
        	spiReadWriteReg(channel, waveform[bos1901[channel].index]);
        	bos1901[channel].index++;
    	}
    }

    return res;
}

// Wait until BOS1901 internal FIFO is empty
static void advSensingWaitFifoEmpty(uint8_t channel)
{
    bool fifoempty = 0;
    uint16_t wReg = 0;

    //Set up broadcast to read IC_STATUS
    wReg = 0x5617;
    spiReadWriteReg(channel, wReg);  // Set BC = IC_STATUS

    // loop until FIFO is empty
    while(!fifoempty)
    {
        timeWaitUs(10);
        wReg = 0xC000;
        uint16_t ic_status_reg = spiReadWriteReg(channel, wReg); // dummy write, get IC_STATUS value
        fifoempty = (ic_status_reg >> 6) & 0x1; // extract EMPTY value.
    }
}

static uint8_t advSensingGetFifoSpace(uint8_t channel)
{
    uint8_t fifospace = 0;
    uint16_t wReg = 0;

    //Set up broadcast to read IC_STATUS
    wReg = 0x5617;
    spiReadWriteReg(channel, wReg);  // Set BC = IC_STATUS
	timeWaitUs(10);
	wReg = 0xC000;
	uint16_t ic_status_reg = spiReadWriteReg(channel, wReg); // dummy write, get IC_STATUS value
	fifospace = ic_status_reg & 0x7F; // extract EMPTY & FIFO_SPACE value.

    return fifospace;
}

// Change to next sensing phase
static void advSensingNextState(uint8_t channel)
{
    // Check current sensing state
    switch(bos1901[channel].state)
    {
        case SensingState_A_init:
            bos1901[channel].state = SensingState_B_press_setup;
            break;
        case SensingState_B_press_setup:
            bos1901[channel].state = SensingState_B_press_sensing;
            break;
        case SensingState_B_press_sensing:
            bos1901[channel].state = SensingState_C_press_feedback;
            break;
        case SensingState_C_press_feedback:
            bos1901[channel].state = SensingState_D_press_creep_stab;
            break;
        case SensingState_D_press_creep_stab:
            bos1901[channel].state = SensingState_E_release_setup;
            check = true;
            break;
        case SensingState_E_release_setup:
            bos1901[channel].state = SensingState_E_release_sensing;
            break;
        case SensingState_E_release_sensing:
            bos1901[channel].state = SensingState_F_release_feedback;
            break;
        case SensingState_F_release_feedback:
            bos1901[channel].state = SensingState_G_release_creep_stab;
            break;
        case SensingState_G_release_creep_stab:
            bos1901[channel].state = SensingState_B_press_setup;
            check = true;
            break;
        default:
            bos1901[channel].state = SensingState_A_init;
            break;
    }
}


/////////////////////////////////////////////////////////
//            SENSING PHASES FUNCTIONS
/////////////////////////////////////////////////////////

// Phase A - Sensing Initialization
// Single entry function - executed once when called
static void advSensingInit(uint8_t channel)
{
    // ledExWrite(bos1901[channel].led, color_red); // show error.

    advSensingBos1901_Register_Init(channel);
    advSensingGetSensingOffset(channel);
    advSensingConfigureParameters(channel);
    advSensingCalculateWaveforms(channel);

    // LED STATE
    // ledExWrite(bos1901[channel].led, color_black);

    advSensingNextState(channel);          // to go next phase
}

// Entering Phase B - Press Sensing Setup
// Single entry function - executed once when called
static void advSensingPressSetup(uint8_t channel)
{
    advSensingReset(channel);
    spiReadWriteReg(channel, 0x77E7 | SUP_RISE_SENSE_BIT_ON);  // set SENSE = 1
    spiReadWriteReg(channel, 0x5697);  // Set BC = SENSE
    spiReadWriteReg(channel, SENSING_PRESS_DETECT_VAL);  // write 0x0001 to set the bridge to positive polarity

    advSensingNextState(channel);          // go to next phase
}

// Phase B - Press Sensing
// Multiple entry function - entered every time the timer expires
static void advSensingPress(uint8_t channel)
{
    advSensingGetSensingVoltage(channel);

    // evaluate sensing mechanisms
    advSensingValueDetection(&bos1901[channel].pressValueSense1, &bos1901[channel].voltageReadState);
    advSensingSlopeDetection(&bos1901[channel].pressSlopeSense, &bos1901[channel].voltageReadState);
    advSensingValueDetection(&bos1901[channel].pressValueSense2, &bos1901[channel].voltageReadState);
    // evaluate combined result
    bool sensingResult = advSensingEvalDetection(&bos1901[channel].pressValueSense1, &bos1901[channel].pressSlopeSense, &bos1901[channel].pressValueSense2, &bos1901[channel].voltageReadState);

    if (sense) {

        if(sensingResult)
        {
            // printf("\n\n\n\n\n\n\n\nsensing press\n\n\n\n\n\n\n");
            // LED STATE
            // ledExWrite(bos1901[channel].led, color_green);
            advSensingNextState(channel);  // go to next phase
            press = true;
            fingerSensing = channel;
        }
        else {
            check = true;
        }
    }

    else {
        advSensingNextState(channel);  
    }
}

// Phase C - Press Feedback Waveform
// Single entry function - executed once when called
static void advSensingPressFeedback(uint8_t channel)
{
	if(advSensingPlayWaveformNonBlocking(channel, bos1901[channel].press_waveform, bos1901[channel].press_waveform_size))
		advSensingNextState(channel); // to go next phase
}

// Phases D - Press Creep Stabilization
// Single entry function - executed once when called
static void advSensingPressCreepStabilization(uint8_t channel)
{ 
    // printf("\n\n\n\n inside stabilize \n\n\n");
	// first entry - play waveform
	if(bos1901[channel].relaxTimeStartUs == 0)
	{
		// waveform done
		if(advSensingPlayWaveformNonBlocking(channel, bos1901[channel].press_stab_waveform, bos1901[channel].press_stab_waveform_size))
		{
		    // disable then enable output (avoid zero-crossing potential issue)
		    spiReadWriteReg(channel, 0x5687); // disable output
		    spiReadWriteReg(channel, 0x77E7 | SUP_RISE_SENSE_BIT_ON); // SENSE = 1,VDD = 11111,TI_RISE = 0x27
		    spiReadWriteReg(channel, SENSING_RELEASE_DETECT_VAL);  // write 0x0001 to set the bridge to positive polarity
		    spiReadWriteReg(channel, 0x5697); // enable output

		    bos1901[channel].relaxTimeStartUs = timeGetUsCounter();
		}
	}
	// wait relaxation time
	else
	{
		if(timeGetUsCounter() > bos1901[channel].relaxTimeStartUs + PIEZO_RELAXATION_TIME_SENSING_SETUP_MS*1000)
		{
			bos1901[channel].relaxTimeStartUs = 0;
			advSensingNextState(channel); // to go next phase
		}
	}
}

// Entering Phase E - Release Sensing Setup
// Single entry function - executed once when called
static void advSensingReleaseSetup(uint8_t channel)
{
    // printf("\n\n\n\ninside release setup\n\n\n\n");
    advSensingReset(channel);
    spiReadWriteReg(channel, 0x77E7 | SUP_RISE_SENSE_BIT_ON);  // set SENSE = 1
    spiReadWriteReg(channel, 0x5697);  // Set BC = SENSE
    spiReadWriteReg(channel, SENSING_RELEASE_DETECT_VAL);  // write 0x0001 to set the bridge to positive polarity

    advSensingNextState(channel);          // go to next phase
}

// Phase E - Release Sensing
// Multiple entry function - entered every time the timer expires
static void advSensingRelease(uint8_t channel)
{
    // printf("\n\n\n\ninside release sensing\n\n\n\n");
    advSensingGetSensingVoltage(channel);

    // evaluate sensing mechanisms
    advSensingValueDetection(&bos1901[channel].releaseValueSense1, &bos1901[channel].voltageReadState);
    advSensingSlopeDetection(&bos1901[channel].releaseSlopeSense, &bos1901[channel].voltageReadState);
    advSensingValueDetection(&bos1901[channel].releaseValueSense2, &bos1901[channel].voltageReadState);
    // evaluate combined result
    bool sensingResult = advSensingEvalDetection(&bos1901[channel].releaseValueSense1, &bos1901[channel].releaseSlopeSense, &bos1901[channel].releaseValueSense2, &bos1901[channel].voltageReadState);

    if (sense) {
        if(sensingResult) {
            // printf("\n\n\n\n\n\n\n\nsensing release\n\n\n\n\n\n\n");
            // LED STATE
            // ledExWrite(bos1901[channel].led, color_black);
            advSensingNextState(channel);  // go to next phase
            release = true;
            fingerSensing = channel;
        }
        else {
            check = true;
        }

    }

    else {
        advSensingNextState(channel);     
    }


}

// Phase F - Release Feedback Waveform
// Single entry function - executed once when called
static void advSensingReleaseFeedback(uint8_t channel)
{
	if(advSensingPlayWaveformNonBlocking(channel, bos1901[channel].release_waveform, bos1901[channel].release_waveform_size))
		advSensingNextState(channel); // to go next phase
}

// Phases G - Release Creep Stabilization
// Single entry function - executed once when called
static void advSensingReleaseCreepStabilization(uint8_t channel)
{
	// first entry - play waveform
	if(bos1901[channel].relaxTimeStartUs == 0)
	{
		// waveform done
		if(advSensingPlayWaveformNonBlocking(channel, bos1901[channel].release_stab_waveform, bos1901[channel].release_stab_waveform_size))
		{
		    // disable then enable output (avoid zero-crossing issue)
		    spiReadWriteReg(channel, 0x5687); // disable output
		    spiReadWriteReg(channel, 0x77E7 | SUP_RISE_SENSE_BIT_ON); // SENSE = 1,VDD = 11111,TI_RISE = 0x27
		    spiReadWriteReg(channel, SENSING_PRESS_DETECT_VAL);  // write 0x0001 to set the bridge to positive polarity
		    spiReadWriteReg(channel, 0x5697); // enable output

		    bos1901[channel].relaxTimeStartUs = timeGetUsCounter();
		}
	}
	// wait relaxation time
	else
	{
		if(timeGetUsCounter() > bos1901[channel].relaxTimeStartUs + PIEZO_RELAXATION_TIME_SENSING_SETUP_MS*1000)
		{
			bos1901[channel].relaxTimeStartUs = 0;
			advSensingNextState(channel); // to go next phase
		}
	}
}

// Enter selected phase
// Multiple entry function - entered every time the timer expires
static void advSensingEnterPhase(uint8_t channel)
{
    // check current state and execute associated function
    switch(bos1901[channel].state) {
        case SensingState_A_init:
            advSensingInit(channel);
            break;
        case SensingState_B_press_setup:
            advSensingPressSetup(channel);
            break;
        case SensingState_B_press_sensing:
            advSensingPress(channel);
            break;
        case SensingState_C_press_feedback:
            advSensingPressFeedback(channel);
            break;
        case SensingState_D_press_creep_stab:
            advSensingPressCreepStabilization(channel);
            break;
        case SensingState_E_release_setup:
            advSensingReleaseSetup(channel);
            break;
        case SensingState_E_release_sensing:
            advSensingRelease(channel);
            break;
        case SensingState_F_release_feedback:
            advSensingReleaseFeedback(channel);
            break;
        case SensingState_G_release_creep_stab:
            advSensingReleaseCreepStabilization(channel);
            break;
        default:
            bos1901[channel].state = SensingState_A_init;
            advSensingInit(channel);
            break;
    }
}


// Executing sensing
void advSensingExecuteSensing()
{
    // Enters every time the 1kHz timer expires
    if(timeIsTimerExpired())
    {
    	timeResetTimerFlag(); // reset flag for time-based operations

        // original code
        // for each channel
        // for(uint8_t i = 0; i < NB_CHANNELS; i++)
        // {
        //     advSensingEnterPhase(i);
        // }

        // // Code modified to allow only some fingers to vibrate
        for(uint8_t i = 0; i < sizeof(fingersDriving); i++)
        {
            if (fingersDriving[i] == 1)
            {
                advSensingEnterPhase(i);
            }
        }
    }
}


static void advSensingSlopeDetectionReset(SlopeSensingState *ptrSensingState)
{
    ptrSensingState->isSuccessful = false;
    memset(&ptrSensingState->activeData, 0, sizeof(SlopeActiveData));
    ptrSensingState->counter = 0;
}


static void advSensingValueDetectionReset(ValueSensingState *ptrSensingState)
{
    ptrSensingState->isSuccessful = false;
    ptrSensingState->counter = 0;
    ptrSensingState->valueVal = 0;
}

static void advSensingGetSensingOffset(uint8_t channel)
{
    // Get ADC offset value with positive polarity
    spiReadWriteReg(channel, 0x7 << 12 | SUP_RISE_SENSE_BIT_ON | 0x1F << 6 | 0x27); // Set SENSE = 1 & VDD = 31 (5V supply), TI_RISE = default
    spiReadWriteReg(channel, 0x5 << 12 | 0xD << 7 | 0x1 << 4 | 0x7);  // Set OE = 1, BC = read VFEEDBACK
    spiReadWriteReg(channel, SENSING_PRESS_DETECT_VAL);  // Write 0x0000 to set the output to 0V
    timeWaitMs(PIEZO_RELAXATION_TIME_INIT_MS);  // wait relaxation
    uint16_t reg_read;
    // Averaging offset value to remove digital noise
    uint16_t sum = 0;
    for(int i = 0; i < VFEEDBACK_AVERAGE_SAMPLING; i++)
    {
        reg_read = spiReadWriteReg(channel, 0xC000); // Write 0xC000 again to get the ADC offset value.
        sum += reg_read & REG_READ_VFEEDBACK_MASK;
    }
    bos1901[channel].voltageReadState.offset = (sum + VFEEDBACK_AVERAGE_SAMPLING/2) / VFEEDBACK_AVERAGE_SAMPLING;    // save for later
}

static void advSensingGetSensingVoltage(uint8_t channel)
{
    // read VFEEDBACK - averaging to remove digital noise
    uint16_t regConfig = 0x5 << 12 | 0xD << 7 | 1 << 4 | 0x7;
    spiReadWriteReg(channel, regConfig);
    uint16_t tmp;
    int32_t sum = 0;
    for(uint8_t i = 0; i < VFEEDBACK_AVERAGE_SAMPLING; i++)
    {
        tmp = spiReadWriteReg(channel, regConfig);
        sum += tmp & REG_READ_VFEEDBACK_MASK;  // read VFEEDBACK (use on read value)
    }
    bos1901[channel].voltageReadState.vfeedback = (sum + VFEEDBACK_AVERAGE_SAMPLING/2) / VFEEDBACK_AVERAGE_SAMPLING;

    // calculate vsense & convert to voltage
    bos1901[channel].voltageReadState.voltageValue = advSensingVfeedback2Volt( (bos1901[channel].voltageReadState.vfeedback - bos1901[channel].voltageReadState.offset));
    bos1901[channel].voltageReadState.newValueReady = true;
}

static void addToSlopeHistory(SlopeSensingState *ptrSensingState, int32_t dataMicroVolt, uint32_t deltaTimeUs)
{
    uint64_t currentTime = timeGetUsCounter();
    if (ptrSensingState->activeData.prevDataInit == false)
    {
        ptrSensingState->activeData.lastDataTimestamp = timeGetUsCounter();
        ptrSensingState->activeData.prevDataInit = true;
        ptrSensingState->activeData.prevDataIntMicroVolt = dataMicroVolt;
        return;
    }
    else if((currentTime - ptrSensingState->activeData.lastDataTimestamp) > 10000) // reset time out
    {

        ptrSensingState->activeData.prevDataInit = false;
        ptrSensingState->activeData.prevDataIntMicroVolt = dataMicroVolt;
        ptrSensingState->activeData.historyIndex = 0;
        ptrSensingState->activeData.windowIsFull = false;
        return;
    }

    ptrSensingState->activeData.lastDataTimestamp = timeGetUsCounter();

    int64_t difference = dataMicroVolt - ptrSensingState->activeData.prevDataIntMicroVolt;
    int32_t slope = (int32_t) (((int64_t) difference * 1000) / deltaTimeUs); // Unit = microV/ms (or nV/microSec)

    ptrSensingState->activeData.prevDataIntMicroVolt = dataMicroVolt;

    ptrSensingState->activeData.slopeHistory[ptrSensingState->activeData.historyIndex++] = slope;

    if (ptrSensingState->activeData.historyIndex >= ptrSensingState->windowSize)
    {
        ptrSensingState->activeData.historyIndex = 0;
        ptrSensingState->activeData.windowIsFull = true;
    }
}

static int32_t computeAverageSlope(SlopeSensingState *ptrSensingState)
{
    int64_t averageSlope = 0;
    for (uint8_t i = 0; i < ptrSensingState->windowSize; i++)
    {
        averageSlope += ptrSensingState->activeData.slopeHistory[i];
    }

    averageSlope /= ptrSensingState->windowSize;

    return averageSlope;
}

static void advSensingSlopeDetection(SlopeSensingState *ptrSensingState, VoltageReadState *ptrVoltageReadState)
{
    // enter when new value read
    // calculates average slope on a moving window
    // slope values are kept in a history table.
    // if history table is not full, detection is not evaluated.
    // once history table is full, detection is evaluated at every new reading.
    // slope must stay above threshold for the holdtime for detection to be successful.
    // value are reset in another function, when detection is deemed successful according to all active mechanims

    if(ptrSensingState->isEnabled)
    {
        if (ptrVoltageReadState->newValueReady)
        {
            int32_t dataMicroVolt = ptrVoltageReadState->voltageValue * 1000000;

            addToSlopeHistory(ptrSensingState, dataMicroVolt, DATA_HANDLER_SLOPE_DELTATIME_US);

            ptrSensingState->activeData.totalDeltaTimeUs += DATA_HANDLER_SLOPE_DELTATIME_US;

            if (ptrSensingState->activeData.windowIsFull)
            {
                int32_t avgSlope = computeAverageSlope(ptrSensingState); // Unit = microV/ms
                // eval slope
                if ((ptrSensingState->slopeThreshold > 0 &&
                     avgSlope > ptrSensingState->slopeThreshold) ||
                    (ptrSensingState->slopeThreshold < 0 &&
                     avgSlope < ptrSensingState->slopeThreshold))
                {
                    if (ptrSensingState->counter >= ptrSensingState->holdTime)
                    {
                        ptrSensingState->isSuccessful = true;
                    }
                    else
                    {
                        ptrSensingState->isSuccessful = false;
                        ptrSensingState->counter++;
                    }
                }
                else
                {
                    ptrSensingState->isSuccessful = false;
                    ptrSensingState->counter = 0;
                }

                ptrSensingState->activeData.totalDeltaTimeUs = 0;
            }
        }
    }
}

static void advSensingValueDetection(ValueSensingState *ptrSensingState, VoltageReadState *ptrVoltageReadState)
{
    // enter only if new value is read.
    // check if value is above threshold
    // check if holdtime is reached
    // value are reset in another function, when detection is deemed successful according to all active mechanims

    if(ptrSensingState->isEnabled)
    {
        if (ptrVoltageReadState->newValueReady)
        {
            ptrSensingState->valueVal = ptrVoltageReadState->voltageValue;
            // eval value
            if ((ptrSensingState->valueThreshold > 0 &&
                 ptrSensingState->valueVal > ptrSensingState->valueThreshold) ||
                (ptrSensingState->valueThreshold <= 0 &&
                 ptrSensingState->valueVal < ptrSensingState->valueThreshold))
            {
                if (ptrSensingState->counter >= ptrSensingState->holdTime)
                {
                    ptrSensingState->isSuccessful = true;
                }
                else
                {
                    ptrSensingState->isSuccessful = false;
                    ptrSensingState->counter++;
                }
            }
            else
            {
                ptrSensingState->isSuccessful = false;
                ptrSensingState->counter = 0;
            }
        }
    }
}


static bool advSensingEvalDetection(ValueSensingState *valueSense1, SlopeSensingState *slopeSense, ValueSensingState *valueSense2, VoltageReadState *ptrVoltageReadState)
{
    // check if detection is successful according to enabled mechanisms
    bool detectionSuccessful;
    bool ValueSenseEnabled1, ValueSenseEnabled2, SlopeSenseEnabled;

    ValueSenseEnabled1 = valueSense1 != NULL ? valueSense1->isEnabled : false;
    SlopeSenseEnabled  = slopeSense  != NULL ? slopeSense->isEnabled : false;
    ValueSenseEnabled2 = valueSense2 != NULL ? valueSense2->isEnabled : false;

    if (ValueSenseEnabled1 && SlopeSenseEnabled && ValueSenseEnabled2)
        detectionSuccessful = (valueSense1->isSuccessful && slopeSense->isSuccessful) || valueSense2->isSuccessful;
    else if (ValueSenseEnabled1 && SlopeSenseEnabled)
        detectionSuccessful = valueSense1->isSuccessful && slopeSense->isSuccessful;
    else if (ValueSenseEnabled2 && SlopeSenseEnabled)
        detectionSuccessful = valueSense2->isSuccessful || slopeSense->isSuccessful;
    else if (ValueSenseEnabled1 && ValueSenseEnabled2)
        detectionSuccessful = valueSense1->isSuccessful || valueSense2->isSuccessful;
    else if (ValueSenseEnabled1)
        detectionSuccessful = valueSense1->isSuccessful;
    else if (SlopeSenseEnabled)
        detectionSuccessful = slopeSense->isSuccessful;
    else if (ValueSenseEnabled2)
        detectionSuccessful = valueSense2->isSuccessful;
    else
        detectionSuccessful = false;

    // reset poll voltage bool
    ptrVoltageReadState->newValueReady = false;

    return detectionSuccessful;
}


static void advSensingConfigureParameters(uint8_t channel)
{
    // press
    bos1901[channel].pressValueSense1.isEnabled = 			PRESS_DETECTION_VALUE1_ENABLED;
    bos1901[channel].pressValueSense1.valueThreshold =      PRESS_DETECTION_VALUE1_THRESHOLD;
    bos1901[channel].pressValueSense1.holdTime = 			PRESS_DETECTION_VALUE1_HOLDTIME;

    bos1901[channel].pressSlopeSense.isEnabled = 			PRESS_DETECTION_SLOPE_ENABLED;
    bos1901[channel].pressSlopeSense.slopeThreshold = 	    PRESS_DETECTION_SLOPE_THRESHOLD;
    bos1901[channel].pressSlopeSense.holdTime = 			PRESS_DETECTION_SLOPE_HOLDTIME;
    bos1901[channel].pressSlopeSense.windowSize = 			PRESS_DETECTION_SLOPE_WINDOW_SIZE;

    bos1901[channel].pressValueSense2.isEnabled = 			PRESS_DETECTION_VALUE2_ENABLED;
    bos1901[channel].pressValueSense2.valueThreshold =      PRESS_DETECTION_VALUE2_THRESHOLD;
    bos1901[channel].pressValueSense2.holdTime = 			PRESS_DETECTION_VALUE2_HOLDTIME;

    // release
    bos1901[channel].releaseValueSense1.isEnabled = 		RELEASE_DETECTION_VALUE1_ENABLED;
    bos1901[channel].releaseValueSense1.valueThreshold =    RELEASE_DETECTION_VALUE1_THRESHOLD;
    bos1901[channel].releaseValueSense1.holdTime = 			RELEASE_DETECTION_VALUE1_HOLDTIME;

    bos1901[channel].releaseSlopeSense.isEnabled = 			RELEASE_DETECTION_SLOPE_ENABLED;
    bos1901[channel].releaseSlopeSense.slopeThreshold = 	RELEASE_DETECTION_SLOPE_THRESHOLD;
    bos1901[channel].releaseSlopeSense.holdTime = 			RELEASE_DETECTION_SLOPE_HOLDTIME;
    bos1901[channel].releaseSlopeSense.windowSize = 		RELEASE_DETECTION_SLOPE_WINDOW_SIZE;

    bos1901[channel].releaseValueSense2.isEnabled = 		RELEASE_DETECTION_VALUE2_ENABLED;
    bos1901[channel].releaseValueSense2.valueThreshold =    RELEASE_DETECTION_VALUE2_THRESHOLD;
    bos1901[channel].releaseValueSense2.holdTime = 			RELEASE_DETECTION_VALUE2_HOLDTIME;
}

static void advSensingReset(uint8_t channel)
{
    advSensingValueDetectionReset(&bos1901[channel].pressValueSense1);
    advSensingSlopeDetectionReset(&bos1901[channel].pressSlopeSense);
    advSensingValueDetectionReset(&bos1901[channel].pressValueSense2);
    advSensingValueDetectionReset(&bos1901[channel].releaseValueSense1);
    advSensingSlopeDetectionReset(&bos1901[channel].releaseSlopeSense);
    advSensingValueDetectionReset(&bos1901[channel].releaseValueSense2);
}

/*
 * Public Section
 */


/********************************************************
*				    MAIN EXAMPLE
********************************************************/

//int main(void)
void example(void)
{
    while(1)
    {
        advSensingExecuteSensing();
        vTaskDelay(1);
    }
}

void drive(uint16_t freq, uint8_t cycles, WaveformType waveformType) {

    frequency = freq;
    waveform = waveformType;
    for (int i = 0; i< NB_CHANNELS; i++) {
        advSensingCalculateWaveforms(i);
    }
    

    // while(1)
    // {
        
    // }
}

#endif
