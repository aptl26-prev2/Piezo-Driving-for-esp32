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

#include <stdbool.h>
#include <stdint.h>

#include "gpioEx.h"
#include "data.h"

#define GPIO_

/*
 * Private Section
 */


/*
 * Public Section
 */

// bool gpioExSet(uint8_t gpio, GPIOState inState)
// {
//     bool res = false;

// 	GPIO_TypeDef *gpioPort;
// 	uint16_t	gpioPin;

// 	switch(gpio)
// 	{
// 		case GPIOEX0:
// 			gpioPort = IO0_PORT;
// 			gpioPin = IO0_PIN;
// 			break;
// 		case GPIOEX1:
// 			gpioPort = IO1_PORT;
// 			gpioPin = IO1_PIN;
// 			break;
// 		case GPIOEX2:
// 			gpioPort = IO2_PORT;
// 			gpioPin = IO2_PIN;
// 			break;
// 		case GPIOEX3:
// 			gpioPort = IO3_PORT;
// 			gpioPin = IO3_PIN;
// 			break;
// 		default:
// 			gpioPort = IO0_PORT;
// 			gpioPin = IO0_PIN;
// 	}

// 	if (inState != GPIOState_Invalid)
// 	{
// 		// replace this line with your MCU GPIO read code.
// 		uint8_t stateToWrite = inState == GPIOState_High;
// 		HAL_GPIO_WritePin(gpioPort,gpioPin,stateToWrite);
// 		res = true;
// 	}

//     return res;
// }

// GPIOState gpioExGet(uint8_t gpio)
// {
// 	GPIO_TypeDef *gpioPort;
// 	uint16_t	gpioPin;
//     GPIOState state = GPIOState_Invalid;

// 	switch(gpio)
// 	{
// 		case GPIOEX0:
// 			gpioPort = IO0_PORT;
// 			gpioPin = IO0_PIN;
// 			break;
// 		case GPIOEX1:
// 			gpioPort = IO1_PORT;
// 			gpioPin = IO1_PIN;
// 			break;
// 		case GPIOEX2:
// 			gpioPort = IO2_PORT;
// 			gpioPin = IO2_PIN;
// 			break;
// 		case GPIOEX3:
// 			gpioPort = IO3_PORT;
// 			gpioPin = IO3_PIN;
// 			break;
// 		default:
// 			gpioPort = IO0_PORT;
// 			gpioPin = IO0_PIN;
// 	}

// 	// replace this line with your MCU GPIO read code.
// 	if (HAL_GPIO_ReadPin(gpioPort,gpioPin) == 1)
// 	{
// 		state = GPIOState_High;
// 	}
// 	else
// 	{
// 		state = GPIOState_Low;
// 	}

//     return state;
// }
