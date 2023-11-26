/*
 * fc_status_codes.h
 *
 *  Created on: Nov 15, 2023
 *      Author: amber
 */

#ifndef INC_FC_STATUS_CODES_H_
#define INC_FC_STATUS_CODES_H_

/* Universal Statuses for all drivers */

typedef enum{
	FC_STATUS_SUCCESS = 0x00,
	FC_STATUS_ERROR = 0x01,
	FC_STATUS_TIMEOUT = 0x02,
	FC_STATUS_INVALID_DATA = 0x03
} FC_STATUS;

#endif /* INC_FC_STATUS_CODES_H_ */
