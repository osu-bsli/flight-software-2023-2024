/*
 * fc_data_processing.h
 *
 *  Created on: Nov 12, 2023
 *      Author: bsli
 */

#ifndef INC_FC_DATA_PROCESSING_H_
#define INC_FC_DATA_PROCESSING_H_

struct fc_processed_data {
	float velocity;
	float altitude;
	float air_density;
	float heading;
	float acceleration;
};

/* Functions */
int fc_process_sensor_data(struct fc_processed_data *data);



#endif /* INC_FC_DATA_PROCESSING_H_ */
