#include <avr/io.h>

#include "timer.h"

void timer0_init(void)
{
	TCCR0A |= (1<<WGM01);	//CTC mode
	TCCR0B |= (1<<CS00);	//Presc = 1
	OCR0A =  79;
	TIMSK0 |= (1<<OCIE0A);
}
