/*
 * fc_ms5607.h
 *
 *  Created on: Nov 5, 2023
 *      Author: bsli
 */

/*THIS IS TO BE EDITED- EVERYTHING BELOW IS JUST A TEMPLATE FOR NOW */


#ifndef INC_FC_ADXL375_H_
#define INC_FC_ADXL375_H_

#include "stm32h7xx_hal.h"

/* i2c constants---> THIS STILL NEEDS TO BE FIXED*/
#define FC_ADXL375_I2C_DEVICE_ID     0x1Du /* (pg. 18) if ALT_ADDRESS pin is low, these change */
#define FC_ADXL375_I2C_WRITE_ADDRESS 0x3Au
#define FC_ADXL375_I2C_READ_ADDRESS  0x3Bu

/* constants (pg. 10) */
#define FC_MS5607_CONSTANT_RESET            		0x1Eu
#define FC_MS5607_CONSTANT_CONVERTD1_OSR256     	0x40u
#define FC_MS5607_CONSTANT_CONVERTD1_OSR512     	0x42u
#define FC_MS5607_CONSTANT_CONVERTD1_OSR1024        0x44u
#define FC_MS5607_CONSTANT_CONVERTD1_OSR2048        0x46u
#define FC_MS5607_CONSTANT_CONVERTD1_OSR4096        0x48u
#define FC_MS5607_CONSTANT_CONVERTD1_OSR256         0x50u
#define FC_MS5607_CONSTANT_CONVERTD1_OSR512         0x52u
#define FC_MS5607_CONSTANT_CONVERTD1_OSR1024        0x54u
#define FC_MS5607_CONSTANT_CONVERTD1_OSR2048     	0x56u
#define FC_MS5607_CONSTANT_CONVERTD1_OSR4096      	0x58u
#define FC_MS5607_CONSTANT_ADC_READ    				0x00u
#define FC_MS5607_CONSTANT_PROM_READ				0xA0u

/* PROM addresses for conversion constants C1-C6 */
#define FC_MS5607_CONSTANT_PROM_READC1				0xA2u // Pressure sensitivity
#define FC_MS5607_CONSTANT_PROM_READC2				0xA4u // Pressure offset
#define FC_MS5607_CONSTANT_PROM_READC3				0xA6u // Temperature coefficient of pressure sensitivity
#define FC_MS5607_CONSTANT_PROM_READC4				0xA8u // Temperature coefficient of pressure offset
#define FC_MS5607_CONSTANT_PROM_READC5				0xAAu // Reference Temperature
#define FC_MS5607_CONSTANT_PROM_READC6				0xACu // Temperature coefficient of the temperature

/* struct */

struct fc_adxl375 {
	 I2C_HandleTypeDef *i2c_handle;

	 float acceleration_x;
	 float acceleration_y;
	 float acceleration_z;
};

/* functions */
int adxl375_initialize(struct fc_adxl375 *device, I2C_HandleTypeDef *i2c_handle);
int adxl375_process(struct fc_adxl375 *device);

HAL_StatusTypeDef fc_adxl375_readregister(struct fc_adxl375 *device, uint8_t reg, uint8_t *data);
HAL_StatusTypeDef fc_adxl375_readregisters(struct fc_adxl375 *device, uint8_t reg, uint8_t *data, uint8_t length);
HAL_StatusTypeDef fc_adxl375_writeregister(struct fc_adxl375 *device, uint8_t reg, uint8_t *data);

#endif /* INC_FC_ADXL375_H_ */
