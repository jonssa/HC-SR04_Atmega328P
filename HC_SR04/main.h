/*
 * main.h
 *
 *  Created on: 16 cze 2020
 *      Author: Macias
 */

#ifndef MAIN_H_
#define MAIN_H_

#define LED_PORT	PORTB
#define LED_DIR		DDRB
#define LED_B		(1<<PB1)
#define LED_R		(1<<PB2)
#define LED_ON		LED_PORT &= ~LED_B
#define LED_OFF		LED_PORT |=  LED_B

#define LED_TOGGLE	LED_PORT ^=  LED_R

#endif /* MAIN_H_ */
