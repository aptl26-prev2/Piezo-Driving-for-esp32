//
// Description: SPI module for ST MCU
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

#include <stdint.h>
#include "spi.h"
#include "../components/arduino/tools/sdk/esp32c3/include/driver/include/driver/gpio.h"
#include "../components/arduino/libraries/spi/src/SPI.h"

// board channel A
// #define SS0_PORT (GPIOA)
// #define SS0_PIN  (SS0_Pin)
// board channel B
// #define SS1_PORT (GPIOE)
// #define SS1_PIN  (SS1_Pin)
#define CS_PIN1 GPIO_NUM_16
#define CS_PIN2 GPIO_NUM_16

/********************************************************
*				 FUNCTIONS DEFINTION
********************************************************/

extern SPIClass * hspi1;
extern SPIClass * hspi4;

void spiInit()
{

}

// Writes data to SPI and reads returned data
uint16_t spiReadWriteReg(uint8_t chipSelect, uint16_t data)
{
	SPIClass * spiHandle;
	// GPIO_TypeDef *gpioPort;
	gpio_num_t gpioPin;
	// if (data == 0x56A7) {
	// 	printf("inside target function\n");
	// 	printf("data: ");
	// 	printf("%x\n", data);
	// }
	uint16_t DataSend = data;
	uint16_t DataReceive = 0;

	spiHandle = hspi1;

	gpioPin = CS_PIN1;
	// switch(chipSelect)
	// {
	// 	case 0:
	// 		spiHandle = hspi1;
	// 		// gpioPort = SS0_PORT;
	// 		gpioPin = CS_PIN1;
	// 		break;
	// 	case 1:
	// 		spiHandle = hspi4;
	// 		// gpioPort = SS1_PORT;
	// 		gpioPin = CS_PIN2;
	// 		break;
	// 	default:
	// 		spiHandle = hspi1;
	// 		// gpioPort = SS0_PORT;
	// 		gpioPin = CS_PIN1;
	// }

	// HAL_GPIO_WritePin(gpioPort, gpioPin, 0);
	// HAL_SPI_TransmitReceive(spiHandle, (uint8_t*)&DataSend, (uint8_t*)&DataReceive, 1, 100);
	// HAL_GPIO_WritePin(gpioPort, gpioPin, 1);
	// static const int spiClk = 12000000;
	static const int spiClk = 750000;
	// static const int spiClk = 1000000;
	spiHandle->beginTransaction(SPISettings(spiClk, SPI_MSBFIRST, SPI_MODE0));
	gpio_set_level(gpioPin, 0);
	DataReceive = spiHandle->transfer16(DataSend);
	gpio_set_level(gpioPin, 1);
	spiHandle->endTransaction();

	printf("DataSend: ");
	printf("%x\n", DataSend);
	// printf(",  Channel: ");
	// printf("%x\n", chipSelect);
	printf("DataReceive: ");
	printf("%x\n", DataReceive);
	

	return DataReceive;

}


