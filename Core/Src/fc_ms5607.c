/*
 * fc_ms5607.c
 *
 *  Created on: Nov 5, 2023
 *      Author: bsli
 */

#include "fc_ms5607.h"
#include "stm32h7xx_hal.h"

/*THIS IS TO BE EDITED- EVERYTHING BELOW IS JUST A TEMPLATE FOR NOW */

int ms5607_initialize(struct fc_ms5607 *device, I2C_HandleTypeDef *i2c_handle) {

	/* reset struct */
	device->i2c_handle     = i2c_handle;
	device->acceleration_x = 0.0f;
	device->acceleration_y = 0.0f;
	device->acceleration_z = 0.0f;

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

int adxl375_process(struct fc_adxl375 *device) {

	/* read raw acceleration data bytes */
	uint8_t data[6]; /* DATAX0, X1, Y0, Y1, Z0, and Z1 registers (pg. 24) */
	HAL_StatusTypeDef status = fc_adxl375_readregisters(device, FC_ADXL375_REGISTER_DATAX0, data, sizeof(data));
	if (status != HAL_OK) {
		return 255;
	}

	/* convert bytes to signed 16-bit values */
	union { /* must use union for type-punning to avoid undefined behavior */
		uint8_t bytes[2]; /* little-endian system, bytes[0] is least significant byte */
		int16_t value;
	} converter;

	converter.bytes[0] = data[0]; /* DATAX0 is least significant byte (pg. 24) */
	converter.bytes[1] = data[1];
	int16_t raw_acceleration_x = converter.value;

	converter.bytes[0] = data[2]; /* DATAY0 is least significant byte (pg. 24) */
	converter.bytes[1] = data[3];
	int16_t raw_acceleration_y = converter.value;

	converter.bytes[0] = data[4]; /* DATAZ0 is least significant byte (pg. 24) */
	converter.bytes[1] = data[5];
	int16_t raw_acceleration_z = converter.value;

	/* convert raw data to actual acceleration data */
	device->acceleration_x = (float) raw_acceleration_x;
	device->acceleration_y = (float) raw_acceleration_y;
	device->acceleration_z = (float) raw_acceleration_z;

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
