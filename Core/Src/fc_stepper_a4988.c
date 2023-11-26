/*
 * fc_adxl375.c
 *
 *  Created on: Sep 24, 2023
 *      Author: bsli
 */

#include "fc_stepper_a4988.h"
#include "fc_common.h"
#include "stm32h7xx_hal.h"
#include "cmsis_os.h"

float fc_step_motor(float steps) {
	/* Set direction */
	if (steps > 0) {
		HAL_GPIO_WritePin(GPIO_OUT_A4988_DIR_GPIO_Port, GPIO_OUT_A4988_DIR_Pin, GPIO_PIN_SET);
	} else {
		HAL_GPIO_WritePin(GPIO_OUT_A4988_DIR_GPIO_Port, GPIO_OUT_A4988_DIR_Pin, GPIO_PIN_RESET);
	}

	/* Make all possible full steps */
	while (steps%16 > 0) {
		/* Set Micro step */
		HAL_GPIO_WritePin(GPIO_OUT_A4988_MS1_GPIO_Port, GPIO_OUT_A4988_MS1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIO_OUT_A4988_MS2_GPIO_Port, GPIO_OUT_A4988_MS2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIO_OUT_A4988_MS3_GPIO_Port, GPIO_OUT_A4988_MS3_Pin, GPIO_PIN_RESET);

		/* Make the steps */
		HAL_GPIO_WritePin(GPIO_OUT_A4988_STEP_GPIO_Port, GPIO_OUT_A4988_STEP_Pin, GPIO_PIN_RESET);
		osDelay(1);
		HAL_GPIO_WritePin(GPIO_OUT_A4988_STEP_GPIO_Port, GPIO_OUT_A4988_STEP_Pin, GPIO_PIN_SET);
		osDelay(1);
		HAL_GPIO_WritePin(GPIO_OUT_A4988_STEP_GPIO_Port, GPIO_OUT_A4988_STEP_Pin, GPIO_PIN_RESET);
		osDelay(MOTOR_DELAY_FULL);
		
		/* Decrement angle remaining. */
		steps -= 16;
	}

	/* Make all possible half steps */
	while (steps%8 > 0) {
		/* Set Micro step */
		HAL_GPIO_WritePin(GPIO_OUT_A4988_MS1_GPIO_Port, GPIO_OUT_A4988_MS1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIO_OUT_A4988_MS2_GPIO_Port, GPIO_OUT_A4988_MS2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIO_OUT_A4988_MS3_GPIO_Port, GPIO_OUT_A4988_MS3_Pin, GPIO_PIN_RESET);

		/* Make the steps */
		HAL_GPIO_WritePin(GPIO_OUT_A4988_STEP_GPIO_Port, GPIO_OUT_A4988_STEP_Pin, GPIO_PIN_RESET);
		osDelay(1);
		HAL_GPIO_WritePin(GPIO_OUT_A4988_STEP_GPIO_Port, GPIO_OUT_A4988_STEP_Pin, GPIO_PIN_SET);
		osDelay(1);
		HAL_GPIO_WritePin(GPIO_OUT_A4988_STEP_GPIO_Port, GPIO_OUT_A4988_STEP_Pin, GPIO_PIN_RESET);
		osDelay(MOTOR_DELAY_FULL);

		/* Decrement angle remaining. */
		steps -= 8;
	}

	/* Make all possible quarter steps */
	while (steps%4 > 0) {
		/* Set Micro step */
		HAL_GPIO_WritePin(GPIO_OUT_A4988_MS1_GPIO_Port, GPIO_OUT_A4988_MS1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIO_OUT_A4988_MS2_GPIO_Port, GPIO_OUT_A4988_MS2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIO_OUT_A4988_MS3_GPIO_Port, GPIO_OUT_A4988_MS3_Pin, GPIO_PIN_RESET);

		/* Make the steps */
		HAL_GPIO_WritePin(GPIO_OUT_A4988_STEP_GPIO_Port, GPIO_OUT_A4988_STEP_Pin, GPIO_PIN_RESET);
		osDelay(1);
		HAL_GPIO_WritePin(GPIO_OUT_A4988_STEP_GPIO_Port, GPIO_OUT_A4988_STEP_Pin, GPIO_PIN_SET);
		osDelay(1);
		HAL_GPIO_WritePin(GPIO_OUT_A4988_STEP_GPIO_Port, GPIO_OUT_A4988_STEP_Pin, GPIO_PIN_RESET);
		osDelay(MOTOR_DELAY_FULL);

		/* Decrement angle remaining. */
		steps -= 4;
	}

	/* Make all possible eigth steps */
	while (steps%2 > 0) {
		/* Set Micro step */
		HAL_GPIO_WritePin(GPIO_OUT_A4988_MS1_GPIO_Port, GPIO_OUT_A4988_MS1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIO_OUT_A4988_MS2_GPIO_Port, GPIO_OUT_A4988_MS2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIO_OUT_A4988_MS3_GPIO_Port, GPIO_OUT_A4988_MS3_Pin, GPIO_PIN_RESET);

		/* Make the steps */
		HAL_GPIO_WritePin(GPIO_OUT_A4988_STEP_GPIO_Port, GPIO_OUT_A4988_STEP_Pin, GPIO_PIN_RESET);
		osDelay(1);
		HAL_GPIO_WritePin(GPIO_OUT_A4988_STEP_GPIO_Port, GPIO_OUT_A4988_STEP_Pin, GPIO_PIN_SET);
		osDelay(1);
		HAL_GPIO_WritePin(GPIO_OUT_A4988_STEP_GPIO_Port, GPIO_OUT_A4988_STEP_Pin, GPIO_PIN_RESET);
		osDelay(MOTOR_DELAY_FULL);

		/* Decrement angle remaining. */
		steps -= 2;
	}

	/* Make all possible sixteenth steps */
	while (steps--> 0) {
		/* Set Micro step */
		HAL_GPIO_WritePin(GPIO_OUT_A4988_MS1_GPIO_Port, GPIO_OUT_A4988_MS1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIO_OUT_A4988_MS2_GPIO_Port, GPIO_OUT_A4988_MS2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIO_OUT_A4988_MS3_GPIO_Port, GPIO_OUT_A4988_MS3_Pin, GPIO_PIN_SET);

		/* Make the steps */
		HAL_GPIO_WritePin(GPIO_OUT_A4988_STEP_GPIO_Port, GPIO_OUT_A4988_STEP_Pin, GPIO_PIN_RESET);
		osDelay(1);
		HAL_GPIO_WritePin(GPIO_OUT_A4988_STEP_GPIO_Port, GPIO_OUT_A4988_STEP_Pin, GPIO_PIN_SET);
		osDelay(1);
		HAL_GPIO_WritePin(GPIO_OUT_A4988_STEP_GPIO_Port, GPIO_OUT_A4988_STEP_Pin, GPIO_PIN_RESET);
		osDelay(MOTOR_DELAY_FULL);
	}

	return 0;
}
