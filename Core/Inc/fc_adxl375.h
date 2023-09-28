/*
 * fc_adxl375.h
 *
 *  Created on: Sep 24, 2023
 *      Author: bsli
 */

#ifndef INC_FC_ADXL375_H_
#define INC_FC_ADXL375_H_

/* i2c constants */
#define FC_ADXL375_I2C_DEVICE_ID     0x1Du; /* (pg. 18) if ALT_ADDRESS pin is low, these change */
#define FC_ADXL375_I2C_WRITE_ADDRESS 0x3Au;
#define FC_ADXL375_I2C_READ_ADDRESS  0x3Bu;

/* register constants (pg. 20) */
#define FC_ADXL375_REGISTER_DEVID            0x00u;
#define FC_ADXL375_REGISTER_THRESH_SHOCK     0x1Du;
#define FC_ADXL375_REGISTER_OFSX             0x1Eu;
#define FC_ADXL375_REGISTER_OFSY             0x1Fu;
#define FC_ADXL375_REGISTER_OFSZ             0x20u;
#define FC_ADXL375_REGISTER_DUR              0x21u;
#define FC_ADXL375_REGISTER_LATENT           0x22u;
#define FC_ADXL375_REGISTER_WINDOW           0x23u;
#define FC_ADXL375_REGISTER_THRESH_ACT       0x24u;
#define FC_ADXL375_REGISTER_THRESH_INACT     0x25u;
#define FC_ADXL375_REGISTER_TIME_INACT       0x26u;
#define FC_ADXL375_REGISTER_ACT_INACT_CTL    0x27u;
#define FC_ADXL375_REGISTER_SHOCK_AXES       0x2Au;
#define FC_ADXL375_REGISTER_ACT_SHOCK_STATUS 0x2Bu;
#define FC_ADXL375_REGISTER_BW_RATE          0x2Cu;
#define FC_ADXL375_REGISTER_POWER_CTL        0x2Du;
#define FC_ADXL375_REGISTER_INT_ENABLE       0x2Eu;
#define FC_ADXL375_REGISTER_INT_MAP          0x2Fu;
#define FC_ADXL375_REGISTER_INT_SOURCE       0x30u;
#define FC_ADXL375_REGISTER_DATA_FORMAT      0x31u;
#define FC_ADXL375_REGISTER_DATAX0           0x32u;
#define FC_ADXL375_REGISTER_DATAX1           0x33u;
#define FC_ADXL375_REGISTER_DATAY0           0x34u;
#define FC_ADXL375_REGISTER_DATAY1           0x35u;
#define FC_ADXL375_REGISTER_DATAZ0           0x36u;
#define FC_ADXL375_REGISTER_DATAZ1           0x37u;
#define FC_ADXL375_REGISTER_FIFO_CTL         0x38u;
#define FC_ADXL375_REGISTER_FIFO_STATUS      0x39u;

/* struct */

struct fc_adxl375 {
	 I2C_HandleTypeDef *i2c_handle;

	 float acceleration_x;
	 float acceleration_y;
	 float acceleration_z;

	 float temperature; /* C */
};

/* functions */
HAL_StatusTypeDef fc_adxl375_readregister(struct fc_adxl375 *device, uint8_t register, uint8_t *data);

#endif /* INC_FC_ADXL375_H_ */
