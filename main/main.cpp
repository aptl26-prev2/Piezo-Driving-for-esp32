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
#include <stdio.h>

#include "example.h"
// #include 

#include "driver/spi_master.h"
#include "spi.h"
#include "ledEx.h"
#include "gpioEx.h"
#include "timeEx.h"
#include "../components/arduino/tools/sdk/esp32c3/include/driver/include/driver/gpio.h"
#include "../components/arduino/libraries/spi/src/SPI.h"
// #include "esp32-hal-timer.h"
#include "esp_log.h"
#include "esp_check.h"
#include "esp_err.h"
#include "esp_timer.h"
#include "math.h"
#include "BluetoothSerial.h"
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
BluetoothSerial BTSerial;

SPIClass * hspi1 = NULL;
SPIClass * hspi4 = NULL;

// declare a pointer to a hw_timer_t structure
// hw_timer_t * htim2;
esp_timer_handle_t htim2;

// hw_timer_t * timer = NULL;

#define CS_PIN1 GPIO_NUM_4
#define CS_PIN2 GPIO_NUM_16

#define SPI_HOST    HSPI_HOST //Define the SPI host to be HSPI
#define DMA_CHAN    2 //Define the DMA channel to be 2

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
  #define VSPI_SS     16

  #define HSPI_MISO   13
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


//* Experiments for driving
#define MAX_FIFO_SPACE		(64)
#define REFERENCE_PLUS_1LSB					(0x0001)
#define REFERENCE_MINUS_1LSB				(0x0FFF)
#define SUP_RISE_SENSE_BIT_ON  (0x1 << 11)
#define SENSING_RELEASE_DETECT_VAL	    (REFERENCE_MINUS_1LSB) // REFERENCE CODE
#define PIEZO_RELAXATION_TIME_SENSING_SETUP_MS  (20) 

uint16_t index_b;

spi_device_handle_t spi0;
spi_device_handle_t spi1;


/********************************************************
*					    VARIABLES
********************************************************/
volatile uint64_t timer2DefaultPeriod = 0;
volatile uint64_t timerCurrPeriod = 0;
volatile uint64_t timer2NewPeriod = 0;
bool first = true;
bool st = false;


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
  spi_bus_config_t buscfg={
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
    .clock_speed_hz= spiClk,           //Set the clock speed to 10 MHz
    .spics_io_num=CS_PIN2,              //Set the CS pin number for chip select 0
    .queue_size=7,                          //Set the queue size to 7
  };

  // spi_device_handle_t spi0;
  //Initialize the SPI devices
  gpio_set_level(CS_PIN2, 1); 
  esp_err_t ret=spi_bus_initialize(SPI_HOST, &buscfg, DMA_CHAN); //Initialize the SPI bus with the given configuration and DMA channel
  assert(ret==ESP_OK); //Check if the initialization was successful
  ret=spi_bus_add_device(SPI_HOST, &devcfg0, &spi0); //Add a device to the SPI bus with the given configuration and get a handle for it (chip select 0)
  ret=spi_bus_add_device(SPI_HOST, &devcfg1, &spi1); //Add a device to the SPI bus with the given configuration and get a handle for it (chip select 0)
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



 //* Experiments for driving
static int16_t advSensingVolt2Amplitude(float volt)
{
    int16_t amplitude = volt*2047/3.6/31;

    return amplitude & 0x0FFF;
}
static uint8_t advSensingGetFifoSpace(uint8_t channel)
{
    uint8_t fifospace = 0;
    uint16_t wReg = 0;

    //Set up broadcast to read IC_STATUS
    wReg = 0x5617;
    spiReadWriteReg(channel, wReg);  // Set BC = IC_STATUS
	timeWaitUs(10);
	wReg = 0xC000;
	uint16_t ic_status_reg = spiReadWriteReg(channel, wReg); // dummy write, get IC_STATUS value
	fifospace = ic_status_reg & 0x7F; // extract EMPTY & FIFO_SPACE value.

    return fifospace;
}
static void advSensingWaitFifoEmpty(uint8_t channel)
{
    bool fifoempty = 0;
    uint16_t wReg = 0;

    //Set up broadcast to read IC_STATUS
    wReg = 0x5617;
    spiReadWriteReg(channel, wReg);  // Set BC = IC_STATUS

    // loop until FIFO is empty
    while(!fifoempty)
    {
        timeWaitUs(10);
        wReg = 0xC000;
        uint16_t ic_status_reg = spiReadWriteReg(channel, wReg); // dummy write, get IC_STATUS value
        fifoempty = (ic_status_reg >> 6) & 0x1; // extract EMPTY value.
    }
}

static void advSensingCalculateWaveform(uint16_t* table, uint16_t* size, float vMax, float vMin, uint16_t freq, uint8_t cycles)
{
    float amplitude = (vMax - vMin)/2;
    float offset = (vMax + vMin)/2;
    uint16_t samplingRateHz = PLAY_SAMPLING_RATE;
    uint16_t nbrOfSamplePerCycle = round(samplingRateHz / (float) freq);
    double theta0 = 2 * M_PI / nbrOfSamplePerCycle;
    float phaseShift;
    uint16_t endVal;
    
    // calculate phase
    if (vMin >= 0)
    {
        phaseShift = -M_PI;
        endVal = REFERENCE_MINUS_1LSB;
    }
    else if (vMax <= 0)
    {
        phaseShift = 0;
        endVal = REFERENCE_PLUS_1LSB;
    }
    else
    {
        phaseShift = -M_PI - acosf(fabsf(offset) / amplitude);
        endVal = fabsf(vMax) > fabsf(vMin) ? REFERENCE_MINUS_1LSB : REFERENCE_PLUS_1LSB;
    }

    *size = nbrOfSamplePerCycle * cycles;
    for(uint16_t i = 0; i < *size; i++)
    {
        table[i] = advSensingVolt2Amplitude( (vMax - vMin) / 2 * cos((double)(theta0*i + phaseShift)) + (vMax + vMin)/2 );
    }
    // ending value
    (*size)++;
    table[(*size)-1] = endVal;
}

static bool advSensingPlayWaveformNonBlocking(uint8_t channel, uint16_t* waveform, uint16_t size)
{
	bool res = false;

	// first entry
	if(index_b == 0)
	{
	    advSensingWaitFifoEmpty(channel); // wait until BOS1901 internal FIFO is empty before sending the waveform to make sure we can write 64 points.
	    spiReadWriteReg(channel, 0x77E7);  // set SENSE = 0 to drive the output
	}

    // fill FIFO with table values, wait if more than 64 points sent
	uint16_t fifospace = advSensingGetFifoSpace(channel);

    // waveform all programmed
    if(index_b == size)
    {
    	// waveform finished playing
    	if(fifospace == MAX_FIFO_SPACE)
    	{
            index_b = 0;
            res = true;
    	}
    }
    else
    {
    	uint16_t sendSize = fifospace <= (size - index_b) ? fifospace : (size - index_b);

    	for(int8_t i = 0; i < sendSize; i++)
    	{
        	spiReadWriteReg(channel, waveform[index_b]);
        	index_b++;
    	}
    }

    return res;
}

void driving_test(void) {
  //  software reset
     spiReadWriteReg(0, 0x5427);

    uint16_t press_waveform[1024];
    uint16_t press_waveform_size;
    uint16_t press_stab_waveform[1024];   // Press stabilization waveform data points
  	uint16_t press_stab_waveform_size;         
    uint16_t relaxTimeStartUs = 0 ;
    advSensingCalculateWaveform(press_waveform, &press_waveform_size, 90, -10, 500, 10);
    advSensingCalculateWaveform(press_stab_waveform, &press_stab_waveform_size, 0, -5, 500, 1);
    advSensingPlayWaveformNonBlocking(0, press_waveform, press_waveform_size);
    if(relaxTimeStartUs == 0)
    {
      // waveform done
      if(advSensingPlayWaveformNonBlocking(0, press_stab_waveform, press_stab_waveform_size))
      {
          // disable then enable output (avoid zero-crossing potential issue)
          spiReadWriteReg(0, 0x5687); // disable output
          spiReadWriteReg(0, 0x77E7 | SUP_RISE_SENSE_BIT_ON); // SENSE = 1,VDD = 11111,TI_RISE = 0x27
          spiReadWriteReg(0, SENSING_RELEASE_DETECT_VAL);  // write 0x0001 to set the bridge to positive polarity
          spiReadWriteReg(0, 0x5697); // enable output

          relaxTimeStartUs = timeGetUsCounter();
      }
    }
    // wait relaxation time
    else
    {
      if(timeGetUsCounter() > relaxTimeStartUs + PIEZO_RELAXATION_TIME_SENSING_SETUP_MS*1000)
      {
        relaxTimeStartUs = 0;
        // advSensingNextState(channel); // to go next phase
      }
    }
  
}

void stop () {
  check = true;
  st = true;
}


void callFunctionBasedOnJson(const std::string& json) {
    rapidjson::Document d;
    d.Parse(json.c_str());

    std::map<std::string, WaveformType> waveformTypeMap = {
        {"SINE", SINE},
        {"SQUARE", SQUARE},
        {"TRIANGLE", TRIANGLE}
        // Add more mappings here...
    };

    if (!d.IsObject()) {
      printf("d isn't an object\n");
    }

    if (d.HasMember("functionName") && d["functionName"].IsString()) {
        std::string functionName = d["functionName"].GetString();

        if (functionName == "drive" && d.HasMember("args") && d["args"].IsArray()) {
            const rapidjson::Value& args = d["args"];
            if (args.Size() == 3 && args[0].IsInt() && args[1].IsInt() && args[2].IsString()) {
                std::string waveformTypeString = args[2].GetString();
                if (waveformTypeMap.count(waveformTypeString) > 0) {
                    drive(args[0].GetUint(), args[1].GetUint(), waveformTypeMap[waveformTypeString]);
                }
            }
          
          first = false;
          check = false; 
          st = false;
        }

        else if (functionName == "stop") {
          printf("inside elif\n");
          stop();
        } 

        else if (functionName == "sense") {
          sense = true;
          first = false;
          check = false; 
          st = false;
        }
    }
}


 void bt_setup(void) {
  BTSerial.begin("HC-05");
}

void bt_read_send(void) {
  check = true;
  while (true) {
    // printf("inside outer while; \n");
    if (BTSerial.available()) {
      String data = BTSerial.readStringUntil('\n');
      
      printf("Reciecve: %s\n", data.c_str());
      callFunctionBasedOnJson(data.c_str());
    }
    
    else if (!st) {
      check = false;
    }

    while (!check && !first) {
      // printf("inside inner while; \n");
      advSensingExecuteSensing();
      vTaskDelay(1);
    } 

    if (press) {
      BTSerial.println("{\"press\": true}");
      press = false;
    }

    if (release) {
      BTSerial.println("{\"release\": true}");
      release = false;
    }

    vTaskDelay(1);
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
