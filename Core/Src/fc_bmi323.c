/*
 * fc_bmi323.c
 *
 *  Created on: Nov 12, 2023
 *      Author: bsli
 */
#include "fc_bmi323.h"
#include "fc_common.h"
#include "stm32h7xx_hal.h"
#include <assert.h>

/* sensor configuration
 * - Accelerometer range: 16 g      (max).
 * - Gyroscope range:     125 deg/s (min, we only care about off-axis rotation which is slow).
 * - Temperature range is fixed.
 * - Power mode: normal (datasheet pg. 22).
 * Ranges are +/-, see datasheet pg. 1.
 */

/* TODO:
 * - Check saturation flags for each axis of each sensor during sensor read.
 */

#define FC_BMI323_ACC_RANGE_MAX 16.0f   /* acceleration         (g)     (datasheet pg. 23) */
#define FC_BMI323_ACC_RANGE_MIN -16.0f
#define FC_BMI323_GYR_RANGE_MAX 125.0f  /* angular acceleration (deg/s) (datasheet pg. 25) */
#define FC_BMI323_GYR_RANGE_MIN -125.0f

uint16_t fc_bytes2uint16(uint8_t msb, uint8_t lsb) {
	union {
		uint8_t bytes[2]; /* little-endian */
		uint16_t value;
	} converter;
	converter.bytes[0] = lsb;
	converter.bytes[1] = msb;
	return converter.value;
}

int16_t fc_bytes2int16(uint8_t msb, uint8_t lsb) {
	union {
		uint8_t bytes[2]; /* little-endian */
		int16_t value;
	} converter;
	converter.bytes[0] = lsb;
	converter.bytes[1] = msb;
	return converter.value;
}


int fc_bmi323_initialize(struct fc_bmi323 *device, I2C_HandleTypeDef *i2c_handle, int *i2c_owner) {
	/* when writing to registers with reserved bits, must read, update, then write (datasheet pg. 62) */
	/* write calibration values to registers (datasheet pg. 55) */

	/* check ERR_REG.fatal_err before enabling sensors */

	/* =================================================================================== */
	/* configure ACC_CONF register (acc_mode, acc_range, acc_bw, acc_avg_num, and acc_odr) */
	/* =================================================================================== */

	/* ACC_CONF.acc_mode = 0b111 for normal power mode (datasheet pg. 22) */
	/* ACC_CONF.acc_avg_num = ??? TODO */
	/* ACC_CONF.acc_bw = ??? TODO */
	/* ACC_CONF.acc_range = 0b011 for +/- 16 g range (datasheet pg. 92) */
	/* ACC_CONF.acc_odr = ??? TODO */

	/* =================================================================================== */
	/* configure GYR_CONF register (gyr_mode, gyr_range, gyr_bw, gyr_avg_num, and gyr_odr) */
	/* =================================================================================== */

	/* GYR_CONF.gyr_mode = 0b111 for normal power mode (datasheet pg. 22) */
	/* GYR_CONF.gyr_avg_num = ??? TODO */
	/* GYR_CONF.gyr_bw = ??? TODO */
	/* GYR_CONF.gyr_range = 0b000 for +/- 125 deg/s range (datasheet pg. 94) */
	/* GYR_CONF.gyr_odr = ??? TODO */

	return 0;
}

int fc_bmi323_process(struct fc_bmi323 *device) {

	/* check for dataready (datasheet pg. 68) */
	int is_temperature_data_ready = 0;
	int is_gyroscope_data_ready = 0;
	int is_acceleration_data_ready = 0;
	uint8_t dataready_bytes[4]; /* first 2 are dummy bytes required by fc_bmi323_readregisters() */
	HAL_StatusTypeDef status = fc_bmi323_readregisters(device, FC_BMI323_REGISTER_STATUS, dataready_bytes, 2);
	if (status != HAL_OK) {
		return 42;
	}
	uint16_t dataready = fc_bytes2uint16(dataready_bytes[3], dataready_bytes[2]);
	if (dataready & (1 << 5)) {
		is_temperature_data_ready = 1;
	}
	if (dataready & (1 << 6)) {
		is_gyroscope_data_ready = 1;
	}
	if (dataready & (1 << 7)) {
		is_acceleration_data_ready = 1;
	}

	/* TODO: read data if ready */
	/* if the dataready bits are clear on read, are we able to read all 3 data at once? */
	if (is_acceleration_data_ready) {

		/* read data */
		uint8_t temperature_bytes[8]; /* 2 dummy bytes + 16-bit x/y/z */
		status = fc_bmi323_readregisters(device, FC_BMI323_REGISTER_ACC_DATA_X, temperature_bytes, sizeof(temperature_bytes));
		if (status != HAL_OK) {
			return 42;
		}

		/* multiplier to convert an int16_t to the sensor range
		 * (65535 is the total range of an int16_t) */
		float scale = (FC_BMI323_ACC_RANGE_MAX - FC_BMI323_ACC_RANGE_MIN) / 65535.0f;

		/* convert x acceleration */
		int16_t x = fc_bytes2int16(temperature_bytes[3], temperature_bytes[2]);
		device->acceleration_x = ((float) x) * scale;

		/* convert y acceleration */
		int16_t y = fc_bytes2int16(temperature_bytes[5], temperature_bytes[4]);
		device->acceleration_y = ((float) y) * scale;

		/* convert z acceleration */
		int16_t z = fc_bytes2int16(temperature_bytes[7], temperature_bytes[6]);
		device->acceleration_z = ((float) z) * scale;

		/* set sensor time */
		device->acceleration_timestamp = osKernelGetTickCount();
	}

	if (is_gyroscope_data_ready) {

		/* read data */
		uint8_t gyroscope_bytes[8]; /* 2 dummy bytes + 16-bit x/y/z */
		status = fc_bmi323_readregisters(device, FC_BMI323_REGISTER_GYR_DATA_X, gyroscope_bytes, sizeof(gyroscope_bytes));
		if (status != HAL_OK) {
			return 42;
		}

		/* multiplier to convert an int16_t to the sensor range
		 * (65535 is the total range of an int16_t) */
		float scale = (FC_BMI323_GYR_RANGE_MAX - FC_BMI323_GYR_RANGE_MIN) / 65535.0f;

		/* convert gyroscope x */
		int16_t x = fc_bytes2int16(gyroscope_bytes[3], gyroscope_bytes[2]);
		device->gyroscope_x = ((float) x) * scale;

		/* convert gyroscope y */
		int16_t y = fc_bytes2int16(gyroscope_bytes[5], gyroscope_bytes[4]);
		device->gyroscope_y = ((float) y) * scale;

		/* convert gyroscope z */
		int16_t z = fc_bytes2int16(gyroscope_bytes[7], gyroscope_bytes[6]);
		device->gyroscope_z = ((float) z) * scale;

		/* set sensor time */
		device->acceleration_timestamp = osKernelGetTickCount();
	}

	if (is_temperature_data_ready) {

		/* read data */
		uint8_t temperature_bytes[4]; /* 2 dummy bytes + 16-bit temperature */
		status = fc_bmi323_readregisters(device, FC_BMI323_REGISTER_TEMP_DATA, temperature_bytes, sizeof(temperature_bytes));
		if (status != HAL_OK) {
			return 42;
		}

		/* convert temperature */
		int16_t temp = fc_bytes2int16(temperature_bytes[3], temperature_bytes[2]);
		device->temperature = ((float) temp); /* TODO: finish conversions and fix range conversions to account for negatives */
		/* see datasheet pg. 26 for info on temperature ranges/conversion */
	}

	/* TODO: finish */

	return 0;
}

HAL_StatusTypeDef fc_bmi323_readregisters(struct fc_bmi323 *device, uint8_t reg, uint8_t *data, uint8_t length) {
	assert(length >= 4); /* minimum possible length = 2 dummy bytes + 1 register's worth of data = 4 bytes*/

	HAL_StatusTypeDef status;

	/* first, send the register (datasheet pg. 223) */
	status = HAL_I2C_Master_Transmit(device->i2c_handle, FC_BMI323_I2C_DEVICE_ID, &reg, sizeof (reg), 100);
	if (status != HAL_OK)
	{
		return status;
	}

	/* then, receive the data. 2 dummy bytes will be received first. (datasheet pg. 223) */
	status = HAL_I2C_Master_Receive(device->i2c_handle, FC_BMI323_I2C_DEVICE_ID, data, length, 100);
	if (status != HAL_OK)
	{
		return status;
	}

	return HAL_OK;
}

HAL_StatusTypeDef fc_bmi323_writeregisters(struct fc_bmi323 *device, uint8_t reg, uint8_t *data, uint8_t length) {
	return HAL_I2C_Mem_Write(device->i2c_handle, FC_BMI323_I2C_DEVICE_ID, reg, sizeof (reg), data, length, 100);
}
