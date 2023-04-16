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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */


#include <stdint.h>

#include "example.h"

#include "spi.h"
#include "ledEx.h"
#include "gpioEx.h"
#include "timeEx.h"
#include "../components/arduino/tools/sdk/esp32c3/include/driver/include/driver/gpio.h"
#include "../components/arduino/libraries/spi/src/SPI.h"
#include "esp32-hal-timer.h"

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

SPIClass * hspi1 = NULL;
SPIClass * hspi4 = NULL;

// declare a pointer to a hw_timer_t structure
hw_timer_t * htim2;

// hw_timer_t * timer = NULL;

#define CS_PIN1 GPIO_NUM_5
#define CS_PIN2 GPIO_NUM_16

#define ALTERNATE_PINS

#ifdef ALTERNATE_PINS
  #define VSPI_MISO   2
  #define VSPI_MOSI   4
  #define VSPI_SCLK   0
  #define VSPI_SS     33

  #define HSPI_MISO   19
  #define HSPI_MOSI   23
  #define HSPI_SCLK   18
  #define HSPI_SS     5
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

/********************************************************
*					    VARIABLES
********************************************************/
volatile uint32_t timer2DefaultPeriod = 0;
volatile uint32_t timer2NewPeriod = 0;


void HAL_TIM_PeriodElapsedCallback();
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
  static const int spiClk = 4000000;
  gpio_set_level(CS_PIN1, 1);
  hspi1 = new SPIClass(HSPI);
  hspi1->begin(HSPI_SCLK, HSPI_MISO, HSPI_MOSI, HSPI_SS);


  

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
  static const int spiClk = 4000000;
  gpio_set_level(CS_PIN2, 1);
  hspi4 = new SPIClass(VSPI);
  hspi4->begin(VSPI_SCLK, VSPI_MISO, VSPI_MOSI, VSPI_SS);

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

  // initialize timer 2 with a prescaler of 80 and a count up mode
  htim2 = timerBegin(2, 96, true);

  // set the period or alarm value of timer 2 to 1000
  timerAlarmWrite(htim2, 1000, true);

  // enable auto-reload mode for timer 2
  timerSetAutoReload(htim2, true);

  // attach an interrupt handler function to timer 2
  timerAttachInterrupt(htim2, &HAL_TIM_PeriodElapsedCallback, true);

   // enable the alarm event or interrupt for timer 2
  timerAlarmEnable(htim2);
  // vTaskDelay(1000 / portTICK_PERIOD_MS);

  timer2DefaultPeriod = timerAlarmRead(htim2); // read the current period value
  timer2NewPeriod = timer2DefaultPeriod; // initialize the new period value
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

void HAL_TIM_PeriodElapsedCallback() {
  // check if the interrupt source is timer 2
  // if (htim2 == htim2) {
  timeSetTimerFlag(); // set a flag for some purpose
  // check if the period change is requested
  if (timerAlarmRead(htim2) != timer2NewPeriod) {
    // set the new period or alarm value for timer 2
    timerAlarmWrite(htim2, timer2NewPeriod, true);
    timeSetUsIncrement(timer2NewPeriod + 1); // set some increment value based on the new period
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
	example();

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

  // spiReadWriteReg(0, 0xc000);
  // spiReadWriteReg(0, 0xc000);
  // spiReadWriteReg(0, 0xc000);
  // spiReadWriteReg(0, 0x5121);
  // spiReadWriteReg(0, 0x5697);

	/* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

  /* USER CODE END 3 */
}
