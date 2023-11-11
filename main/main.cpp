/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "functions.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */


#include <stdint.h>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <cstdint>

#include "example.h"
// #include 

#include "driver/gpio.h"
#include "driver/spi_master.h"
#include <map>


#include "spi.h"
#include "ledEx.h"
#include "gpioEx.h"
#include "timeEx.h"
// /tools/sdk/esp32c3/include/driver/include/driver/gpio.h"
// #include "../components/arduino/libraries/spi/src/SPI.h"
// #include "esp32-hal-timer.h"
#include "esp_log.h"
#include "esp_check.h"
#include "esp_err.h"
#include "esp_timer.h"
#include "math.h"
#include "esp_bt.h"
#include "esp_bt_main.h"
#include "esp_bt_device.h"
#include "esp_gap_bt_api.h"
#include "esp_spp_api.h"
#include "nvs_flash.h"
#include "../components/rapidjson/include/rapidjson/document.h"
// #include "../components/esp_timer/include/esp_timer.h"
// #include "../components/esp_timer/include/esp_timer.h"


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
// I2C_HandleTypeDef hi2c1;

// SPI_HandleTypeDef hspi1;
// SPI_HandleTypeDef hspi4;

// TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

// !ESP code
// BluetoothSerial BTSerial;
// Bluetooth setup with esp lib
#define BT_DEVICE_NAME "HC-05"
#define SPP_SERVER_NAME "SPP_SERVER"
static const esp_spp_mode_t esp_spp_mode = ESP_SPP_MODE_CB;
static const esp_spp_sec_t sec_mask = ESP_SPP_SEC_NONE;
static const esp_spp_role_t role_slave = ESP_SPP_ROLE_SLAVE;
static uint32_t handle = 0;


// SPIClass * hspi1 = NULL;
// SPIClass * hspi4 = NULL;

// declare a pointer to a hw_timer_t structure
// hw_timer_t * htim2;
esp_timer_handle_t htim2;

// hw_timer_t * timer = NULL;
#define TAG "YOUR_MODULE_NAME"

#define CS_PIN1 GPIO_NUM_4
#define CS_PIN2 GPIO_NUM_16
#define CS_PIN3 GPIO_NUM_15
#define CS_PIN4 GPIO_NUM_32

#define VSPI_DMA_CHAN    2 //Define the DMA channel to be 2
#define HSPI_DMA_CHAN    1 //Define the DMA channel to be 2

// #define PIN_NUM_MOSI 23 //Define the GPIO number for MOSI pin
// #define PIN_NUM_MISO 19 //Define the GPIO number for MISO pin
// #define PIN_NUM_CLK  18 //Define the GPIO number for SCLK pin
// #define PIN_NUM_CS0  16 //Define the GPIO number for CS0 pin
// #define PIN_NUM_CS1   6 //Define the GPIO number for CS1 pin

#define ALTERNATE_PINS

#ifdef ALTERNATE_PINS
  #define VSPI_MISO   19
  #define VSPI_MOSI   18
  #define VSPI_SCLK   17
  #define VSPI_SS     15

  #define HSPI_MISO   27
  #define HSPI_MOSI   12
  #define HSPI_SCLK   14
  #define HSPI_SS     4
#else
  #define VSPI_MISO   MISO
  #define VSPI_MOSI   MOSI
  #define VSPI_SCLK   SCK
  #define VSPI_SS     SS

  #define HSPI_MISO   12
  #define HSPI_MOSI   13
  #define HSPI_SCLK   14
  #define HSPI_SS     15
#endif







#define NB_CHANNELS (3)

uint16_t index_b;

spi_device_handle_t spi0;
spi_device_handle_t spi1;
spi_device_handle_t spi2;
spi_device_handle_t spi3;


/********************************************************
*					    VARIABLES
********************************************************/
volatile uint64_t timer2DefaultPeriod = 0;
volatile uint64_t timerCurrPeriod = 0;
volatile uint64_t timer2NewPeriod = 0;
bool first = true;
bool st = false;
// static void advSensingInit(uint8_t channel);


void HAL_TIM_PeriodElapsedCallback(void* arg);


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
// void SystemClock_Config(void);
// static void MX_GPIO_Init(void);
// static void MX_TIM2_Init(void);
// static void MX_SPI1_Init(void);
// static void MX_I2C1_Init(void);
// static void MX_SPI4_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/********************************************************
*						MAIN
********************************************************/

/* USER CODE END 0 */

extern "C" { void app_main(); }

/**
  * @brief System Clock Configuration
  * @retval None
  */
// void SystemClock_Config(void)
// {
//   RCC_OscInitTypeDef RCC_OscInitStruct = {0};
//   RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

//   /** Configure the main internal regulator output voltage
//   */
//   __HAL_RCC_PWR_CLK_ENABLE();
//   __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
//   /** Initializes the RCC Oscillators according to the specified parameters
//   * in the RCC_OscInitTypeDef structure.
//   */
//   RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
//   RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
//   RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
//   RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
//   RCC_OscInitStruct.PLL.PLLM = 6;
//   RCC_OscInitStruct.PLL.PLLN = 96;
//   RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
//   RCC_OscInitStruct.PLL.PLLQ = 2;
//   RCC_OscInitStruct.PLL.PLLR = 2;
//   if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
//   {
//     Error_Handler();
//   }
//   /** Initializes the CPU, AHB and APB buses clocks
//   */
//   RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
//                               |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
//   RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
//   RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
//   RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
//   RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

//   if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
//   {
//     Error_Handler();
//   }
// }

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
// static void MX_I2C1_Init(void)
// {

//   /* USER CODE BEGIN I2C1_Init 0 */

//   /* USER CODE END I2C1_Init 0 */

//   /* USER CODE BEGIN I2C1_Init 1 */

//   /* USER CODE END I2C1_Init 1 */
//   hi2c1.Instance = I2C1;
//   hi2c1.Init.ClockSpeed = 50000;
//   hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
//   hi2c1.Init.OwnAddress1 = 0;
//   hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
//   hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
//   hi2c1.Init.OwnAddress2 = 0;
//   hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
//   hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
//   if (HAL_I2C_Init(&hi2c1) != HAL_OK)
//   {
//     Error_Handler();
//   }
//   /* USER CODE BEGIN I2C1_Init 2 */

//   /* USER CODE END I2C1_Init 2 */

// }

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, 1);

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  // hspi1.Instance = SPI1;
  // hspi1.Init.Mode = SPI_MODE_MASTER;
  // hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  // hspi1.Init.DataSize = SPI_DATASIZE_16BIT;
  // hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  // hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  // hspi1.Init.NSS = SPI_NSS_SOFT;
  // hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
  // hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  // hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  // hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  // hspi1.Init.CRCPolynomial = 10;
  // if (HAL_SPI_Init(&hspi1) != HAL_OK)
  // {
  //   Error_Handler();
  // }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */


  //!Arduino Code
  
  // gpio_set_level(CS_PIN1, 1); 
  // // pinMode(HSPI_SS, OUTPUT);
  // hspi1 = new SPIClass(HSPI);
  // hspi1->begin(HSPI_SCLK, HSPI_MISO, HSPI_MOSI, HSPI_SS);


  //!New spi library
  static const int spiClk = 12*1000*1000;
  // static const int spiClk = 20*1000*1000;
  spi_bus_config_t buscfg1={
    .mosi_io_num=HSPI_MOSI, //Set the MOSI pin number
    .miso_io_num=HSPI_MISO, //Set the MISO pin number
    .sclk_io_num=HSPI_SCLK, //Set the SCLK pin number
    .quadwp_io_num=-1, //Set the QUADWP pin number to -1 (not used)
    .quadhd_io_num=-1, //Set the QUADHD pin number to -1 (not used)
    .max_transfer_sz=0 //Set the maximum transfer size in bytes
  };

  spi_device_interface_config_t devcfg0={
    .mode=0,                                //Set the SPI mode to 0
    .clock_speed_hz= spiClk,           //Set the clock speed to 10 MHz
    .spics_io_num=CS_PIN1,              //Set the CS pin number for chip select 0
    .queue_size=7,                          //Set the queue size to 7
  };

  spi_device_interface_config_t devcfg1={
    .mode=0,                                //Set the SPI mode to 0
    .clock_speed_hz= spiClk,           //Set the clock speed to 12 MHz
    .spics_io_num=CS_PIN2,              //Set the CS pin number for chip select 0
    .queue_size=7,                          //Set the queue size to 7
  };

  // spi_device_handle_t spi0;
  //Initialize the SPI devices
  gpio_set_level(CS_PIN1, 1); 
  gpio_set_level(CS_PIN2, 1); 
  esp_err_t ret=spi_bus_initialize(SPI2_HOST, &buscfg1, HSPI_DMA_CHAN); //Initialize the SPI bus with the given configuration and DMA channel
  assert(ret==ESP_OK); //Check if the initialization was successful
  ret=spi_bus_add_device(SPI2_HOST, &devcfg0, &spi0); //Add a device to the SPI bus with the given configuration and get a handle for it (chip select 0)
  ret=spi_bus_add_device(SPI2_HOST, &devcfg1, &spi1); //Add a device to the SPI bus with the given configuration and get a handle for it (chip select 0)
  assert(ret==ESP_OK); //Check if adding device was successful

  

}

/**
  * @brief SPI4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI4_Init(void)
{

  /* USER CODE BEGIN SPI4_Init 0 */

  /* USER CODE END SPI4_Init 0 */

  /* USER CODE BEGIN SPI4_Init 1 */

  /* USER CODE END SPI4_Init 1 */
  /* SPI4 parameter configuration*/
  // hspi4.Instance = SPI4;
  // hspi4.Init.Mode = SPI_MODE_MASTER;
  // hspi4.Init.Direction = SPI_DIRECTION_2LINES;
  // hspi4.Init.DataSize = SPI_DATASIZE_16BIT;
  // hspi4.Init.CLKPolarity = SPI_POLARITY_LOW;
  // hspi4.Init.CLKPhase = SPI_PHASE_1EDGE;
  // hspi4.Init.NSS = SPI_NSS_SOFT;
  // hspi4.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
  // hspi4.Init.FirstBit = SPI_FIRSTBIT_MSB;
  // hspi4.Init.TIMode = SPI_TIMODE_DISABLE;
  // hspi4.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  // hspi4.Init.CRCPolynomial = 10;
  // if (HAL_SPI_Init(&hspi4) != HAL_OK)
  // {
  //   Error_Handler();
  // }
  /* USER CODE BEGIN SPI4_Init 2 */

  /* USER CODE END SPI4_Init 2 */

  //!Arduino Code
  // static const int spiClk = 12000000;
  // gpio_set_level(CS_PIN2, 1);
  // hspi4 = new SPIClass(VSPI);
  // hspi4->begin(VSPI_SCLK, VSPI_MISO, VSPI_MOSI, VSPI_SS);


// //!New spi library
  //!New spi library
  static const int spiClk = 12*1000*1000;
  // static const int spiClk = 20*1000*1000;
  spi_bus_config_t buscfg2={
    .mosi_io_num=VSPI_MOSI, //Set the MOSI pin number
    .miso_io_num=VSPI_MISO, //Set the MISO pin number
    .sclk_io_num=VSPI_SCLK, //Set the SCLK pin number
    .quadwp_io_num=-1, //Set the QUADWP pin number to -1 (not used)
    .quadhd_io_num=-1, //Set the QUADHD pin number to -1 (not used)
    .max_transfer_sz=0 //Set the maximum transfer size in bytes
  };

  spi_device_interface_config_t devcfg2={
    .mode=0,                                //Set the SPI mode to 0
    .clock_speed_hz= spiClk,           //Set the clock speed to 10 MHz
    .spics_io_num=CS_PIN3,              //Set the CS pin number for chip select 0
    .queue_size=7,                          //Set the queue size to 7
  };

  spi_device_interface_config_t devcfg3={
    .mode=0,                                //Set the SPI mode to 0
    .clock_speed_hz= spiClk,           //Set the clock speed to 12 MHz
    .spics_io_num=CS_PIN4,              //Set the CS pin number for chip select 0
    .queue_size=7,                          //Set the queue size to 7
  };

  // spi_device_handle_t spi0;
  //Initialize the SPI devices
  gpio_set_level(CS_PIN3, 1); 
  gpio_set_level(CS_PIN4, 1); 
  esp_err_t ret=spi_bus_initialize(SPI3_HOST, &buscfg2, VSPI_DMA_CHAN); //Initialize the SPI bus with the given configuration and DMA channel
  assert(ret==ESP_OK); //Check if the initialization was successful
  ret=spi_bus_add_device(SPI3_HOST, &devcfg2, &spi2); //Add a device to the SPI bus with the given configuration and get a handle for it (chip select 0)
  ret=spi_bus_add_device(SPI3_HOST, &devcfg3, &spi3); //Add a device to the SPI bus with the given configuration and get a handle for it (chip select 0)
  assert(ret==ESP_OK); //Check if adding device was successful

  








//   static const int spiClk = 12*1000*1000;
//   // static const int spiClk = 20*1000*1000;
//   spi_bus_config_t buscfg={
//     .mosi_io_num=HSPI_MOSI, //Set the MOSI pin number
//     .miso_io_num=HSPI_MISO, //Set the MISO pin number
//     .sclk_io_num=HSPI_SCLK, //Set the SCLK pin number
//     .quadwp_io_num=-1, //Set the QUADWP pin number to -1 (not used)
//     .quadhd_io_num=-1, //Set the QUADHD pin number to -1 (not used)
//     .max_transfer_sz=0 //Set the maximum transfer size in bytes
//   };

//   spi_device_interface_config_t devcfg0={
//     .mode=0,                                //Set the SPI mode to 0
//     .clock_speed_hz= spiClk,           //Set the clock speed to 10 MHz
//     .spics_io_num=CS_PIN2,              //Set the CS pin number for chip select 0
//     .queue_size=7,                          //Set the queue size to 7
//   };

//   // spi_device_handle_t spi0;
//   //Initialize the SPI devices
//   esp_err_t ret=spi_bus_initialize(SPI_HOST, &buscfg, DMA_CHAN); //Initialize the SPI bus with the given configuration and DMA channel
//   assert(ret==ESP_OK); //Check if the initialization was successful
//   ret=spi_bus_add_device(SPI_HOST, &devcfg0, &spi0); //Add a device to the SPI bus with the given configuration and get a handle for it (chip select 0)
//   assert(ret==ESP_OK); //Check if adding device was successful
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  // TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  // TIM_MasterConfigTypeDef sMasterConfig = {0};

  // /* USER CODE BEGIN TIM2_Init 1 */

  // /* USER CODE END TIM2_Init 1 */
  // htim2.Instance = TIM2;
  // htim2.Init.Prescaler = 96-1;
  // htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  // htim2.Init.Period = 125-1;
  // htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  // htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
//   if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
//   {
//     Error_Handler();
//   }
//   sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
//   if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
//   {
//     Error_Handler();
//   }
//   sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
//   sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
//   if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
//   {
//     Error_Handler();
//   }
//   /* USER CODE BEGIN TIM2_Init 2 */

// #ifdef EXAMPLE_ADVSENSING
//   // set period to 1ms for this example
//   __HAL_TIM_SET_AUTORELOAD(&htim2, ADVSENSING_SAMPLING_PERIOD-1);
// #endif

  // timer2DefaultPeriod = htim2.Init.Period;
  // timer2NewPeriod = timer2DefaultPeriod;
  // timeSetUsIncrement(timer2DefaultPeriod+1);

  /* USER CODE END TIM2_Init 2 */


  // !ESP code

  // * I think that the correct timer frequency is 1 MHz

  // // initialize timer 2 with a prescaler of 80 and a count up mode
  // htim2 = timerBegin(2, 80, true);

  // // set the period or alarm value of timer 2 to 1000
  // timerAlarmWrite(htim2, 500, true);

  // // enable auto-reload mode for timer 2
  // timerSetAutoReload(htim2, true);

  // // attach an interrupt handler function to timer 2
  // timerAttachInterrupt(htim2, &HAL_TIM_PeriodElapsedCallback, true);

  //  // enable the alarm event or interrupt for timer 2
  // timerAlarmEnable(htim2);
  // // vTaskDelay(1000 / portTICK_PERIOD_MS);

  // timer2DefaultPeriod = timerAlarmRead(htim2); // read the current period value
  // timer2NewPeriod = timer2DefaultPeriod; // initialize the new period value


  // ! High precision timer
  esp_timer_handle_t htim2;
  const esp_timer_create_args_t periodic_timer_args = {
        .callback = &HAL_TIM_PeriodElapsedCallback,
        .name = "periodic"
    };
  esp_timer_create(&periodic_timer_args, &htim2);
  timer2DefaultPeriod = 125;
  #ifdef EXAMPLE_ADVSENSING
  // set period to 1ms for this example
      timer2DefaultPeriod = ADVSENSING_SAMPLING_PERIOD;
  #endif
  #ifdef DRIVING_TEST
  // set period to 1ms for this example
      timer2DefaultPeriod = ADVSENSING_SAMPLING_PERIOD;
  #endif
  // timer2DefaultPeriod = 124;
  esp_timer_start_periodic(htim2, timer2DefaultPeriod);
  // esp_timer_get_period(htim2, &timer2DefaultPeriod)
  // uint64_t p = 0;
  // esp_timer_get_period(htim2, &p);
  // printf("\n \n Period: %lld \n",p);
  // timer2DefaultPeriod = esp_timer_get_period(htim2); // read the current period value
  timerCurrPeriod = timer2DefaultPeriod;
  timer2NewPeriod = timer2DefaultPeriod; // initialize the new period value
  timeSetUsIncrement(timer2DefaultPeriod);
  // timeSetUsIncrement(16);
}

// /**
//   * @brief GPIO Initialization Function
//   * @param None
//   * @retval None
//   */
// static void MX_GPIO_Init(void)
// {
//   GPIO_InitTypeDef GPIO_InitStruct = {0};

//   /* GPIO Ports Clock Enable */
//   __HAL_RCC_GPIOB_CLK_ENABLE();
//   __HAL_RCC_GPIOA_CLK_ENABLE();
//   __HAL_RCC_GPIOE_CLK_ENABLE();
//   __HAL_RCC_GPIOC_CLK_ENABLE();
//   __HAL_RCC_GPIOH_CLK_ENABLE();
//   __HAL_RCC_GPIOD_CLK_ENABLE();

//   /*Configure GPIO pin Output Level */
//   HAL_GPIO_WritePin(GPIOA, SS0_Pin|D2blue_Pin, GPIO_PIN_SET);

//   /*Configure GPIO pin Output Level */
//   HAL_GPIO_WritePin(SS1_GPIO_Port, SS1_Pin, GPIO_PIN_SET);

//   /*Configure GPIO pin Output Level */
//   HAL_GPIO_WritePin(GPIOB, IO3out_Pin|IO2out_Pin, GPIO_PIN_RESET);

//   /*Configure GPIO pin Output Level */
//   HAL_GPIO_WritePin(GPIOC, D2green_Pin|D2red_Pin|D1blue_Pin, GPIO_PIN_SET);

//   /*Configure GPIO pin Output Level */
//   HAL_GPIO_WritePin(GPIOD, D1red_Pin|D1green_Pin, GPIO_PIN_SET);

//   /*Configure GPIO pins : IO0in_Pin IO1in_Pin */
//   GPIO_InitStruct.Pin = IO0in_Pin|IO1in_Pin;
//   GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
//   GPIO_InitStruct.Pull = GPIO_NOPULL;
//   HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

//   /*Configure GPIO pin : SS0_Pin */
//   GPIO_InitStruct.Pin = SS0_Pin;
//   GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//   GPIO_InitStruct.Pull = GPIO_NOPULL;
//   GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//   HAL_GPIO_Init(SS0_GPIO_Port, &GPIO_InitStruct);

//   /*Configure GPIO pin : SS1_Pin */
//   GPIO_InitStruct.Pin = SS1_Pin;
//   GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//   GPIO_InitStruct.Pull = GPIO_NOPULL;
//   GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//   HAL_GPIO_Init(SS1_GPIO_Port, &GPIO_InitStruct);

//   /*Configure GPIO pins : IO3out_Pin IO2out_Pin */
//   GPIO_InitStruct.Pin = IO3out_Pin|IO2out_Pin;
//   GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//   GPIO_InitStruct.Pull = GPIO_NOPULL;
//   GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//   HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

//   /*Configure GPIO pin : D2blue_Pin */
//   GPIO_InitStruct.Pin = D2blue_Pin;
//   GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//   GPIO_InitStruct.Pull = GPIO_NOPULL;
//   GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//   HAL_GPIO_Init(D2blue_GPIO_Port, &GPIO_InitStruct);

//   /*Configure GPIO pins : D2green_Pin D2red_Pin D1blue_Pin */
//   GPIO_InitStruct.Pin = D2green_Pin|D2red_Pin|D1blue_Pin;
//   GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//   GPIO_InitStruct.Pull = GPIO_NOPULL;
//   GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//   HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

//   /*Configure GPIO pins : D1red_Pin D1green_Pin */
//   GPIO_InitStruct.Pin = D1red_Pin|D1green_Pin;
//   GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//   GPIO_InitStruct.Pull = GPIO_NOPULL;
//   GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//   HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

// }

// /* USER CODE BEGIN 4 */

// void HAL_TIM_PeriodElapsedCallback(hw_timer_t* htim)
// {
// 	timeSetTimerFlag();
// 	// timer period change requested
// 	if(htim->Init.Period != timer2NewPeriod)
// 	{
// 		__HAL_TIM_SET_AUTORELOAD(htim, timer2NewPeriod);
// 		timeSetUsIncrement(timer2NewPeriod+1);
// 	}
// }

// void HAL_TIM_PeriodElapsedCallback() {
//   // check if the interrupt source is timer 2
//   // if (htim2 == htim2) {
//   // printf("timer done\n");
//   timeSetTimerFlag(); // set a flag for some purpose
//   // check if the period change is requested
//   if (timerAlarmReadMicros(htim2) != timer2NewPeriod) {
//     // set the new period or alarm value for timer 2
//     timerAlarmWrite(htim2, timer2NewPeriod, true);
//     timeSetUsIncrement(timer2NewPeriod + 1); // set some increment value based on the new period
//   }
//   // }
// }

void HAL_TIM_PeriodElapsedCallback(void * arg) {
  // check if the interrupt source is timer 2
  // if (htim2 == htim2) {
  // printf("timer done\n");
  timeSetTimerFlag(); // set a flag for some purpose
  int64_t time_since_boot = esp_timer_get_time();
  // printf("perdiod done, time since boot: %lld\n\n", time_since_boot);
  // // check if the period change is requested
  // // esp_timer_get_period(htim2, &period_store)
  // printf("timer next alarm: %lld \n\n", esp_timer_get_next_alarm());
  // printf("old period: %lld\n\n ", timer2NewPeriod);
  // printf("new period: %lld\n\n ", timerCurrPeriod);
  if (timerCurrPeriod != timer2NewPeriod) {
    printf("\n\n\nperiod changed\n\n\n");
    // set the new period or alarm value for timer 2
    // esp_timer_restart(htim2, timer2NewPeriod);
    // printf("new period: %lld\n\n ", timer2NewPeriod);

    esp_timer_stop(htim2);

    esp_timer_start_periodic(htim2, timer2NewPeriod);
    timerCurrPeriod = timer2NewPeriod;
    timeSetUsIncrement(timer2NewPeriod); // set some increment value based on the new period
  }
  // }
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
// void Error_Handler(void)
// {
//   /* USER CODE BEGIN Error_Handler_Debug */
//   /* User can add his own implementation to report the HAL error return state */
//   __disable_irq();
//   while (1)
//   {
//   }
//   /* USER CODE END Error_Handler_Debug */
// }

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
/**
  * @brief  The application entry point.
  * @retval int
  */


const int MAX_JSONS = 10;

void splitAndParseJsons(const std::string& str, rapidjson::Document (&docs)[MAX_JSONS]) {
    std::size_t prev = 0, pos = 0;
    int i = 0;

    while ((pos = str.find("}{", prev)) != std::string::npos && i < MAX_JSONS) {
        std::string jsonString = str.substr(prev, pos-prev+1);
        prev = pos + 1;

        docs[i].Parse(jsonString.c_str());
        i++;
    }

    // Last JSON object
    std::string jsonString = str.substr(prev, std::string::npos);
    docs[i].Parse(jsonString.c_str());
}

void stop () {
  check = true;
  st = true;
  sense = false;
  for (int i = 0; i < sizeof(fingersDriving); i++) {
        fingersDriving[i] = 0;
  }
}

bool arrayIsAllZeros(uint8_t array[], int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] != 0) {
            return false;
        }
    }
    return true;
}

std::string trim(const std::string &s) {
    auto wsfront = std::find_if_not(s.begin(), s.end(), [](int c){ return std::isspace(c); });
    auto wsback = std::find_if_not(s.rbegin(), s.rend(), [](int c){ return std::isspace(c); }).base();
    return (wsback <= wsfront ? std::string() : std::string(wsfront, wsback));
}

// std::vector<rapidjson::Document> splitAndParseJsons(const std::string& str) {
//     std::vector<rapidjson::Document> docs;
//     std::size_t prev = 0, pos = 0;

//     while ((pos = str.find("}{", prev)) != std::string::npos) {
//         std::string jsonString = str.substr(prev, pos-prev+1);
//         prev = pos + 1;

//         rapidjson::Document d;
//         d.Parse(jsonString.c_str());
//         docs.push_back(d);
//     }

//     // Last JSON object
//     std::string jsonString = str.substr(prev, std::string::npos);
//     rapidjson::Document d;
//     d.Parse(jsonString.c_str());
//     docs.push_back(d);

//     return docs;
// }


void callFunctionBasedOnJson(const std::string& json) {
    rapidjson::Document d;
    d.Parse(json.c_str());

    std::map<std::string, WaveformType> waveformTypeMap = {
        {"SINE", SINE},
        {"SQUARE", SQUARE},
        {"TRIANGLE", TRIANGLE},
        {"SAWTOOTH", SAWTOOTH}
        // Add more mappings here...
    };

    if (!d.IsObject()) {
      printf("d isn't an object\n");
      return;
    }

    if (d.HasMember("functionName") && d["functionName"].IsString()) {
        std::string functionName = d["functionName"].GetString();
        // printf("inside functionName\n\n");

        if (functionName == "drive" && d.HasMember("args") && d["args"].IsArray()) {

            const rapidjson::Value& args = d["args"];
            if (args.Size() == 3 && args[0].IsInt() && args[1].IsInt() && args[2].IsString()) {
                std::string waveformTypeString = args[2].GetString();
                if (waveformTypeMap.count(waveformTypeString) > 0) {
                    int64_t timeBeforeDrive = esp_timer_get_time();
                    drive(args[0].GetUint(), args[1].GetUint(), waveformTypeMap[waveformTypeString]);
                    printf("Drive: %lld\n\n", esp_timer_get_time() - timeBeforeDrive);  
                }
            }


            if (d.HasMember("fingerToActivate") && d["fingerToActivate"].IsInt()) {
                int fingerToActivate = d["fingerToActivate"].GetInt();
                fingersDriving[fingerToActivate] = 1;
            }
          
            first = false;
            check = false; 
            st = false;
            // BTSerial.println("vibrating");
        }

        else if (functionName == "stopDriving" && d.HasMember("fingerToStop") && d["fingerToStop"].IsInt()) {
          int fingerToStop = d["fingerToStop"].GetInt();
          fingersDriving[fingerToStop] = 0;

          if (arrayIsAllZeros(fingersDriving, sizeof(fingersDriving))) {
            stop();
          }
        } 

        else if (functionName == "stopSensing" ) {
          printf("Stopped sensing mode\n");
          stop();
        } 

        else if (functionName == "sense") {
          printf("Entered sensing mode\n");
          sense = true;
          first = false;
          check = false; 
          st = false;
          for (int i = 0; i < NB_CHANNELS; i++) {
              fingersDriving[i] = 1;
          }
          drive(50, 1, SINE);
        }
    }
}

void esp_spp_cb(esp_spp_cb_event_t event, esp_spp_cb_param_t *param) {
    switch (event) {
    case ESP_SPP_INIT_EVT:
        ESP_LOGI(TAG, "ESP_SPP_INIT_EVT");
        break;
        
    case ESP_SPP_SRV_OPEN_EVT:
        ESP_LOGI(TAG, "ESP_SPP_SRV_OPEN_EVT");
        handle = param->srv_open.handle;
        break;
        
    case ESP_SPP_DATA_IND_EVT:  // This event indicates that there's incoming data.
        ESP_LOGI(TAG, "ESP_SPP_DATA_IND_EVT");
        {
            uint8_t* buffer = param->data_ind.data;  // Data buffer
            int len = param->data_ind.len;  // Length of received data

            // find the '}' character to delimit the JSON message
            int endIndex = -1;
            for (int j = 0; j < len; j++) {
                if (buffer[j] == '}') {
                    endIndex = j;
                    break;
                }
            }

            if (endIndex != -1) {
                buffer[endIndex + 1] = '\0';  // null-terminate the string
                std::string data = std::string((char*)buffer);
                data = trim(data);
                printf("\n\nReceive: %s\n\n", data.c_str());
                callFunctionBasedOnJson(data.c_str());
            }
        }
        break;

    // Add cases for other events as required...
    
    default:
        ESP_LOGI(TAG, "Unhandled event %d", event);
        break;
    }
}


void bt_setup(void) {
    esp_bt_controller_config_t bt_cfg = BT_CONTROLLER_INIT_CONFIG_DEFAULT();
    esp_bt_controller_init(&bt_cfg);
    esp_bt_controller_enable(ESP_BT_MODE_CLASSIC_BT);
    esp_bluedroid_init();
    esp_bluedroid_enable();
    
    esp_bt_dev_set_device_name(BT_DEVICE_NAME);
    esp_spp_register_callback(esp_spp_cb);
    esp_spp_init(esp_spp_mode);
    esp_bt_gap_set_scan_mode(ESP_BT_CONNECTABLE, ESP_BT_GENERAL_DISCOVERABLE);
    esp_spp_start_srv(sec_mask, role_slave, 0, SPP_SERVER_NAME);
}


void bt_read_send(void) {
    printf("\n\ninside bt_read_send\n\n");
    for (uint8_t i = 0; i < NB_CHANNELS; i++) {
        advSensingInit(i);
    }
    int i = 0;
    check = true;

    while (true) {
        if (i == 1) printf("inside while \n");
        
        // Since we removed the data reading from this function (as it's now in the callback),
        // you can proceed with other tasks directly.

        if (!st) { // Assuming "st" checks if we should stop or not
            check = false;
        }

        while (!check && !first) {  // Assuming "first" checks if it's the initial loop or not
            advSensingExecuteSensing(); // Execute sensing
            vTaskDelay(1);  // Short delay
        }

        // Send updates based on button states:
        if (press) {
            char str[40];
            sprintf(str, "{\"press\": true, \"fingerSensing\": %u}", fingerSensing);
            esp_spp_write(handle, strlen(str), (uint8_t*)str);
            press = false;  // Reset the press flag
        }

        if (release) {
            char str[40];
            sprintf(str, "{\"press\": false, \"fingerSensing\": %u}", fingerSensing);
            esp_spp_write(handle, strlen(str), (uint8_t*)str);
            release = false;  // Reset the release flag
        }

        // Send a newline periodically (every 10 iterations in this case):
        if (i % 10 == 0) {
            esp_spp_write(handle, 1, (uint8_t*)"\n");
        }

        i++;
        vTaskDelay(1);  // Short delay
    }
}



// add button press mode and possible button press during viberation;

void app_main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  // HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  // SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  // MX_GPIO_Init();
  esp_err_t ret;

  // Initialize NVS
  ret = nvs_flash_init();
  if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      // NVS partition was truncated and needs to be erased
      // Retry nvs_flash_init
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
  }
    ESP_ERROR_CHECK( ret );
  MX_TIM2_Init();
  MX_SPI1_Init();
  // MX_I2C1_Init();
  MX_SPI4_Init();
  /* USER CODE BEGIN 2 */

  // HAL_TIM_Base_Start_IT(&htim2);

    // spiInit();		    // Init SPI Configuration
    // ioExpanderConfig(); // Init IoExpander for BOS1901 channel LEDs

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

    // colors testing
	// ledExWrite(LEDEX_D1, color_green);

	// run example code
	// example();
  // drive(50, 1, SINE); // freq, cycles, waveformType

  // setCpuFrequencyMhz(80);
  // printf("\n\n Cpus speed: %i \n\n", getCpuFrequencyMhz());

  bt_setup();
  bt_read_send();

  // std::string json = R"({"functionName":"drive","args":[50,1,"SINE"]})";
  // callFunctionBasedOnJson(json);

  // #define VSPI_MISO   MISO
  // #define VSPI_MOSI   MOSI
  // #define VSPI_SCLK   SCK
  // printf("\n\n something\n\n");
  // printf("\n\n\nSS: %d", SS); 
  // printf("\n\n\nMOSI: %d", MOSI);
  // printf("\n\n\nSS: %d", SS) ; 
  // printf("\n\n\nMISO: %d", MISO);
  // printf("\n\n\nSCK: %d", SCK); 
  // printf("\n\n\nSCK: %d", SCK); 
  // for(;;) {
  //   spiReadWriteReg(0, 0xc000);
  // }
  // spiReadWriteReg(0, 0xc000);
  // spiReadWriteReg(0, 0xc000);
  // spiReadWriteReg(0, 0x5121);
  // spiReadWriteReg(0, 0x5697);

	/* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

  /* USER CODE END 3 */

  //* Experimenting with driving:
  // driving_test();
 
}

// use the bluetooth serial app to time each send and receive time and then use
// a timer inside esp32 to find what block of code is taking too much time
// In addition, consider changing the fingers before calling drive in the json
// note that for sensing right now where limiting the loop to 2 instead of all fingers so that no errors happen
// Most of the delay is caused by the time to calculate waveforms, the size of the array is bigger for lower frequencies and is taking more time to calcuare
// The higher the frequency, the lower the number of sample per cycle is, the smaller the array is
// It takes more time to vibrate after waiting a while because bluetooth enters mode 2 which means it's in stand by mode
// Right now, init only works for two fingers because it's hardcoded for two fingers
// Changing #define SIG_SIZE_MAX from (1024 * 4) to (1024) signficantly reduced memory usage