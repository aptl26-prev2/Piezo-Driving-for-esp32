//
// Description: Time API Implementation for Cypress Psoc6 family
// Created on 1/10/2020
// Copyright (c) 2020 Boreas Technologies All rights reserved.
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

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

#include "timeEx.h"
#include "ledEx.h"
#include "math.h"
#include "rom/ets_sys.h"


// Flag variable associated with interrupt timer2
// Note: MCU timer assumed to be at 1MHz with period in us.
static volatile uint8_t timeExFlag = 0; // timer expired flag
static volatile uint64_t timeUsCounter = 0; // us, time counter
static uint32_t timeUsCounterIncrement = 1; // timer period in microseconds

/*
 * Public Section
 */

void timeSetUsIncrement(uint32_t usIncrement)
{
	timeUsCounterIncrement = usIncrement;
}

void timeWaitMs(uint32_t timeMs)
{
    // change to your MCU delay ms function
    // HAL_Delay(timeMs);
     ets_delay_us(1000 * timeMs);
}

void timeWaitUs(uint32_t timeUs)
{
    // change to your MCU delay us function.
	// uint32_t time = timeUs/1000 > 1 ? timeUs/1000 : 1;
	// HAL_Delay(time);
    ets_delay_us(timeUs);
}

uint64_t timeGetUsCounter(void)
{
	return timeUsCounter;
}

bool timeIsTimerExpired(void)
{
	return timeExFlag;
}

void timeSetTimerFlag(void)
{
	timeExFlag = 1;
	timeIncrementTimeCounter();
}

void timeResetTimerFlag(void)
{
	timeExFlag = 0;
}

void timeIncrementTimeCounter(void)
{
	timeUsCounter += timeUsCounterIncrement;
}


