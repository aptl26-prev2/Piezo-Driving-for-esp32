// //
// // Description: LED  Generic
// // Created on 04/15/2021
// // Copyright (c) 2021 Boreas Technologies All rights reserved.
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

// // THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// // IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// // FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// // AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// // LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// // OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// // SOFTWARE.
// //

// #include <IoExpander.h>
// #include "ledEx.h"
// #include "main.h"

// // Include your LED driver file if any.
// // These functions are only used informatively. They are not required for the example to work.
// // You may leave these functions empty if you don't need them.

// typedef enum
// {
//     ledExStateOn = 0,
//     ledExStateOff = 1
// } ledExState;


// int32_t ledExInit()
// {
//     // Insert your LED init code.
//     ledExWrite(LEDEX_D1, color_black);
//     ledExWrite(LEDEX_D2, color_black);
//     ledExWrite(LEDEX_CHA, color_black);
//     ledExWrite(LEDEX_CHB, color_black);

//     return 0;
// }

// void ledExWrite(uint8_t led, ledExColor color)
// {
// 	GPIO_TypeDef* portRed;
// 	GPIO_TypeDef* portGreen;
// 	GPIO_TypeDef* portBlue;
// 	uint16_t pinNumRed,pinNumGreen,pinNumBlue;
//     uint8_t reg;
    
//     switch(led)
//     {
//         case LEDEX_D1: 
//             portRed = LED_D1_RED_PORT;
//             pinNumRed = LED_D1_RED_PIN;
//             portGreen = LED_D1_GREEN_PORT;
//             pinNumGreen = LED_D1_GREEN_PIN;
//             portBlue = LED_D1_BLUE_PORT;
//             pinNumBlue = LED_D1_BLUE_PIN;
//             break;
//         case LEDEX_D2: 
//             portRed = LED_D2_RED_PORT;
//             pinNumRed = LED_D2_RED_PIN;
//             portGreen = LED_D2_GREEN_PORT;
//             pinNumGreen = LED_D2_GREEN_PIN;
//             portBlue = LED_D2_BLUE_PORT;
//             pinNumBlue = LED_D2_BLUE_PIN;
//             break;
//         case LEDEX_CHA:
//             portRed = LED_CHA_RED_PORT;
//             pinNumRed = LED_CHA_RED_PIN;
//             portGreen = LED_CHA_GREEN_PORT;
//             pinNumGreen = LED_CHA_GREEN_PIN;
//             portBlue = LED_CHA_BLUE_PORT;
//             pinNumBlue = LED_CHA_BLUE_PIN;
//             break;
//         case LEDEX_CHB:
//             portRed = LED_CHB_RED_PORT;
//             pinNumRed = LED_CHB_RED_PIN;
//             portGreen = LED_CHB_GREEN_PORT;
//             pinNumGreen = LED_CHB_GREEN_PIN;
//             portBlue = LED_CHB_BLUE_PORT;
//             pinNumBlue = LED_CHB_BLUE_PIN;
//             break;
//         default:
//             portRed = NULL;
//             pinNumRed = 0;
//             portGreen = NULL;
//             pinNumGreen = 0;
//             portBlue = NULL;
//             pinNumBlue = 0;
//             break;
//     }
    
//     switch(led)
//     {
// 		case LEDEX_D1:
// 		case LEDEX_D2:
// 			if(portRed != NULL && portGreen != NULL && portBlue != NULL)
// 			{
// 				// Change Colors
// 				switch (color)
// 				{
// 					case color_black:
// 						HAL_GPIO_WritePin(portRed,pinNumRed,ledExStateOff);
// 						HAL_GPIO_WritePin(portGreen,pinNumGreen,ledExStateOff);
// 						HAL_GPIO_WritePin(portBlue,pinNumBlue,ledExStateOff);
// 						break;
// 					case color_red:
// 						HAL_GPIO_WritePin(portRed,pinNumRed,ledExStateOn);
// 						HAL_GPIO_WritePin(portGreen,pinNumGreen,ledExStateOff);
// 						HAL_GPIO_WritePin(portBlue,pinNumBlue,ledExStateOff);
// 						break;
// 					case color_green:
// 						HAL_GPIO_WritePin(portRed,pinNumRed,ledExStateOff);
// 						HAL_GPIO_WritePin(portGreen,pinNumGreen,ledExStateOn);
// 						HAL_GPIO_WritePin(portBlue,pinNumBlue,ledExStateOff);
// 						break;
// 					case color_blue:
// 						HAL_GPIO_WritePin(portRed,pinNumRed,ledExStateOff);
// 						HAL_GPIO_WritePin(portGreen,pinNumGreen,ledExStateOff);
// 						HAL_GPIO_WritePin(portBlue,pinNumBlue,ledExStateOn);
// 						break;
// 					case color_yellow:
// 						HAL_GPIO_WritePin(portRed,pinNumRed,ledExStateOn);
// 						HAL_GPIO_WritePin(portGreen,pinNumGreen,ledExStateOn);
// 						HAL_GPIO_WritePin(portBlue,pinNumBlue,ledExStateOff);
// 						break;
// 					case color_magenta:
// 						HAL_GPIO_WritePin(portRed,pinNumRed,ledExStateOn);
// 						HAL_GPIO_WritePin(portGreen,pinNumGreen,ledExStateOff);
// 						HAL_GPIO_WritePin(portBlue,pinNumBlue,ledExStateOn);
// 						break;
// 					case color_cyan:
// 						HAL_GPIO_WritePin(portRed,pinNumRed,ledExStateOff);
// 						HAL_GPIO_WritePin(portGreen,pinNumGreen,ledExStateOn);
// 						HAL_GPIO_WritePin(portBlue,pinNumBlue,ledExStateOn);
// 						break;
// 					case color_white:
// 						HAL_GPIO_WritePin(portRed,pinNumRed,ledExStateOn);
// 						HAL_GPIO_WritePin(portGreen,pinNumGreen,ledExStateOn);
// 						HAL_GPIO_WritePin(portBlue,pinNumBlue,ledExStateOn);
// 						break;
// 					default:
// 						HAL_GPIO_WritePin(portRed,pinNumRed,ledExStateOff);
// 						HAL_GPIO_WritePin(portGreen,pinNumGreen,ledExStateOff);
// 						HAL_GPIO_WritePin(portBlue,pinNumBlue,ledExStateOff);
// 						break;

// 					}
// 				}
// 			break;
// 		case LEDEX_CHA:
// 		case LEDEX_CHB:
// 			// Get port value
//             reg = ioExpanderRead();
//             // clear bits
//             SET_BIT(reg, 1 << pinNumRed);
//             SET_BIT(reg, 1 << pinNumGreen);
//             SET_BIT(reg, 1 << pinNumBlue);
//             // Change Colors - associated bits
// 			switch (color)
// 			{
// 				case color_black:
// 					break;
// 				case color_red:
// 					CLEAR_BIT(reg, 1 << pinNumRed);
// 					break;
// 				case color_green:
// 					CLEAR_BIT(reg, 1 << pinNumGreen);
// 					break;
// 				case color_blue:
// 					CLEAR_BIT(reg, 1 << pinNumBlue);
// 					break;
// 				case color_yellow:
// 					CLEAR_BIT(reg, 1 << pinNumRed);
// 					CLEAR_BIT(reg, 1 << pinNumGreen);
// 					break;
// 				case color_magenta:
// 					CLEAR_BIT(reg, 1 << pinNumRed);
// 					CLEAR_BIT(reg, 1 << pinNumBlue);
// 					break;
// 				case color_cyan:
// 					CLEAR_BIT(reg, 1 << pinNumGreen);
// 					CLEAR_BIT(reg, 1 << pinNumBlue);
// 					break;
// 				case color_white:
// 					CLEAR_BIT(reg, 1 << pinNumRed);
// 					CLEAR_BIT(reg, 1 << pinNumGreen);
// 					CLEAR_BIT(reg, 1 << pinNumBlue);
// 					break;
// 				default:
// 					break;
// 			}
// 			// Set port value
//             ioExpanderWrite(reg);
// 			break;
//     }
// }

