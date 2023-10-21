//
// Description: Generic Time API
//
// Copyright (c) 2019 Boreas Technologies All rights reserved.
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

#ifndef _TIMEEX_H
#define _TIMEEX_H

#include <stdint.h>
#include <stdbool.h>
// #include "stm32f4xx_hal.h" // insert your MCU resource file here.

// #include "../components/arduino/libraries/spi/src/SPI.h"

#define MICROSECOND_IN_MILLISECOND(_us) (_us/1000)

#define SECOND_IN_MILLISECOND(_s) (_s*1000)

#define SECOND_IN_MICROSECOND(_s) (_s*1000000)

/*
 * @brief Set microseconds increment for counter.
 *
 * @param[in] usIncrement The increment time in microsecond.
 *
 * @return void
 */
void timeSetUsIncrement(uint32_t usIncrement);

/*
 * @brief Wait specific amount time in milliseconds.
 *
 * @param[in] timeMs The time in microsecond to wait for
 *
 * @return void
 */
void timeWaitMs(uint32_t timeMs);

/*
 * @brief Wait specific amount time in microsecond.
 *
 * @param[in] timeUs The time in microsecond to wait for
 *
 * @return void
 */
void timeWaitUs(uint32_t timeUs);

/*
 * @brief Return time counter in microseconds.
 *
 * @return Us time value
 */
uint64_t timeGetUsCounter(void);

/*
 * @brief Tells if timer has expired
 *
 * @return true if timer expired, false if not.
 */
bool timeIsTimerExpired(void);

/*
 * @brief Reset timer flag
 *
 */
void timeResetTimerFlag(void);

/*
 * @brief Set timer flag
 *
 */
void timeSetTimerFlag(void);

/*
 * @brief Increment microseconds time counter
 *
 */
void timeIncrementTimeCounter(void);

#endif // _TIMEEX_H
