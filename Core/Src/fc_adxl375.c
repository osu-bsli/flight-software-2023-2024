/*
 * fc_adxl375.c
 *
 *  Created on: Sep 24, 2023
 *      Author: bsli
 */

#include "fc_adxl375.h"

HAL_StatusTypeDef fc_adxl375_writeregister(struct fc_adxl375 *device, uint8_t reg, uint8_t *data) {
	return HAL_I2C_Mem_Write(device->i2c_handle, FC_ADXL375_I2C_DEVICE_ID, reg, sizeof(reg), data, 1, 100);
}
