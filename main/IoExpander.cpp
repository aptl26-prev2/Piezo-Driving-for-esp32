// //
// // Description: I2C Implementation for the Psoc6 Family
// // Created on 1/23/2020
// // Copyright (c) 2020 Boreas Technologies All rights reserved.
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
// #include <stdbool.h>
// #include <strings.h>

// #include "data.h"
// #include "timeEx.h"

// #define SEND_STOP               (true)
// #define MAX_BUFFER_LENGTH       (25u) // Maximum Buffer Length

// extern I2C_HandleTypeDef hi2c1;
// static uint8_t regout_ioexpander = 0xFF;

// /*
//  * Public Section
//  */

//  void ioExpanderInit()
// {
// // **** REPLACE WITH YOUR I2C INITIALIZATION CODE *****
        

// // **** REPLACE WITH YOUR I2C INITIALIZATION CODE *****
// }

//  void ioExpanderConfig()
//  {
// 	 // IO Expander configuration
// 	 uint8_t data[2];

// 	 // config register - config as outputs
// 	 data[0] = IOEXPANDER_REGISTER_CONFIG;
// 	 data[1] = 0;
// 	 HAL_I2C_Master_Transmit(&hi2c1, IOEXPANDER_I2C_ADDRESS_WRITE, data, 2, 10000);
// 	 // polarity register - config as outputs
// 	 data[0] = IOEXPANDER_REGISTER_POLARITY;
// 	 data[1] = 0;
// 	 HAL_I2C_Master_Transmit(&hi2c1, IOEXPANDER_I2C_ADDRESS_WRITE, data, 2, 10000);
// 	 // output register
// 	 regout_ioexpander = 0xFF;
// 	 data[0] = IOEXPANDER_REGISTER_OUTPUT;
// 	 data[1] = regout_ioexpander;
// 	 HAL_I2C_Master_Transmit(&hi2c1, IOEXPANDER_I2C_ADDRESS_WRITE, data, 2, 10000);
//  }


// uint8_t ioExpanderRead()
// {
//     return regout_ioexpander;
// }



// bool ioExpanderWrite(uint8_t reg)
// {
// 	regout_ioexpander = reg;
// 	 // output register
// 	 uint8_t data[2];
// 	 data[0] = IOEXPANDER_REGISTER_OUTPUT;
// 	 data[1] = regout_ioexpander;

// 	return HAL_I2C_Master_Transmit(&hi2c1, IOEXPANDER_I2C_ADDRESS_WRITE, (void*)data, 2, 10000) == HAL_OK;
// }


// /*
//  * Private Section
//  */

