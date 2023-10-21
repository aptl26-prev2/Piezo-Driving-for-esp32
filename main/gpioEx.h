//
// Description: Generic GPIO API
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
#ifndef _GPIOEX_H
#define _GPIOEX_H

#include <stdbool.h>
// #include "stm32f4xx_hal.h" // insert your MCU resource file here.
// #include "../components/arduino/libraries/spi/src/SPI.h"
#include "main.h" // change for get your gpio code.

// #define IO0_PORT (GPIOB)
// #define IO0_PIN  (IO0in_Pin)
// #define IO1_PORT (GPIOB)
// #define IO1_PIN  (IO1in_Pin)
// #define IO2_PORT (GPIOB)
// #define IO2_PIN  (IO2out_Pin)
// #define IO3_PORT (GPIOB)
// #define IO3_PIN  (IO3out_Pin)

// #define GPIOEX0       (0)
// #define GPIOEX1       (1)
// #define GPIOEX2       (2)
// #define GPIOEX3       (3)

typedef enum
{
    GPIOState_High,
    GPIOState_Low,
    GPIOState_Invalid
} GPIOState;

bool gpioExSet(uint8_t gpio, GPIOState state);

GPIOState gpioExGet(uint8_t gpio);

#endif // _GPIO_H
