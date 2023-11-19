/*
 * fc_flight_stage.h
 *
 *  Created on: Nov 12, 2023
 *      Author: bsli
 */

#ifndef INC_FC_FLIGHT_STAGE_H_
#define INC_FC_FLIGHT_STAGE_H_

enum flight_stage {
	pre_pad = 0,
	pad = 1,
	boost = 2,
	coast = 3,
	control = 4,
	droque = 5,
	main = 6,
	landed = 7,
};

/* Functions */
enum flight_stage get_flight_stage(struct fc_processed_data *data);


#endif /* INC_FC_FLIGHT_STAGE_H_ */
