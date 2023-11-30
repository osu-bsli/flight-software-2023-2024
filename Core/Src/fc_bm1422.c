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

	/* start i2c read with a 2-byte Batch Read */
	/* Use the FIRST Device Address for the batch read */
	status = fc_bm1422_readregisters(device, FC_BM1422_REGISTER_INFORMATION, &data, 2);
	if (status != HAL_OK) {
		return 42;
	}

	if (data != FC_BM1422_I2C_ADDRESS) {
		return 255;
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

	/* Set the Power Control Bit for Magnometer
	 * Default Setting: 0x22 -> 00100010 (pg.12)*/
	data = 0b01101100u;

	/* tell interrupt handler that this sensor is using the i2c peripheral */
	*device->i2c_owner = FC_I2C_OWNER_FC_BM1422;

	/* Start i2c write */
	status = fc_bm1422_writeregister(device, FC_BM1422_REGISTER_CONTROL1, &data);
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

	return 0;
}

/* TODO: finish function body */
int fc_bm1422_process(struct fc_bm1422 *device) {

	return 0;
}

/* TODO: replace "0" with equivalent of device ID for the magnometer */

HAL_StatusTypeDef fc_bm1422_readregister(struct fc_bm1422 *device, uint8_t reg, uint8_t *data) {
	return HAL_I2C_Mem_Read_IT(device->i2c_handle, 0, reg, sizeof(reg), data, sizeof(data));
}

HAL_StatusTypeDef fc_bm1422_readregisters(struct fc_bm1422 *device, uint8_t reg, uint8_t *data, uint8_t length) {
	return HAL_I2C_Mem_Read_IT(device->i2c_handle, 0, reg, sizeof(reg), data, length);
}

HAL_StatusTypeDef fc_bm1422_writeregister(struct fc_bm1422 *device, uint8_t reg, uint8_t *data) {
	return HAL_I2C_Mem_Write_IT(device->i2c_handle, 0, reg, sizeof(reg), data, sizeof(data));
}
