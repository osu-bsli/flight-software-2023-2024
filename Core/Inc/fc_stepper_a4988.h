/*
 * fc_adxl375.h
 *
 *  Created on: Sep 24, 2023
 *      Author: bsli
 */

#ifndef INC_FC_ADXL375_H_
#define INC_FC_ADXL375_H_

#include "stm32h7xx_hal.h"


/* Motor step angles */
#define MOTOR_STEP_FULL 		1.8
#define MOTOR_STEP_HALF 		0.9
#define MOTOR_STEP_QUARTER 		0.45
#define MOTOR_STEP_EIGTH		0.225
#define MOTOR_STEP_SIXTEENTH	0.1125

/* Motor step delays */
#define MOTOR_RPS 5
#define MOTOR_DELAY_FULL		1 	/* MOTOR_STEP_FULL/(MOTOR_RPS*360)*1000 miliseconds */
#define MOTOR_DELAY_HALF 		0.5
#define MOTOR_DELAY_QUARTER		0.25
#define MOTOR_DELAY_EIGTH		0.125
#define MOTOR_DELAY_SIXTEENTH	0.0625

#define GPIO_OUT_A4988_DIR_Pin GPIO_PIN_8
#define GPIO_OUT_A4988_DIR_GPIO_Port GPIOI
#define GPIO_OUT_A4988_SLEEP_Pin GPIO_PIN_13
#define GPIO_OUT_A4988_SLEEP_GPIO_Port GPIOC
#define GPIO_OUT_A4988_RESET_Pin GPIO_PIN_14
#define GPIO_OUT_A4988_RESET_GPIO_Port GPIOC
#define GPIO_OUT_A4988_ENABLE_Pin GPIO_PIN_15
#define GPIO_OUT_A4988_ENABLE_GPIO_Port GPIOC

#define GPIO_OUT_A4988_STEP_Pin GPIO_PIN_4
#define GPIO_OUT_A4988_STEP_GPIO_Port GPIOI
#define GPIO_OUT_A4988_MS1_Pin GPIO_PIN_5
#define GPIO_OUT_A4988_MS1_GPIO_Port GPIOI
#define GPIO_OUT_A4988_MS2_Pin GPIO_PIN_6
#define GPIO_OUT_A4988_MS2_GPIO_Port GPIOI
#define GPIO_OUT_A4988_MS3_Pin GPIO_PIN_7
#define GPIO_OUT_A4988_MS3_GPIO_Port GPIOI


float fc_step_motor(float angle);


#endif /* INC_FC_ADXL375_H_ */
