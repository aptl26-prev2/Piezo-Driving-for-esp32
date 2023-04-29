/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
// #include "stm32f4xx_hal.h"
#include "../components/arduino/libraries/spi/src/SPI.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
// #define IO0in_Pin GPIO_PIN_4
// #define IO0in_GPIO_Port GPIOB
// #define SS0_Pin GPIO_PIN_15
// #define SS0_GPIO_Port GPIOA
// #define SS1_Pin GPIO_PIN_4
// #define SS1_GPIO_Port GPIOE
// #define IO3out_Pin GPIO_PIN_7
// #define IO3out_GPIO_Port GPIOB
// #define IO2out_Pin GPIO_PIN_6
// #define IO2out_GPIO_Port GPIOB
// #define IO1in_Pin GPIO_PIN_5
// #define IO1in_GPIO_Port GPIOB
// #define D2blue_Pin GPIO_PIN_10
// #define D2blue_GPIO_Port GPIOA
// #define D2green_Pin GPIO_PIN_9
// #define D2green_GPIO_Port GPIOC
// #define D2red_Pin GPIO_PIN_7
// #define D2red_GPIO_Port GPIOC
// #define D1blue_Pin GPIO_PIN_6
// #define D1blue_GPIO_Port GPIOC
// #define D1red_Pin GPIO_PIN_14
// #define D1red_GPIO_Port GPIOD
// #define D1green_Pin GPIO_PIN_13
// #define D1green_GPIO_Port GPIOD
/* USER CODE BEGIN Private defines */
#define SAMPLING_RATE	(8000)
#define PLAY_SAMPLING_RATE (8000)
#define ADVSENSING_SAMPLING_RATE (1000)
#define ADVSENSING_SAMPLING_PERIOD (ADVSENSING_SAMPLING_RATE-1)

// UNCOMMENT AN EXAMPLE LINE TO COMPILE IT.

// Button emulation example, sensing on press and release, feedback output managed using FIFO.
// This example is referenced in Application Note on Sensing.
// Use this example to get basic understanding of sensing.
//#define EXAMPLE_SENSING

// Button emulation example, sensing on press and release, feedback output managed by the MCU.
// This example is referenced in Application Note on Driving.
// It shows a different output method to play waveforms, one used when synchronization between BOS1901
// and MCU or other BOS1901 is required.
//#define EXAMPLE_DRIVING

// Button emulation example, sensing on press and release, feedback output managed by the FIFO,
// detection using a combination of threshold and slope methods, filtered VFEEDBACK measurements,
// negative stabilization after waveforms.
// This example contains the latest improvements to sensing and stabilizing the piezo actuator.
// It is the go-to example for the best button experience.
// #define EXAMPLE_SENSING
#define EXAMPLE_DRIVING

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
