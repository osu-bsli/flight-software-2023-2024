/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

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
#define GPIO_OUT_A4988_5_Pin GPIO_PIN_8
#define GPIO_OUT_A4988_5_GPIO_Port GPIOI
#define GPIO_OUT_A4988_6_Pin GPIO_PIN_13
#define GPIO_OUT_A4988_6_GPIO_Port GPIOC
#define GPIO_OUT_A4988_7_Pin GPIO_PIN_14
#define GPIO_OUT_A4988_7_GPIO_Port GPIOC
#define GPIO_OUT_A4988_8_Pin GPIO_PIN_15
#define GPIO_OUT_A4988_8_GPIO_Port GPIOC
#define GPIO_INTERRUPT_MAXM8C_DATAREADY_Pin GPIO_PIN_2
#define GPIO_INTERRUPT_MAXM8C_DATAREADY_GPIO_Port GPIOF
#define GPIO_INTERRUPT_BM1422AGMV_DATAREADY_Pin GPIO_PIN_3
#define GPIO_INTERRUPT_BM1422AGMV_DATAREADY_GPIO_Port GPIOF
#define GPIO_INTERRUPT_BMI323_DATAREADY_Pin GPIO_PIN_4
#define GPIO_INTERRUPT_BMI323_DATAREADY_GPIO_Port GPIOC
#define GPIO_INTERRUPT_ADXL375_DATAREADY_Pin GPIO_PIN_5
#define GPIO_INTERRUPT_ADXL375_DATAREADY_GPIO_Port GPIOB
#define GPIO_OUT_A4988_1_Pin GPIO_PIN_4
#define GPIO_OUT_A4988_1_GPIO_Port GPIOI
#define GPIO_OUT_A4988_2_Pin GPIO_PIN_5
#define GPIO_OUT_A4988_2_GPIO_Port GPIOI
#define GPIO_OUT_A4988_3_Pin GPIO_PIN_6
#define GPIO_OUT_A4988_3_GPIO_Port GPIOI
#define GPIO_OUT_A4988_4_Pin GPIO_PIN_7
#define GPIO_OUT_A4988_4_GPIO_Port GPIOI

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
