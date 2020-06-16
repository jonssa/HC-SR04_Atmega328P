/*
 * main.c
 *
 *  Created on: 15 sty 2020
 *      Author: Macias
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>

#include "i2c/i2c.h"
#include "hd44780_i2c/hd44780_i2c.h"
#include "hc_sr04/hc_sr04.h"
#include "main.h"
#include "timer/timer.h"

int main(void)
{
	i2c_init();
	lcd_init();
	HC_init();
	timer0_init();

	/* INT0 interrupt init*/
	EIMSK |= (1<<INT0);		//interrupt enabled on pin INT0
	EICRA |= (1<<ISC01) | (1<<ISC00);	//rising edge interrupt request on pin INT0 (PD2)
	nextedge = 0;	//falling

	uint8_t distance;
	uint8_t distance_dec;

	sei();

	while(1)
	{
		EICRA |= (1<<ISC01) | (1<<ISC00); //rising edge
		nextedge = 0;

		gotoxy(0,0);
		lcd_str("HC-SR04 sensor");

		HC_measure(meas_done, &distance, &distance_dec);

		gotoxy(1,0);
		lcd_int(distance);
		lcd_writechar('.');
		lcd_int(distance_dec);
		lcd_str(" cm   ");

		_delay_ms(500);
	}
}

ISR(INT0_vect)
{
	if(nextedge == 0) //if next falling (now rising)
	{
		LED_PORT |=  LED_R;
		nextedge = 1;
		EICRA &= ~(1<<ISC00);
		timertime = 0;
	}
	else if(nextedge == 1) //if next rising (now falling)
	{
		timeready = timertime;
		LED_PORT &= ~LED_R;
		nextedge = 0;
		EICRA |= (1<<ISC01) | (1<<ISC00);
		meas_done = 1;
	}
}

ISR(TIMER0_COMPA_vect)
{
	timertime++;
}
