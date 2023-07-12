/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void clearAllClock()
{
  HAL_GPIO_WritePin(L0_GPIO_Port, L0_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(L7_GPIO_Port, L7_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(L8_GPIO_Port, L8_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(L9_GPIO_Port, L9_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(L10_GPIO_Port, L10_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(L11_GPIO_Port, L11_Pin, GPIO_PIN_SET);
}
void clearNumberOnBlock(int num)
{
  switch (num)
  {
  case 0:
    HAL_GPIO_WritePin(L0_GPIO_Port, L0_Pin, GPIO_PIN_SET);
    break;
  case 1:
    HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_SET);
    break;
  case 2:
    HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_SET);
    break;
  case 3:
    HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_SET);
    break;
  case 4:
    HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_SET);
    break;
  case 5:
    HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, GPIO_PIN_SET);
    break;
  case 6:
    HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, GPIO_PIN_SET);
    break;
  case 7:
    HAL_GPIO_WritePin(L7_GPIO_Port, L7_Pin, GPIO_PIN_SET);
    break;
  case 8:
    HAL_GPIO_WritePin(L8_GPIO_Port, L8_Pin, GPIO_PIN_SET);
    break;
  case 9:
    HAL_GPIO_WritePin(L9_GPIO_Port, L9_Pin, GPIO_PIN_SET);
    break;
  case 10:
    HAL_GPIO_WritePin(L10_GPIO_Port, L10_Pin, GPIO_PIN_SET);
    break;
  default:
    HAL_GPIO_WritePin(L11_GPIO_Port, L11_Pin, GPIO_PIN_SET);
  }
}
void setNumberOnBlock(int num)
{
  switch (num)
  {
  case 0:
    HAL_GPIO_WritePin(L0_GPIO_Port, L0_Pin, GPIO_PIN_RESET);
    break;
  case 1:
    HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_RESET);
    break;
  case 2:
    HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_RESET);
    break;
  case 3:
    HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_RESET);
    break;
  case 4:
    HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_RESET);
    break;
  case 5:
    HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, GPIO_PIN_RESET);
    break;
  case 6:
    HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, GPIO_PIN_RESET);
    break;
  case 7:
    HAL_GPIO_WritePin(L7_GPIO_Port, L7_Pin, GPIO_PIN_RESET);
    break;
  case 8:
    HAL_GPIO_WritePin(L8_GPIO_Port, L8_Pin, GPIO_PIN_RESET);
    break;
  case 9:
    HAL_GPIO_WritePin(L9_GPIO_Port, L9_Pin, GPIO_PIN_RESET);
    break;
  case 10:
    HAL_GPIO_WritePin(L10_GPIO_Port, L10_Pin, GPIO_PIN_RESET);
    break;
  default:
    HAL_GPIO_WritePin(L11_GPIO_Port, L11_Pin, GPIO_PIN_RESET);
  }
}
// void setTime(int sec, int min, int hou)
// {
//   clearAllClock();
//   setNumberOnBlock(sec);
//   setNumberOnBlock(min);
//   setNumberOnBlock(hou);
// }
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int sec = -1;
    int min = 0;
    int hou = 0;
  while (1)
  {sec++;
  if (sec >= 12)
  {
    sec = 0;
    min++;
  }
  if (min >= 12)
  {
    min = 0;
    hou++;
  }
  if (hou >= 12)
  {
    hou = 0;
  }
  clearAllClock();
  setNumberOnBlock(sec);
  setNumberOnBlock(min);
  setNumberOnBlock(hou);
  HAL_Delay(5000);
}
//Lab6, test each single led
	// HAL_GPIO_TogglePin(L1_GPIO_Port, L1_Pin);
	// HAL_Delay(1000);
	// HAL_GPIO_TogglePin(L2_GPIO_Port, L2_Pin);
	// HAL_Delay(1000);
	// HAL_GPIO_TogglePin(L3_GPIO_Port, L3_Pin);
	// HAL_Delay(1000);
	// HAL_GPIO_TogglePin(L4_GPIO_Port, L4_Pin);
	// HAL_Delay(1000);
	// HAL_GPIO_TogglePin(L5_GPIO_Port, L5_Pin);
	// HAL_Delay(1000);
	// HAL_GPIO_TogglePin(L6_GPIO_Port, L6_Pin);
	// HAL_Delay(1000);
	// HAL_GPIO_TogglePin(L7_GPIO_Port, L7_Pin);
	// HAL_Delay(1000);
	// HAL_GPIO_TogglePin(L8_GPIO_Port, L8_Pin);
	// HAL_Delay(1000);
	// HAL_GPIO_TogglePin(L9_GPIO_Port, L9_Pin);
	// HAL_Delay(1000);
	// HAL_GPIO_TogglePin(L10_GPIO_Port, L10_Pin);
	// HAL_Delay(1000);
	// HAL_GPIO_TogglePin(L11_GPIO_Port, L11_Pin);
	// HAL_Delay(1000);
	// HAL_GPIO_TogglePin(L12_GPIO_Port, L12_Pin);
	// HAL_Delay(1000);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, L0_Pin|L1_Pin|L2_Pin|L3_Pin
                          |L4_Pin|L5_Pin|L6_Pin|L7_Pin
                          |L8_Pin|L9_Pin|L10_Pin|L11_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : L0_Pin L1_Pin L2_Pin L3_Pin
                           L4_Pin L5_Pin L6_Pin L7_Pin
                           L8_Pin L9_Pin L10_Pin L11_Pin */
  GPIO_InitStruct.Pin = L0_Pin|L1_Pin|L2_Pin|L3_Pin
                          |L4_Pin|L5_Pin|L6_Pin|L7_Pin
                          |L8_Pin|L9_Pin|L10_Pin|L11_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

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
