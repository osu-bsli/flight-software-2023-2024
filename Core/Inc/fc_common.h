/*
 * fc_common.h
 *
 *  Created on: Oct 21, 2023
 *      Author: bsli
 */

#ifndef INC_FC_COMMON_H_
#define INC_FC_COMMON_H_

#include "stm32h7xx_hal.h"
#include "cmsis_os.h"

/* constants for tracking which task is currently using an i2c device */
#define FC_I2C_OWNER_MAIN 0
#define FC_I2C_OWNER_FC_ADXL375 1
#define FC_I2C_OWNER_FC_BM1422 2

#endif /* INC_FC_COMMON_H_ */
