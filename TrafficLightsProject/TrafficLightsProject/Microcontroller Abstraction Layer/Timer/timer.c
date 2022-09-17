/*
 * timer.c
 *
 * Created: 14/09/2022 11:40:28 PM
 *  Author: main user
 */ 

#include "timer.h"
volatile void (*CallBackPtr1) (void)= NULL;

ISR(TIMER0_COMP_vect)
{
	
}
ISR(TIMER0_OVF_vect){}