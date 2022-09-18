/*
* timer.h
*
* Created: 14/09/2022 11:40:40 PM
*  Author: main user
*/


#ifndef TIMER_H_
#define TIMER_H_

#include <avr/interrupt.h> // to use ISR	 functions
#include <avr/io.h> // to use interrupt registers
#include "D:\Traffic Lights Embedded Project\TrafficLightsProject\TrafficLightsProject\types.h"

typedef enum en_timer_t {timer0,timer1,timer2}en_timer_t;
typedef enum en_timerMode_t {normal,CTC}en_timerMode_t;
typedef enum en_timerInterrupt_t {ENABLE,DISABLE}en_timerInterrupt_t;
typedef enum en_timerPrescaler_t {N_0,N_1,N_8,N_64,N_256,N_1024}en_timerPrescaler_t;

typedef struct st_timerConfig_t{
	uint16_t timerInitialValue;
	uint16_t comparelValue;
	en_timerPrescaler_t prescaler;
	en_timer_t selectedTimer;
	en_timerMode_t timerMode;
	en_timerInterrupt_t timerInterrupt;

	
	
}st_timerConfig_t;

void TIMER_init(st_timerConfig_t * configStruct);
void TIMER_reset(en_timer_t selectedTimer);
void TIMER_setCallback (void (*functionPtr) (void) ) ;



#endif /* TIMER_H_ */