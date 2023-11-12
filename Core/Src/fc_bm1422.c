/*
 * fc_bm1422.c
 *
 *  Created on: Nov 5, 2023
 *      Author: bsli
 */

#include "fc_common.h"
#include "stm32h7xx_hal.h"
#include "fc_bm1422.h"

int fc_bm1422_initialize(struct fc_bm1422 *device, I2C_HandleTypeDef *i2c_handle, int *i2c_owner) {

	/* reset struct */
	device->i2c_handle		= i2c_handle;
	device->i2c_is_done		= 0;
	device->x_data			= 0.0f;
	device->y_data			= 0.0f;
	device->z_data			= 0.0f;

	/* =================================== */
	/* check that the device id is correct */
	/* =================================== */

	HAL_StatusTypeDef status;
	uint8_t data;

	/* tell interrupt handler that we're using the i2c peripheral */
	*device->i2c_owner = FC_I2C_OWNER_FC_BM1422;

	if (status != HAL_OK) {
		return 42;
	}

	/* wait under i2c read is complete */
	while (!device->i2c_is_done) {
		osDelay(10);
	}
	if (device->i2c_is_error) {
		return 255;
	}
	device->i2c_is_done = 0;
	device->i2c_is_error = 0;

	/* tell interrupt handler that this sensor is using the i2c peripheral */
	*decice->i2c_owner = FC_I2C_OWNER_FC_BM1422;

	/* Start i2c write */
	if (status != HAL_OK) {
		return 42;
	}

	/* wait until i2c read is complete */
	while (!device->i2c_is_done) {
		osDelay(10);
	}
	if (device->i2c_is_error) {
		return 255;
	}
	device->i2c_is_done = 0;
	device->i2c_is_error = 0;

	/* TODO: FINISH THIS */

	return 0;
}
