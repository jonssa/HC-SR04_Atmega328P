/*
 * hc_sr04.h
 *
 *  Created on: 16 cze 2020
 *      Author: Macias
 */

#ifndef HC_SR04_HC_SR04_H_
#define HC_SR04_HC_SR04_H_

#define TRIG		(1<<PD3)
#define TRIG_PORT	PORTD
#define	TRIG_DIR	DDRD
#define TRIG_OFF	TRIG_PORT &= ~TRIG;
#define TRIG_ON		TRIG_PORT |=  TRIG;

void HC_init(void);
void HC_startmeas(void);
void HC_measure(uint8_t meas_done, uint8_t *distance, uint8_t *distance_dec);

extern volatile uint8_t meas_done;

#endif /* HC_SR04_HC_SR04_H_ */
