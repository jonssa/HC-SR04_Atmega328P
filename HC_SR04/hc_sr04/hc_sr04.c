/*
 * hc_sr04.c
 *
 *  Created on: 16 cze 2020
 *      Author: Macias
 */

#include <avr/io.h>
#include <util/delay.h>

#include "hc_sr04.h"
#include "../main.h"
#include "../timer/timer.h"

volatile uint8_t meas_done = 0;

void HC_startmeas(void)
{
	TRIG_ON;
	_delay_us(10);
	TRIG_OFF;
}

void HC_init(void)
{
	TRIG_DIR |= TRIG;
	TRIG_OFF;

	LED_DIR |= LED_B;
	LED_OFF;

	LED_DIR |= LED_R;
}

void HC_measure(uint8_t meas_done, uint8_t *distance, uint8_t *distance_dec)
{
	HC_startmeas();
	if(meas_done)
	{
		*distance = timeready*10/58;
		*distance_dec = (timeready*100/58) % 10;
	}
}
