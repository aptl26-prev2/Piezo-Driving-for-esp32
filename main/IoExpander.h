//
// Description: I2C Driver Interface for IoExpander
// Created on 1/23/2020
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

#ifndef _IOEXPANDER_H
#define _IOEXPANDER_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
// #include "stm32f4xx_hal.h" // insert your MCU resource file here.
// #include "../components/arduino/libraries/spi/src/SPI.h"
#include "main.h"

#define I2C_7BIT_ADDRESS_MASK (0x7F)
#define I2C_TIMEOUT (100u)
#define IOEXPANDER_I2C_ADDRESS (0x38)
#define IOEXPANDER_I2C_ADDRESS_WRITE (IOEXPANDER_I2C_ADDRESS << 1)
#define IOEXPANDER_I2C_ADDRESS_READ (IOEXPANDER_I2C_ADDRESS << 1 | 1)
#define IOEXPANDER_REGISTER_INPUT (0x0)
#define IOEXPANDER_REGISTER_OUTPUT (0x1)
#define IOEXPANDER_REGISTER_POLARITY (0x2)
#define IOEXPANDER_REGISTER_CONFIG (0x3)

// global init function
void ioExpanderInit();
    
void ioExpanderConfig();

uint8_t ioExpanderRead();

bool ioExpanderWrite(uint8_t reg);



#endif // _IOEXPANDER_H
