/*
 * fc_bmi323.h
 *
 *  Created on: Nov 12, 2023
 *      Author: user
 */

#ifndef INC_FC_BMI323_H_
#define INC_FC_BMI323_H_

#include "stm32h7xx_hal.h"

/* i2c constants */
#define FC_BMI323_I2C_DEVICE_ID	(0x68u << 1) /* depends on how "SDO" pin is wired (datasheet pg. 217) */

/* register constants (datasheet pg. 62) */
#define FC_BMI323_REGISTER_CHIP_ID			0x00u
#define FC_BMI323_REGISTER_ERR_REG			0x01u
#define FC_BMI323_REGISTER_STATUS			0x02u
#define FC_BMI323_REGISTER_ACC_DATA_X		0x03u
#define FC_BMI323_REGISTER_ACC_DATA_Y		0x04u
#define FC_BMI323_REGISTER_ACC_DATA_Z		0x05u
#define FC_BMI323_REGISTER_GYR_DATA_X		0x06u
#define FC_BMI323_REGISTER_GYR_DATA_Y		0x07u
#define FC_BMI323_REGISTER_GYR_DATA_Z		0x08u
#define FC_BMI323_REGISTER_TEMP_DATA		0x09u
#define FC_BMI323_REGISTER_SENSOR_TIME_0	0x0Au
#define FC_BMI323_REGISTER_SENSOR_TIME_1	0x0Bu
#define FC_BMI323_REGISTER_SAT_FLAGS		0x0Cu
#define FC_BMI323_REGISTER_INT_STATUS_INT1	0x0Du
#define FC_BMI323_REGISTER_INT_STATUS_INT2	0x0Eu
#define FC_BMI323_REGISTER_INT_STATUS_IBI	0x0Fu
#define FC_BMI323_REGISTER_FEATURE_IO0		0x10u
#define FC_BMI323_REGISTER_FEATURE_IO1		0x11u
#define FC_BMI323_REGISTER_FEATURE_IO2		0x12u
#define FC_BMI323_REGISTER_FEATURE_IO3		0x13u
#define FC_BMI323_REGISTER_FEATURE_IO_STATUS	0x14u
#define FC_BMI323_REGISTER_FIFO_FILL_LEVEL	0x15u
#define FC_BMI323_REGISTER_FIFO_DATA		0x16u
#define FC_BMI323_REGISTER_ACC_CONF			0x20u
#define FC_BMI323_REGISTER_GYR_CONF			0x21u
#define FC_BMI323_REGISTER_ALT_ACC_CONF		0x28u
#define FC_BMI323_REGISTER_ALT_GYR_CONF		0x29u
#define FC_BMI323_REGISTER_ALT_CONF			0x2Au
/* (datasheet pg. 63) */
#define FC_BMI323_REGISTER_ALT_STATUS		0x2Bu
#define FC_BMI323_REGISTER_FIFO_WATERMARK	0x35u
#define FC_BMI323_REGISTER_FIFO_CONF		0x36u
#define FC_BMI323_REGISTER_FIFO_CTRL		0x37u
#define FC_BMI323_REGISTER_IO_INT_CTRL		0x38u
#define FC_BMI323_REGISTER_INT_CONF			0x39u
#define FC_BMI323_REGISTER_INT_MAP1			0x3Au
#define FC_BMI323_REGISTER_INT_MAP2			0x3Bu
#define FC_BMI323_REGISTER_FEATURE_CTRL		0x40u
#define FC_BMI323_REGISTER_FEATURE_DATA_ADDR	0x41u
#define FC_BMI323_REGISTER_FEATURE_DATA_TX		0x42u
#define FC_BMI323_REGISTER_FEATURE_DATA_STATUS	0x43u
#define FC_BMI323_REGISTER_FEATURE_ENGINE_STATUS	0x45u
#define FC_BMI323_REGISTER_FEATURE_EVENT_EXT	0x47
#define FC_BMI323_REGISTER_IO_PDN_CTRL		0x4Fu
#define FC_BMI323_REGISTER_IO_SPI_IF		0x50u
#define FC_BMI323_REGISTER_IO_PAD_STRENGTH	0x51u
#define FC_BMI323_REGISTER_IO_I2C_IF		0x52u
#define FC_BMI323_REGISTER_IO_ODR_DEVIATION	0x53u
#define FC_BMI323_REGISTER_ACC_DP_OFF_X		0x60u
#define FC_BMI323_REGISTER_ACC_DP_DGAIN_X	0x61u
#define FC_BMI323_REGISTER_ACC_DP_OFF_Y		0x62u
#define FC_BMI323_REGISTER_ACC_DP_DGAIN_Y	0x63u
#define FC_BMI323_REGISTER_ACC_DP_OFF_Z		0x64u
#define FC_BMI323_REGISTER_ACC_DP_DGAIN_Z	0x65u
#define FC_BMI323_REGISTER_GYR_DP_OFF_X		0x66u
#define FC_BMI323_REGISTER_GYR_DP_DGAIN_X	0x67u
#define FC_BMI323_REGISTER_GYR_DP_OFF_Y		0x68u
#define FC_BMI323_REGISTER_GYR_DP_DGAIN_Y	0x69u
#define FC_BMI323_REGISTER_GYR_DP_OFF_Z		0x6Au
/* (datasheet pg. 64) */
#define FC_BMI323_REGISTER_GYR_DP_DGAIN_Z	0x6Bu
#define FC_BMI323_REGISTER_I3C_TC_SYNC_TPH	0x70u
#define FC_BMI323_REGISTER_I3C_TC_SYNC_TU	0x71u
#define FC_BMI323_REGISTER_I3C_TC_SYNC_ODR	0x72u
#define FC_BMI323_REGISTER_CMD				0x7Eu
#define FC_BMI323_REGISTER_CFG_RES			0x7Fu

#define FC_BMI323_ACC_INVALID 0x8000u  /* invalid value for acceleration data (datasheet pg. 22) */
#define FC_BMI323_GYR_INVALID 0x8000u  /* invalid value for gyroscope data (datasheet pg. 24) */
#define FC_BMI323_TEMP_INVALID 0x8000u /* invalid value for temperature data (datasheet pg. 25) */

/* struct */

struct fc_bmi323 {
	 I2C_HandleTypeDef *i2c_handle; /* the i2c peripheral */
	 int *i2c_owner;                /* pointer to variable tracking who is using the i2c peripheral */
	 int i2c_is_done;               /* i2c completion or error interrupt will set this to true, false otherwise */
	 int i2c_is_error;              /* i2c error interrupt will set this to true, false otherwise */

	 /* datasheet pg. 22 */
	 float acceleration_x;
	 float acceleration_y;
	 float acceleration_z;
	 int acceleration_x_is_overflow; /* 1 if overflow (saturated), 0 if not */
	 int acceleration_y_is_overflow;
	 int acceleration_z_is_overflow;

	 float gyroscope_x;
	 float gyroscope_y;
	 float gyroscope_z;
	 int gyroscope_x_is_overflow;
	 int gyroscope_y_is_overflow;
	 int gyroscope_z_is_overflow;

	 float temperature;

	 float time; /* sensor keeps timestamps for measurements (datasheet pg. 25) */
};

/* functions */
int fc_bmi323_initialize(struct fc_bmi323 *device, I2C_HandleTypeDef *i2c_handle, int *i2c_owner);
int fc_bmi323_process(struct fc_bmi323 *device);

/* Starts reading 1 byte from a register.
 * The value won't be ready until the HAL_I2C_MemTxCpltCallback() interrupt handler is called. */
HAL_StatusTypeDef fc_bmi323_readregister(struct fc_bmi323 *device, uint8_t reg, uint8_t *data);

/* Starts reading multiple bytes from a register.
 * Use this to read multiple contiguous registers in one go (aka "burst mode").
 * The value won't be ready until the HAL_I2C_MemTxCpltCallback() interrupt handler is called. */
HAL_StatusTypeDef fc_bmi323_readregisters(struct fc_bmi323 *device, uint8_t reg, uint8_t *data, uint8_t length);

/* Starts writing 1 byte to a register.
 * The value won't be ready until the HAL_I2C_MemRxCpltCallback() interrupt handler is called. */
HAL_StatusTypeDef fc_bmi323_writeregister(struct fc_bmi323 *device, uint8_t reg, uint8_t *data);

#endif /* INC_FC_BMI323_H_ */
