/*
 * ultrasonic.c
 *
 *  Created on: May 31, 2022
 *      Author: The Bayoumi
 */

#include "ultrasonic.h"

	uint16 g_timeHigh = 0;
	uint8 g_edgeCount = 0;

void Ultrasonic_edgeProcessing(void)
{
	g_edgeCount++;
	if(g_edgeCount == 1)
	{
		/*
		 * Clear the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		Icu_clearTimerValue();
		/* Detect falling edge */
		Icu_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 2)
	{
		/* Store the High time value */
		g_timeHigh = Icu_getInputCaptureValue();

		Icu_clearTimerValue();
		/* Detect rising edge */
		Icu_setEdgeDetectionType(RISING);
		g_edgeCount=0;
	}
}

void Ultrasonic_init(void)
{

	Icu_ConfigType Config={F_CPU_8,RISING};
	Icu_init(&Config);


	Icu_setCallBack(Ultrasonic_edgeProcessing);

	GPIO_setupPinDirection( Ultrasonic_Tr_PORT_ID, Ultrasonic_Tr_PIN_ID, PIN_OUTPUT);

	GPIO_writePin( Ultrasonic_Tr_PORT_ID, Ultrasonic_Tr_PIN_ID, LOGIC_LOW);
}

void Ultrasonic_Trigger(void)
{
	GPIO_writePin(Ultrasonic_Tr_PORT_ID,Ultrasonic_Tr_PIN_ID,LOGIC_HIGH);

	_delay_us(10);

	GPIO_writePin(Ultrasonic_Tr_PORT_ID,Ultrasonic_Tr_PIN_ID,LOGIC_LOW);
}

uint32 Ultrasonic_ReadDistance(void)
{
	Ultrasonic_Trigger();

	return (g_timeHigh / 57.7);
}

