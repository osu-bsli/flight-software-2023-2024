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
#define GPIO_OUT_A4988_DIR_Pin GPIO_PIN_8
#define GPIO_OUT_A4988_DIR_GPIO_Port GPIOI
#define GPIO_OUT_A4988_SLEEP_Pin GPIO_PIN_13
#define GPIO_OUT_A4988_SLEEP_GPIO_Port GPIOC
#define GPIO_OUT_A4988_RESET_Pin GPIO_PIN_14
#define GPIO_OUT_A4988_RESET_GPIO_Port GPIOC
#define GPIO_OUT_A4988_ENABLE_Pin GPIO_PIN_15
#define GPIO_OUT_A4988_ENABLE_GPIO_Port GPIOC
#define GPIO_EXTI2_MAXM8C_DATAREADY_Pin GPIO_PIN_2
#define GPIO_EXTI2_MAXM8C_DATAREADY_GPIO_Port GPIOF
#define GPIO_EXTI3_BM1422AGMV_DATAREADY_Pin GPIO_PIN_3
#define GPIO_EXTI3_BM1422AGMV_DATAREADY_GPIO_Port GPIOF
#define GPIO_EXTI15_BMI1422AGMV_DATAREADY_Pin GPIO_PIN_15
#define GPIO_EXTI15_BMI1422AGMV_DATAREADY_GPIO_Port GPIOG
#define GPIO_EXTI5_ADXL375_DATAREADY_Pin GPIO_PIN_5
#define GPIO_EXTI5_ADXL375_DATAREADY_GPIO_Port GPIOB
#define GPIO_OUT_A4988_STEP_Pin GPIO_PIN_4
#define GPIO_OUT_A4988_STEP_GPIO_Port GPIOI
#define GPIO_OUT_A4988_MS1_Pin GPIO_PIN_5
#define GPIO_OUT_A4988_MS1_GPIO_Port GPIOI
#define GPIO_OUT_A4988_MS2_Pin GPIO_PIN_6
#define GPIO_OUT_A4988_MS2_GPIO_Port GPIOI
#define GPIO_OUT_A4988_MS3_Pin GPIO_PIN_7
#define GPIO_OUT_A4988_MS3_GPIO_Port GPIOI

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
