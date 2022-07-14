/*
 * DistanceMeasuringSystem.c
 *
 *  Created on: May 31, 2022
 *      Author: The Bayoumi
 */

#include "ultrasonic.h"
#include "lcd.h"


int main(void)
{
	sei();
	LCD_init();
	Ultrasonic_init();

	uint32 Distance = 0;

	LCD_displayString("Dist. =");
	LCD_displayStringRowColumn(0,13,"cm");
	while(1)
	{
		Distance = Ultrasonic_ReadDistance();

		LCD_moveCursor(0,9);

		LCD_intgerToString(Distance);

		if(Distance<100)
		{
			LCD_displayCharacter(' ');
		}
	}
}
