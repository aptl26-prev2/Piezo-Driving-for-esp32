//
// Description: LED Generic
// Created on 04/15/2021
// Copyright (c) 2021 Boreas Technologies All rights reserved.
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


#ifndef _LEDEX_H
#define _LEDEX_H

#include <stdint.h>
#include <stdbool.h>
// #include "stm32f4xx_hal.h" // insert your MCU resource file here.
// #include "../components/arduino/libraries/spi/src/SPI.h"
#include "IoExpander.h"

// On GPIO
#define LEDEX_D1       (0)
#define LEDEX_D2       (1)
// On IO Expander
#define LEDEX_CHA       (2)
#define LEDEX_CHB       (3)

#define LEDEX_NB	(4)

#define LED_D1_RED_PORT (GPIOD)
#define LED_D1_RED_PIN  (D1red_Pin)
#define LED_D1_GREEN_PORT (GPIOD)
#define LED_D1_GREEN_PIN  (D1green_Pin)
#define LED_D1_BLUE_PORT (GPIOC)
#define LED_D1_BLUE_PIN  (D1blue_Pin)

#define LED_D2_RED_PORT (GPIOC)
#define LED_D2_RED_PIN  (D2red_Pin)
#define LED_D2_GREEN_PORT (GPIOC)
#define LED_D2_GREEN_PIN  (D2green_Pin)
#define LED_D2_BLUE_PORT (GPIOA)
#define LED_D2_BLUE_PIN  (D2blue_Pin)

#define LED_CHA_RED_PORT (0)
#define LED_CHA_RED_PIN  (5)
#define LED_CHA_GREEN_PORT (0)
#define LED_CHA_GREEN_PIN  (4)
#define LED_CHA_BLUE_PORT (0)
#define LED_CHA_BLUE_PIN  (3)

#define LED_CHB_RED_PORT (0)
#define LED_CHB_RED_PIN  (2)
#define LED_CHB_GREEN_PORT (0)
#define LED_CHB_GREEN_PIN  (1)
#define LED_CHB_BLUE_PORT (0)
#define LED_CHB_BLUE_PIN  (0)

#define COLOR_NB       (8)

typedef enum
{
    color_black = 0,
    color_red,
    color_green,
    color_blue,
    color_yellow,
    color_magenta,
    color_cyan,
    color_white
} ledExColor;

int32_t ledExInit();

void ledExWrite(uint8_t led, ledExColor color);


#endif // _LEDEX_H

