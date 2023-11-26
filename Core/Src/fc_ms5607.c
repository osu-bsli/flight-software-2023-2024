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
FC_STATUS ms5607_initialize(struct fc_ms5607 *device, I2C_HandleTypeDef *i2c_handle) {

	/* reset struct */
	device->i2c_handle    = i2c_handle;
	device->pressure_mbar = 0.0f;
	device->temperature_c = 0.0f;

	/* check that the device id is correct */
	HAL_StatusTypeDef status;
	uint8_t data;
	//status = fc_ms5607_readregister(device, FC_MS5607_I2C_DEVICE_ID, &data); //TODO: Find new way to verify

	/* Return error code if data or read status is not correct */
/*	if (status != HAL_OK) {
		return FC_STATUS_ERROR;
	}
	if (data != FC_MS5607_I2C_DEVICE_ID) {
		return FC_STATUS_ERROR;
	}*/

	/* Initiate reset sequence to calibrate PROM */
	int reset_status = ms5607_reset(device);
	if(reset_status != FC_STATUS_SUCCESS){
		return FC_STATUS_ERROR;
	}

	// Initialization succeeded
	return FC_STATUS_SUCCESS;
}

/* Reset command for barometer */
/* Return Status */
FC_STATUS ms5607_reset(struct fc_ms5607 *device) {
	/* Send reset command */

	// Write reset command
	uint8_t* data = FC_MS5607_CONSTANT_RESET;
	FC_STATUS reset_status = fc_ms5607_send_command(device, FC_MS5607_I2C_WRITE_ADDRESS, data, FC_8BIT_COMMAND_SIZE, FC_MS5607_I2C_TIMEOUT);
	if(reset_status != FC_STATUS_SUCCESS){
			return FC_STATUS_ERROR;
	}

	/* Must read PROM once after a reset occurs - maybe?*/
	//int read_status = ms5607_read_prom(device);
	return FC_STATUS_SUCCESS;
}

/* Prom read sequence. Reads C1-C6  - NOT SURE IF THIS IS NECESSARY */
FC_STATUS ms5607_read_prom(struct fc_ms5607 *device){
	/* PROM Read command consists of two parts */

	/* First command sets up the system into PROM read mode */
	return FC_STATUS_SUCCESS;
}

// TODO: update from accelerometer driver

/* Process to read and convert pressure and temperature */
FC_STATUS ms5607_process(struct fc_ms5607 *device) {
	uint8_t* command_data = FC_MS5607_CONSTANT_CONVERTD1_OSR4096;

	/* Conversion Sequence */
	/* Start Conversion by sending pressure conversion command (01001000) */
	int send_status = fc_ms5607_send_command(device, FC_MS5607_I2C_WRITE_ADDRESS, command_data, sizeof(data), timeout);
	if(send_status != FC_STATUS_SUCCESS){
		return FC_STATUS_ERROR;
	}

	// TODO: Figure out how to store 24 bits of conversion data.
	uint8_t data;
	/* Access conversion data by sending a read command. 24 SCLK cycles to receive all bits. */
	int read_status = fc_ms_send_read_command(device, FC_MS5607_IC2_READ_ADDRESS, &data, );

	// TODO: Convert pressure data. (Ex: 110002 = 1100.02 mbar) divide raw data by 100 and convert to float
	// TODO: Populate structure with reading

	return 0;
}

FC_STATUS fc_ms5607_send_read_command(struct fc_ms5607 *device, uint16_t addr, uint8_t *data, uint16_t size, uint32_t timeout) {
	/* Transmit a command of 0s to trigger a read */
	uint8_t* data = 0x00;
	FC_STATUS send_command = fc_ms5607_send_write_command(device, FC_MS5607_I2C_WRITE_ADDRESS, data, sizeof(data), timeout);
	if(send_command != HAL_OK){
		return FC_STATUS_ERROR;
	}

	/* Read data */
	int read_command = HAL_I2C_Master_Receive(device->i2c_handle, addr, data, size, timeout);

	return FC_STATUS_SUCCESS;
}

/* Double check all data + data lengths */
FC_STATUS fc_ms5607_send_write_command(struct fc_ms5607 *device, uint16_t addr, uint8_t *data, uint16_t size, uint32_t timeout) {
	send_command = HAL_I2C_Master_Transmit(device->i2c_handle, addr, data, sizeof(data), timeout);
	if(send_command != HAL_OK){
		return FC_STATUS_ERROR;
	}
}
