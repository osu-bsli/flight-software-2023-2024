/*
 * fc_ms5607.h
 *
 *  Created on: Nov 5, 2023
 *      Author: bsli
 */

/*THIS IS TO BE EDITED- EVERYTHING BELOW IS JUST A TEMPLATE FOR NOW
 *
 *
 * Need to get PROM address
 * Pg. 8 has all the important constants*/

#ifndef INC_FC_MS5607_H_
#define INC_FC_MS5607_H_

#include "stm32h7xx_hal.h"

/* i2c constants---> THIS STILL NEEDS TO BE FIXED*/
#define FC_MS5607_I2C_DEVICE_ID     0x77u /* CSB pulled low, so CSB bit is set to 1 */
#define FC_MS5607_I2C_WRITE_ADDRESS 0xEEu
#define FC_MS5607_I2C_READ_ADDRESS  0xEFu

/* constants (pg. 10)
 * These are updated for ms5067*/
#define FC_MS5607_CONSTANT_RESET            		0x1Eu
#define FC_MS5607_CONSTANT_CONVERTD1_OSR256     	0x40u
#define FC_MS5607_CONSTANT_CONVERTD1_OSR512     	0x42u
#define FC_MS5607_CONSTANT_CONVERTD1_OSR1024        0x44u
#define FC_MS5607_CONSTANT_CONVERTD1_OSR2048        0x46u
#define FC_MS5607_CONSTANT_CONVERTD1_OSR4096        0x48u
#define FC_MS5607_CONSTANT_CONVERTD2_OSR256         0x50u
#define FC_MS5607_CONSTANT_CONVERTD2_OSR512         0x52u
#define FC_MS5607_CONSTANT_CONVERTD2_OSR1024        0x54u
#define FC_MS5607_CONSTANT_CONVERTD2_OSR2048     	0x56u
#define FC_MS5607_CONSTANT_CONVERTD2_OSR4096      	0x58u
#define FC_MS5607_CONSTANT_ADC_READ    				0x00u
#define FC_MS5607_CONSTANT_PROM_READ				0xA0u

/* PROM addresses for conversion constants C1-C6 */
#define FC_MS5607_CONSTANT_PROM_READC1				0xA2u // Pressure sensitivity
#define FC_MS5607_CONSTANT_PROM_READC2				0xA4u // Pressure offset
#define FC_MS5607_CONSTANT_PROM_READC3				0xA6u // Temperature coefficient of pressure sensitivity
#define FC_MS5607_CONSTANT_PROM_READC4				0xA8u // Temperature coefficient of pressure offset
#define FC_MS5607_CONSTANT_PROM_READC5				0xAAu // Reference Temperature
#define FC_MS5607_CONSTANT_PROM_READC6				0xACu // Temperature coefficient of the temperature

/* Max and min reading values to check validity of data collected */
#define FC_MS5607_CONSTANT_PRESSURE_MIN				10.0f //minimun pressure is 10mbar
#define FC_MS5607_CONSTANT_PRESSURE_MAX				1200.0f //minimun pressure is 10mbar
#define FC_MS5607_CONSTANT_TEMPERATURE_MIN			-40.0f //minimun temperature is -40 degrees Celsius
#define FC_MS5607_CONSTANT_TEMPERATURE_MAX			85.0f //maximum temperature is 85 degrees Celsius

/* struct */

struct fc_ms5607 {
	 I2C_HandleTypeDef *i2c_handle; /* the i2c peripheral */
	 int *i2c_owner;                /* pointer to variable tracking who is using the i2c peripheral */
	 int i2c_is_done;               /* i2c completion or error interrupt will set this to true, false otherwise */
	 int i2c_is_error;              /* i2c error interrupt will set this to true, false otherwise */

	 float pressure_mbar; /* pressure in mbar */
	 float temperature_c; /* temperature in degrees Celsius */
};

/* functions */
int ms5607_initialize(struct fc_ms5607 *device, I2C_HandleTypeDef *i2c_handle);
int ms5607_process(struct fc_ms5607 *device);

HAL_StatusTypeDef fc_ms5607_readregister(struct fc_ms5607 *device, uint8_t reg, uint8_t *data);
HAL_StatusTypeDef fc_ms5607_readregisters(struct fc_ms5607 *device, uint8_t reg, uint8_t *data, uint8_t length);
HAL_StatusTypeDef fc_ms5607_writeregister(struct fc_ms5607 *device, uint8_t reg, uint8_t *data);

#endif /* INC_FC_MS5607_H_ */

