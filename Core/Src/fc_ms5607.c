/*
 * fc_ms5607.c
 *
 *  Created on: Nov 5, 2023
 *      Author: bsli
 */

#include "fc_ms5607.h"
#include "stm32h7xx_hal.h"
#include "fc_status_codes.h"

/* Initialize MS5607 barometer I2C device */
int ms5607_initialize(struct fc_ms5607 *device, I2C_HandleTypeDef *i2c_handle) {

	/* reset struct */
	device->i2c_handle    = i2c_handle;
	device->pressure_mbar = 0.0f;
	device->temperature_c = 0.0f;

	/* check that the device id is correct */
	HAL_StatusTypeDef status;
	uint8_t data;
	status = fc_ms5607_readregister(device, FC_MS5607_I2C_DEVICE_ID, &data);

	/* Return error code if data or read status is not correct */
	if (status != HAL_OK) {
		return FC_STATUS_ERROR;
	}
	if (data != FC_MS5607_I2C_DEVICE_ID) {
		return FC_STATUS_ERROR;
	}

	/* Initiate reset sequence to calibrate PROM */

	int status = ms5607_reset();
	if(status != FC_STATUS_SUCCESS){
		return FC_STATUS_ERROR;
	}

	// Initialization succeeded
	return FC_STATUS_SUCCESS;
}

/* Reset command for barometer */
/* Return Status */
int ms5607_reset() {
	/* Send reset command */

	// Write reset command

	HAL_StatusTypeDef reset_status = fc_ms5607_writeregister(struct fc_ms5607 *device, uint8_t reg, uint8_t *data);

	/* Must read PROM once after a reset occurs */

}

// TODO: write read prom

/* Prom read sequence. Reads C1-C6  */
int ms5607_read_PROM(){


}

// TODO: update from accelerometer driver

/* Process to read and convert pressure and temperature */
int ms5607_process(struct fc_ms5607 *device) {

	/* read raw pressure data bytes */
	uint8_t data[6]; /* DATAX0, X1, Y0, Y1, Z0, and Z1 registers (pg. 24) */
	HAL_StatusTypeDef status = fc_ms5607_readregisters(device, FC_MS5607_CONSTANT_RESET, data, sizeof(data));
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
	//int16_t raw_acceleration_x = converter.value;

	converter.bytes[0] = data[2]; /* DATAY0 is least significant byte (pg. 24) */
	converter.bytes[1] = data[3];
	//int16_t raw_acceleration_y = converter.value;

	converter.bytes[0] = data[4]; /* DATAZ0 is least significant byte (pg. 24) */
	converter.bytes[1] = data[5];
	//int16_t raw_acceleration_z = converter.value;

	/* convert raw data to actual acceleration data */
//	device->acceleration_x = (float) raw_acceleration_x;
//	device->acceleration_y = (float) raw_acceleration_y;
//	device->acceleration_z = (float) raw_acceleration_z;

	return 0;
}

HAL_StatusTypeDef fc_ms5607_readregister(struct fc_ms5607 *device, uint8_t reg, uint8_t *data) {
	return HAL_I2C_Mem_Read(device->i2c_handle, FC_MS5607_I2C_DEVICE_ID_READ, reg, sizeof(reg), data, sizeof(data), 100);
}

HAL_StatusTypeDef fc_ms5607_readregisters(struct fc_ms5607 *device, uint8_t reg, uint8_t *data, uint8_t length) {
	return HAL_I2C_Mem_Read(device->i2c_handle, FC_MS5607_I2C_DEVICE_ID, reg, sizeof(reg), data, length, 100);
}

HAL_StatusTypeDef fc_ms5607_writeregister(struct fc_ms5607 *device, uint8_t reg, uint8_t *data) {
	return HAL_I2C_Mem_Write(device->i2c_handle, FC_MS5607_I2C_DEVICE_ID_WRITE, reg, sizeof(reg), data, sizeof(data), 100);
}
