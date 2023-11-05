/*
 * fc_bm1422.h
 *
 *  Created on: Nov 5, 2023
 *      Author: bsli
 */

#ifndef INC_FC_BM1422_H_
#define INC_FC_BM1422_H_

// i2c constants (pg. 9-10)
#define FC_BM1422_I2C_LOW		0x0Eu		     // NOT bit-shifted
#define FC_BM1422_I2C_HIGH		0x0Fu			 // NOT bit-shifted

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
	int *i2c_owner;
	int i2c_is_done;
	int i2c_is_error;

	float x_data;
	float y_data;
	float z_data;
};

#endif /* INC_FC_BM1422_H_ */
