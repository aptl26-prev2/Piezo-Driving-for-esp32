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
// #include "../components/arduino/tools/sdk/esp32c3/include/driver/include/driver/gpio.h"
// #include "../components/arduino/libraries/spi/src/SPI.h"
#include "driver/spi_master.h"
#include "driver/gpio.h"


#define SPI_HOST    HSPI_HOST //Define the SPI host to be HSPI

// board channel A
// #define SS0_PORT (GPIOA)
// #define SS0_PIN  (SS0_Pin)
// board channel B
// #define SS1_PORT (GPIOE)
// #define SS1_PIN  (SS1_Pin)
#define CS_PIN1 GPIO_NUM_4
#define CS_PIN2 GPIO_NUM_16
#define CS_PIN3 GPIO_NUM_15
#define CS_PIN4 GPIO_NUM_32

/********************************************************
*				 FUNCTIONS DEFINTION
********************************************************/

extern SPIClass * hspi1;
extern SPIClass * hspi4;
extern spi_device_handle_t spi0;
extern spi_device_handle_t spi1;
extern spi_device_handle_t spi2;
extern spi_device_handle_t spi3;

static const int spiClk = 12*1000*1000;
// spi_device_handle_t spi0;

// void spiInit() {

// }


uint16_t spiReadWriteReg(uint8_t chipSelect, uint16_t data)
{
	spi_device_handle_t spiHandle = spi0; //Declare a handle for the selected SPI device
	gpio_set_level(CS_PIN2, 1); 

	uint16_t DataSend = SPI_SWAP_DATA_TX(data, 16); //Swap and copy the data to be sent to a local variable

	uint16_t DataReceive = 0; //Declare a variable to hold the received data

	esp_err_t ret;
	switch(chipSelect) //Select which SPI device to use based on chip select parameter
	{
		case 0:
			spiHandle = spi0; //Use chip select 0 device handle
			break;
		case 1:
			spiHandle = spi1; //Use chip select 1 device handle
			break;
		case 2:
			spiHandle = spi2; //Use chip select 2 device handle
			break;
		case 3:
			spiHandle = spi3; //Use chip select 2 device handle
			break;
		default:
			spiHandle = spi0; //Use chip select 0 device handle by default
	}

	//Create a transaction structure
	spi_transaction_t t;
	memset(&t, 0, sizeof(t));       //Zero out the transaction structure
	t.length = 16;               //Set the length of the transaction in bits (16 bytes * 8 bits/byte)
	t.tx_buffer = &DataSend;         //Set the pointer to the data buffer to be sent
	t.rx_buffer = &DataReceive;      //Set the pointer to the data buffer to be received

	//Transmit and receive the data using polling mode
	ret = spi_device_polling_transmit(spiHandle, &t);  //Transmit and receive the data using polling mode (blocking until done)
	assert(ret==ESP_OK);            //Check if transmission and reception were successful

	// printf("DataSend: %X\n\n", data);
	// printf("DataReceive: %X\n\n", DataReceive);

	return SPI_SWAP_DATA_RX(DataReceive, 16); //Return the received data
	// return DataReceive
}



// // Writes data to SPI and reads returned data
// uint16_t spiReadWriteReg(uint8_t chipSelect, uint16_t data)
// {
// 	SPIClass * spiHandle;
// 	// GPIO_TypeDef *gpioPort;
// 	gpio_num_t gpioPin;
// 	// if (data == 0x56A7) {
// 	// 	printf("inside target function\n");
// 	// 	printf("data: ");
// 	// 	printf("%x\n", data);
// 	// }
// 	uint16_t DataSend = data;
// 	uint16_t DataReceive = 0;

// 	spiHandle = hspi1;

// 	gpioPin = CS_PIN1;
// 	// switch(chipSelect)
// 	// {
// 	// 	case 0:
// 	// 		spiHandle = hspi1;
// 	// 		// gpioPort = SS0_PORT;
// 	// 		gpioPin = CS_PIN1;
// 	// 		break;
// 	// 	case 1:
// 	// 		spiHandle = hspi4;
// 	// 		// gpioPort = SS1_PORT;
// 	// 		gpioPin = CS_PIN2;
// 	// 		break;
// 	// 	default:
// 	// 		spiHandle = hspi1;
// 	// 		// gpioPort = SS0_PORT;
// 	// 		gpioPin = CS_PIN1;
// 	// }

// 	// HAL_GPIO_WritePin(gpioPort, gpioPin, 0);
// 	// HAL_SPI_TransmitReceive(spiHandle, (uint8_t*)&DataSend, (uint8_t*)&DataReceive, 1, 100);
// 	// HAL_GPIO_WritePin(gpioPort, gpioPin, 1);
// 	// static const int spiClk = 2*750*1000;

// 	// static const int spiClk = 35*1000*1000;
// 	// static const int spiClk = 12*1000*1000;
// 	// static const int spiClk = 1000000;
// 	// spiHandle->beginTransaction(SPISettings(spiClk, SPI_MSBFIRST, SPI_MODE0));
// 	// gpio_set_level(gpioPin, 0);
// 	// DataReceive = spiHandle->transfer16(DataSend);
// 	// gpio_set_level(gpioPin, 1);
// 	// spiHandle->endTransaction();

// 	gpio_set_level(gpioPin, 0);
// 	spiHandle->beginTransaction(SPISettings(spiClk, SPI_MSBFIRST, SPI_MODE0));
// 	DataReceive = spiHandle->transfer16(DataSend);
// 	spiHandle->endTransaction();
// 	gpio_set_level(gpioPin, 1);

// 	printf("DataSend: ");
// 	printf("%x\n", DataSend);
// 	// printf(",  Channel: ");
// 	// printf("%x\n", chipSelect);
// 	printf("DataReceive: ");
// 	printf("%x\n", DataReceive);
	

// 	return DataReceive;

// }





// void spiInit()
// {
//   spi_bus_config_t buscfg={
//     .mosi_io_num=PIN_NUM_MOSI, //Set the MOSI pin number
//     .miso_io_num=PIN_NUM_MISO, //Set the MISO pin number
//     .sclk_io_num=PIN_NUM_CLK, //Set the SCLK pin number
//     .quadwp_io_num=-1, //Set the QUADWP pin number to -1 (not used)
//     .quadhd_io_num=-1, //Set the QUADHD pin number to -1 (not used)
//     .max_transfer_sz=16 //Set the maximum transfer size in bytes
//   };

//   spi_device_interface_config_t devcfg0={
//     .mode=0,                                //Set the SPI mode to 0
//     .clock_speed_hz= spiClk,           //Set the clock speed to 10 MHz
//     .spics_io_num=PIN_NUM_CS0,
// 	.flags=SPI_DEVICE_NO_DUMMY,              //Set the CS pin number for chip select 0
//     .queue_size=7,                          //Set the queue size to 7
//   };

//   //Initialize the SPI devices
//   esp_err_t ret=spi_bus_initialize(SPI_HOST, &buscfg, DMA_CHAN); //Initialize the SPI bus with the given configuration and DMA channel
//   assert(ret==ESP_OK); //Check if the initialization was successful
//   ret=spi_bus_add_device(SPI_HOST, &devcfg0, &spi0); //Add a device to the SPI bus with the given configuration and get a handle for it (chip select 0)
//   assert(ret==ESP_OK); //Check if adding device was successful

// }




// uint16_t spiReadWriteReg(uint8_t chipSelect, uint16_t data)
// {
// 	spi_device_handle_t spiHandle = spi0; //Declare a handle for the selected SPI device


// 	uint16_t DataSend = SPI_SWAP_DATA_TX(data, 16); //Swap and copy the data to be sent to a local variable

// 	uint16_t DataReceive = 0; //Declare a variable to hold the received data

// 	esp_err_t ret;
// 	// switch(chipSelect) //Select which SPI device to use based on chip select parameter
// 	// {
// 	// 	case 0:
// 	// 		spiHandle = spi0; //Use chip select 0 device handle
// 	// 		break;
// 	// 	case 1:
// 	// 		spiHandle = spi1; //Use chip select 1 device handle
// 	// 		break;
// 	// 	default:
// 	// 		spiHandle = spi0; //Use chip select 0 device handle by default
// 	// }

// 	//Create a transaction structure
// 	spi_transaction_t t;
// 	memset(&t, 0, sizeof(t));       //Zero out the transaction structure
// 	t.length = 16;               //Set the length of the transaction in bits (16 bytes * 8 bits/byte)
// 	t.tx_buffer = &DataSend;         //Set the pointer to the data buffer to be sent
// 	t.rx_buffer = &DataReceive;      //Set the pointer to the data buffer to be received

// 	//Transmit and receive the data using polling mode
// 	ret = spi_device_polling_transmit(spiHandle, &t);  //Transmit and receive the data using polling mode (blocking until done)
// 	assert(ret==ESP_OK);            //Check if transmission and reception were successful

// 	// printf("DataSend: %X\n\n", data);
// 	// printf("DataReceive: %X\n\n", DataReceive);

// 	return SPI_SWAP_DATA_RX(DataReceive, 16); //Return the received data
// 	// return DataReceive
// }

