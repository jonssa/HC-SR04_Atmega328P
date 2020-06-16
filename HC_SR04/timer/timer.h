/*
 * timer.h
 *
 *  Created on: 16 cze 2020
 *      Author: Macias
 */

#ifndef TIMER_TIMER_H_
#define TIMER_TIMER_H_

void timer0_init(void);

volatile uint8_t nextedge;
volatile uint16_t timertime;
volatile uint16_t timeready;

#endif /* TIMER_TIMER_H_ */
