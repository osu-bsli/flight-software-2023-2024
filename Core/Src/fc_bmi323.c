/*
 * fc_bmi323.c
 *
 *  Created on: Nov 12, 2023
 *      Author: bsli
 */
#include "fc_bmi323.h"
#include "fc_common.h"
#include "stm32h7xx_hal.h"

int fc_bmi323_initialize(struct fc_bmi323 *device, I2C_HandleTypeDef *i2c_handle, int *i2c_owner) {
	/* when writing to registers with reserved bits, must read, update, then write (datasheet pg. 61) */
	/* write calibration values to registers (datasheet pg. 54) */

	return 0;
}

int fc_bmi323_process(struct fc_bmi323 *device) {

	/* check for dataready (datasheet pg. 65) */
	uint8_t dataready_bytes[2];
	HAL_StatusTypeDef status = HAL_I2C_Mem_Read(device->i2c_handle, FC_BMI323_I2C_DEVICE_ID, FC_BMI323_REGISTER_STATUS, 1, dataready_bytes, 2, 100);
	if (status != HAL_OK) {
		return 42;
	}

	/* TODO: finish */

	return 0;
}
