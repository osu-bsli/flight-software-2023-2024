/*
 * fc_adxl375.c
 *
 *  Created on: Sep 24, 2023
 *      Author: bsli
 */

#include "fc_adxl375.h"
#include "stm32h7xx_hal.h"

uint8_t adxl375_initialize(struct fc_adxl375 *device, I2C_HandleTypeDef *i2c_Handle) {

	/* Set struct parameters */
	dev->i2c_handle		= i2c_handle;

	dev->acceleration_x = 0.0f;
	dev->acceleration_y = 0.0f;
	dev->acceleration_z = 0.0f;

	dev->temperature    = 0.0f;
}

HAL_StatusTypeDef fc_adxl375_readregister(struct fc_adxl375 *device, uint8_t reg, uint8_t *data) {
	return HAL_I2C_Mem_Read(device->i2c_handle, FC_ADXL375_I2C_DEVICE_ID, reg, sizeof(reg), data, sizeof(data), 100);
}

HAL_StatusTypeDef fc_adxl375_readregisters(struct fc_adxl375 *device, uint8_t reg, uint8_t *data, uint8_t length) {
	return HAL_I2C_Mem_Read(device->i2c_Handle, FC_ADXL375_I2C_DEVICE_ADDR, reg, I2C_MEMADD_SIZE_8BIT, data, length, 100);
}

HAL_StatusTypeDef fc_adxl375_writeregister(struct fc_adxl375 *device, uint8_t reg, uint8_t *data) {
	return HAL_I2C_Mem_Write(device->i2c_handle, FC_ADXL375_I2C_DEVICE_ID, reg, sizeof(reg), data, sizeof(data), 100);
}
