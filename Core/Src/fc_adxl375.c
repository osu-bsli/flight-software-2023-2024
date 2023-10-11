/*
 * fc_adxl375.c
 *
 *  Created on: Sep 24, 2023
 *      Author: bsli
 */

#include "fc_adxl375.h"
#include "stm32h7xx_hal.h"

uint8_t adxl375_initialize(struct fc_adxl375 *device, I2C_HandleTypeDef *i2c_handle) {

	/* reset struct */
	device->i2c_handle     = i2c_handle;
	device->acceleration_x = 0.0f;
	device->acceleration_y = 0.0f;
	device->acceleration_z = 0.0f;
	device->temperature    = 0.0f;

	/* check that the device id is correct */
	HAL_StatusTypeDef status;
	uint8_t data;
	status = fc_adxl375_readregister(device, FC_ADXL375_REGISTER_DEVID, &data);
	if (status != HAL_OK) {
		return 42;
	}
	if (data != FC_ADXL375_I2C_DEVICE_ID) {
		return 255;
	}

	/* set measure bit in POWER_CTL register (pg. 22) */
	data = 0b00001000;
	status = fc_adxl375_writeregister(device, FC_ADXL375_REGISTER_POWER_CTL, &data);
	if (status != HAL_OK) {
		return 42;
	}

	return 0;
}

HAL_StatusTypeDef fc_adxl375_readregister(struct fc_adxl375 *device, uint8_t reg, uint8_t *data) {
	return HAL_I2C_Mem_Read(device->i2c_handle, FC_ADXL375_I2C_DEVICE_ID, reg, sizeof(reg), data, sizeof(data), 100);
}

HAL_StatusTypeDef fc_adxl375_readregisters(struct fc_adxl375 *device, uint8_t reg, uint8_t *data, uint8_t length) {
	return HAL_I2C_Mem_Read(device->i2c_handle, FC_ADXL375_I2C_DEVICE_ID, reg, sizeof(reg), data, length, 100);
}

HAL_StatusTypeDef fc_adxl375_writeregister(struct fc_adxl375 *device, uint8_t reg, uint8_t *data) {
	return HAL_I2C_Mem_Write(device->i2c_handle, FC_ADXL375_I2C_DEVICE_ID, reg, sizeof(reg), data, sizeof(data), 100);
}
