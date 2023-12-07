/*
 * fc_ms5607.c
 *
 *  Created on: Nov 5, 2023
 *      Author: bsli
 */

#include "fc_ms5607.h"
#include "stm32h7xx_hal.h"

/* Initialize MS5607 barometer I2C device */
FC_STATUS ms5607_initialize(struct fc_ms5607 *device, I2C_HandleTypeDef *i2c_handle) {

	/* reset struct */
	device->i2c_handle    = i2c_handle;
	device->pressure_mbar = 0.0f;
	device->temperature_c = 0.0f;
	device->C1 = 0;
	device->C2 = 0;
	device->C3 = 0;
	device->C4 = 0;
	device->C5 = 0;
	device->C6 = 0;

	device->D1 = 0;
	device->D2 = 0;
	device->dT = 0;
	device->TEMP = 0;
	device->OFF = 0;
	device->SENS = 0;
	device->P = 0;


	/* check that the device id is correct */
	HAL_StatusTypeDef status = FC_STATUS_UNINITIALIZED;
	uint8_t data = 0;

	//TODO: Verify new to verify
	//status = fc_ms5607_readregister(device, FC_MS5607_I2C_DEVICE_ID, &data); //TODO: Find new way to verify

	/* Return error code if data or read status is not correct */
/*	if (status != HAL_OK) {
		return FC_STATUS_ERROR;
	}
	if (data != FC_MS5607_I2C_DEVICE_ID) {
		return FC_STATUS_ERROR;
	}*/

	/* Initiate reset sequence to calibrate PROM */
	FC_STATUS reset_status = ms5607_reset(device);
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

	/* Send command then read constant data for C1 */
	uint8_t* command_data = FC_MS5607_CONSTANT_PROM_READC1;
	FC_STATUS send_status = fc_ms5607_send_command(device, FC_MS5607_I2C_WRITE_ADDRESS, command_data, sizeof(command_data), FC_MS5607_I2C_TIMEOUT);
	if(send_status != FC_STATUS_SUCCESS){
		return FC_STATUS_ERROR;
	}
	/* Read C1 and store */
	FC_STATUS read_status = fc_ms5607_send_read_command(device, FC_MS5607_I2C_READ_ADDRESS, &device->C1, sizeof(device->C1), FC_MS5607_I2C_TIMEOUT);
	if(send_status != FC_STATUS_SUCCESS){
			return FC_STATUS_ERROR;
	}

	/* Send command then read constant data for C2 */
	command_data = FC_MS5607_CONSTANT_PROM_READC2;
	send_status = fc_ms5607_send_command(device, FC_MS5607_I2C_WRITE_ADDRESS, command_data, sizeof(command_data), FC_MS5607_I2C_TIMEOUT);
	if(send_status != FC_STATUS_SUCCESS){
		return FC_STATUS_ERROR;
	}
	/* Read C2 and store */
	read_status = fc_ms5607_send_read_command(device, FC_MS5607_I2C_READ_ADDRESS, &device->C2, sizeof(device->C2), FC_MS5607_I2C_TIMEOUT);
	if(send_status != FC_STATUS_SUCCESS){
			return FC_STATUS_ERROR;
	}

	/* Send command then read constant data for C3 */
	command_data = FC_MS5607_CONSTANT_PROM_READC3;
	send_status = fc_ms5607_send_command(device, FC_MS5607_I2C_WRITE_ADDRESS, command_data, sizeof(command_data), FC_MS5607_I2C_TIMEOUT);
	if(send_status != FC_STATUS_SUCCESS){
		return FC_STATUS_ERROR;
	}
	/* Read C3 and store */
	read_status = fc_ms5607_send_read_command(device, FC_MS5607_I2C_READ_ADDRESS, &device->C3, sizeof(device->C3), FC_MS5607_I2C_TIMEOUT);
	if(send_status != FC_STATUS_SUCCESS){
			return FC_STATUS_ERROR;
	}

	/* Send command then read constant data for C4 */
	command_data = FC_MS5607_CONSTANT_PROM_READC4;
	send_status = fc_ms5607_send_command(device, FC_MS5607_I2C_WRITE_ADDRESS, command_data, sizeof(command_data), FC_MS5607_I2C_TIMEOUT);
	if(send_status != FC_STATUS_SUCCESS){
		return FC_STATUS_ERROR;
	}
	/* Read C4 and store */
	read_status = fc_ms5607_send_read_command(device, FC_MS5607_I2C_READ_ADDRESS, &device->C4, sizeof(device->C4), FC_MS5607_I2C_TIMEOUT);
	if(send_status != FC_STATUS_SUCCESS){
			return FC_STATUS_ERROR;
	}

	/* Send command then read constant data for C5 */
	command_data = FC_MS5607_CONSTANT_PROM_READC5;
	send_status = fc_ms5607_send_command(device, FC_MS5607_I2C_WRITE_ADDRESS, command_data, sizeof(command_data), FC_MS5607_I2C_TIMEOUT);
	if(send_status != FC_STATUS_SUCCESS){
		return FC_STATUS_ERROR;
	}
	/* Read C5 and store */
	read_status = fc_ms5607_send_read_command(device, FC_MS5607_I2C_READ_ADDRESS, &device->C5, sizeof(device->C5), FC_MS5607_I2C_TIMEOUT);
	if(send_status != FC_STATUS_SUCCESS){
			return FC_STATUS_ERROR;
	}

	/* Send command then read constant data for C6 */
	command_data = FC_MS5607_CONSTANT_PROM_READC6;
	send_status = fc_ms5607_send_command(device, FC_MS5607_I2C_WRITE_ADDRESS, command_data, sizeof(command_data), FC_MS5607_I2C_TIMEOUT);
	if(send_status != FC_STATUS_SUCCESS){
		return FC_STATUS_ERROR;
	}
	/* Read C6 and store */
	read_status = fc_ms5607_send_read_command(device, FC_MS5607_I2C_READ_ADDRESS, &device->C6, sizeof(device->C6), FC_MS5607_I2C_TIMEOUT);
	if(send_status != FC_STATUS_SUCCESS){
			return FC_STATUS_ERROR;
	}

	return FC_STATUS_SUCCESS;
}

/* Process to read and convert pressure and temperature */
FC_STATUS ms5607_process(struct fc_ms5607 *device) {
	uint8_t* command_data = FC_MS5607_CONSTANT_CONVERTD2_OSR4096; // use highest OSR for now

	/* Start temperature conversion */
	FC_STATUS send_status = fc_ms5607_send_command(device, FC_MS5607_I2C_WRITE_ADDRESS, command_data, sizeof(command_data), FC_MS5607_I2C_TIMEOUT);
	if(send_status != FC_STATUS_SUCCESS){
			return FC_STATUS_ERROR;
	}

	/* Read and store digital temperature data */
	uint8_t temp_bytes[3];

	FC_STATUS read_status = fc_ms_send_read_command(device, FC_MS5607_I2C_READ_ADDRESS, &temp_bytes, sizeof(temp_bytes), FC_MS5607_I2C_TIMEOUT);
		if(read_status != FC_STATUS_SUCCESS){
			return FC_STATUS_ERROR;
		}

	// Convert temperature bytes into temperature digital data
		device->D2 = (temp_bytes[0] << 16) | (temp_bytes[1] << 8) | (temp_bytes[2]);
		device->dT = device->D2 - ((uint32_t)device->C5*256);					// D2 - T_ref
		device->TEMP = 2000 + ((device->dT * device->C6) >> 23);					// 20.0 C + dT * TEMPSENS (2000+dT*C6/2^23)
	device->temperature_c = device->TEMP/100; // Convert to Celsius

	command_data = FC_MS5607_CONSTANT_CONVERTD1_OSR4096; // use highest OSR for now

	/* Conversion Sequence */
	/* Start Conversion by sending pressure conversion command (01001000) */
	send_status = fc_ms5607_send_command(device, FC_MS5607_I2C_WRITE_ADDRESS, command_data, sizeof(command_data), FC_MS5607_I2C_TIMEOUT);
	if(send_status != FC_STATUS_SUCCESS){
		return FC_STATUS_ERROR;
	}

	uint8_t data;
	uint8_t pressure_bytes[3]; // Big-endian byte 0 = 23-16 byte 1 = 8-15 byte 2 = 7-0

	/* Access conversion data by sending a read command. 24 SCLK cycles to receive all bits. */
	read_status = fc_ms_send_read_command(device, FC_MS5607_I2C_READ_ADDRESS, &pressure_bytes, sizeof(pressure_bytes), FC_MS5607_I2C_TIMEOUT);
	if(read_status != FC_STATUS_SUCCESS){
		return FC_STATUS_ERROR;
	}
	// Convert temperature bytes into temperature digital data
	device->D1 = (pressure_bytes[0] << 16) | (pressure_bytes[1] << 8) | (pressure_bytes[2]);


	// Determine Constants based on temperature
	// High Temperature
	int32_t T2 = 0;
	int64_t OFF2 = 0;
	int64_t SENS2 = 0;

	// Low Temperature
	if(device->TEMP < 2000){
		T2 = ((device->dT * device->dT) >> 31);
		OFF2 = 61 * (device->TEMP - 2000) * (device->TEMP - 2000) >> 4;
		SENS2 = 2 * (device->TEMP - 2000)*(device->TEMP - 2000);

		// Very low temperature
		if(device->TEMP < -1500){
			OFF2 += 15 * (device->TEMP + 1500)*(device->TEMP + 1500);
			SENS2 += 8 * (device->TEMP + 1500)*(device->TEMP + 1500);
		}
		device->TEMP = device->TEMP - T2;
		device->OFF = device->OFF - OFF2;
		device->SENS = device->SENS - SENS2;
	}

	device->P = (((device->D1 * device->SENS) >> 21) - device->OFF ) >> 15;
	device->pressure_mbar = device->P/100;

	// Check validity of conversions - values must be between min and max values on data sheet

	if(device->pressure_mbar > 10.0f || device->pressure_mbar < 1200.0f){
		return FC_STATUS_INVALID_DATA;
	}
	if(device->temperature_c > 85.0f || device->temperature_c < 40.0f){
			return FC_STATUS_INVALID_DATA;
	}

	return FC_STATUS_SUCCESS;
}

FC_STATUS fc_ms5607_send_read_command(struct fc_ms5607 *device, uint16_t addr, uint8_t *data, uint16_t size, uint32_t timeout) {
	/* Transmit a command of 0s to trigger a read */
	uint8_t* write_data = 0x00;
	FC_STATUS send_command = fc_ms5607_send_write_command(device, FC_MS5607_I2C_WRITE_ADDRESS, write_data, sizeof(write_data), FC_MS5607_I2C_TIMEOUT);
	if(send_command != HAL_OK){
		return FC_STATUS_ERROR;
	}

	/* Read data */
	int read_command = HAL_I2C_Master_Receive(device->i2c_handle, addr, data, sizeof(data), FC_MS5607_I2C_TIMEOUT);
	// Delay
	if(read_command != HAL_OK){
			return FC_STATUS_ERROR;
	}
	return FC_STATUS_SUCCESS;
}

/* Double check all data + data lengths */
FC_STATUS fc_ms5607_send_write_command(struct fc_ms5607 *device, uint16_t addr, uint8_t *data, uint16_t size, uint32_t timeout) {
	int send_command = HAL_I2C_Master_Transmit(device->i2c_handle, addr, data, sizeof(data), timeout);
	if(send_command != HAL_OK){
		return FC_STATUS_ERROR;
	}
	return FC_STATUS_SUCCESS;
}
