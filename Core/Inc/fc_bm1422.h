/*
 * fc_bm1422.h
 *
 *  Created on: Nov 5, 2023
 *      Author: bsli
 */

#ifndef INC_FC_BM1422_H_
#define INC_FC_BM1422_H_

#include "stm32h7xx_hal.h"

/* I2C constants (Pg. 10) */
#define FC_BM1422_I2C_DEVICE_ID			 (0x0Eu << 1)	// There is a low and high address

// Register constants (pg. 10)
#define FC_BM1422_REGISTER_INFORMATION	  0x0D   // LSB
#define FC_BM1422_REGISTER_WHOIAM		  0x0F
#define FC_BM1422_REGISTER_DATA_X		  0x10	 // LSB
#define FC_BM1422_REGISTER_DATA_Y		  0x12	 // LSB
#define FC_BM1422_REGISTER_DATA_Z		  0x14	 // LSB
#define FC_BM1422_REGISTER_DATASTATUS	  0x18
#define FC_BM1422_REGISTER_CONTROL1		  0x1B
#define FC_BM1422_REGISTER_CONTROL2		  0x1C
#define FC_BM1422 REGISTER_CONTROL3 	  0x1D
#define FC_BM1422_REGISTER_AVERAGETIME    0x40
#define FC_BM1422_REGISTER_CONTROL4       0x5C
#define FC_BM1422_REGISTER_TEMPERATURE	  0x60	 // LSB
#define FC_BM1422_REGISTER_DATAX_OFFSET   0x6C
#define FC_BM1422_REGISTER_DATAY_OFFSET	  0x72
#define FC_BM1422_REGISTER_DATAZ_OFFSET	  0x78
#define FC_BM1422_REGISTER_FINEOUTPUT_X   0x90   // LSB
#define FC_BM1422_REGISTER_FINEOUTPUT_Y   0x92   // LSB
#define FC_BM1422_REGISTER_FINEOUTPUT_Z   0x94   // LSB

/* struct */

struct fc_bm1422 {
	I2C_HandleTypeDef *i2c_handle;	 /* the i2c peripheral */
	int *i2c_owner;
	int i2c_is_done;
	int i2c_is_error;

	/* TODO: figure this out */
	float x_data;
	float y_data;
	float z_data;
};

/* Functions
 * TODO: Add comments */
int fc_bm1422_initialize(struct fc_bm1422 *device, I2C_HandleTypeDef *i2c_handle, int *i2c_owner);
int fc_bm1422_process(struct fc_bm1422 *device);

HAL_StatusTypeDef fc_bm1422_readregister(struct fc_bm1422 *device, uint8_t reg, uint8_t *data);

HAL_StatusTypeDef fc_bm1422_readregisters(struct fc_bm1422 *device, uint8_t reg, uint8_t *data, uint8_t length);

HAL_StatusTypeDef fc_bm1422_writeregister(struct fc_bm1422 *device, uint8_t reg, uint8_t *data);

#endif /* INC_FC_BM1422_H_ */
