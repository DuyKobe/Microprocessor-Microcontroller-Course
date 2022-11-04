/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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
#define L0_Pin GPIO_PIN_4
#define L0_GPIO_Port GPIOA
#define L1_Pin GPIO_PIN_5
#define L1_GPIO_Port GPIOA
#define L2_Pin GPIO_PIN_6
#define L2_GPIO_Port GPIOA
#define L3_Pin GPIO_PIN_7
#define L3_GPIO_Port GPIOA
#define L4_Pin GPIO_PIN_8
#define L4_GPIO_Port GPIOA
#define L5_Pin GPIO_PIN_9
#define L5_GPIO_Port GPIOA
#define L6_Pin GPIO_PIN_10
#define L6_GPIO_Port GPIOA
#define L7_Pin GPIO_PIN_11
#define L7_GPIO_Port GPIOA
#define L8_Pin GPIO_PIN_12
#define L8_GPIO_Port GPIOA
#define L9_Pin GPIO_PIN_13
#define L9_GPIO_Port GPIOA
#define L10_Pin GPIO_PIN_14
#define L10_GPIO_Port GPIOA
#define L11_Pin GPIO_PIN_15
#define L11_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
