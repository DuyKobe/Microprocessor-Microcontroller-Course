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
#define R0_Pin GPIO_PIN_4
#define R0_GPIO_Port GPIOA
#define Y0_Pin GPIO_PIN_5
#define Y0_GPIO_Port GPIOA
#define G0_Pin GPIO_PIN_6
#define G0_GPIO_Port GPIOA
#define R1_Pin GPIO_PIN_7
#define R1_GPIO_Port GPIOA
#define EN2_Pin GPIO_PIN_14
#define EN2_GPIO_Port GPIOB
#define EN3_Pin GPIO_PIN_15
#define EN3_GPIO_Port GPIOB
#define Y1_Pin GPIO_PIN_8
#define Y1_GPIO_Port GPIOA
#define G1_Pin GPIO_PIN_9
#define G1_GPIO_Port GPIOA
#define MODE_Pin GPIO_PIN_10
#define MODE_GPIO_Port GPIOA
#define INC_Pin GPIO_PIN_11
#define INC_GPIO_Port GPIOA
#define DEC_Pin GPIO_PIN_12
#define DEC_GPIO_Port GPIOA
#define APPLY_Pin GPIO_PIN_13
#define APPLY_GPIO_Port GPIOA
#define EN0_Pin GPIO_PIN_14
#define EN0_GPIO_Port GPIOA
#define EN1_Pin GPIO_PIN_15
#define EN1_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
