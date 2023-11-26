/*
 * fc_airbrake_control.h
 *
 *  Created on: Nov 12, 2023
 *      Author: bsli
 */

#ifndef INC_FC_AIRBRAKE_CONTROL_H_
#define INC_FC_AIRBRAKE_CONTROL_H_

#include "fc_data_processing.h"


/* Functions */
float predict_apogee(struct fc_processed_data *data);
float predict_drag(struct fc_processed_data *data, float apogee);
float convert_drag_to_area(float drag);
float convert_area_to_angle(float area, float current_angle);
float convert_angle_to_steps(float angle);



#endif /* INC_FC_AIRBRAKE_CONTROL_H_ */
