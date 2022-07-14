/*
 * ultrasonic.h
 *
 *  Created on: May 31, 2022
 *      Author: The Bayoumi
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "icu.h"
#include "gpio.h"
#include "std_types.h"
#include <util/delay.h>
#include "common_macros.h"


#define Ultrasonic_Tr_PORT_ID                 PORTB_ID
#define Ultrasonic_Tr_PIN_ID                  PIN5_ID

void Ultrasonic_init(void);

void Ultrasonic_Trigger(void);

uint32 Ultrasonic_ReadDistance(void);

void Ultrasonic_edgeProcessing(void);

#endif /* ULTRASONIC_H_ */
