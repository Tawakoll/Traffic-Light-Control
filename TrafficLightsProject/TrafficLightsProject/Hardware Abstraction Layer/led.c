/*
 * led.c
 *
 * Created: 12/09/2022 04:17:30 PM
 *  Author: main user
 */ 
#include "led.h"

uint8_t g_interruptCounterLed=0;

/*******************    functions implementations  *****************/
void LED_init(uint8_t ledPort, uint8_t ledPin)
{
	GPIO_init(ledPin,ledPort,OUTPUT);
}

void LED_on(uint8_t ledPort, uint8_t ledPin)
{
	GPIO_write(ledPin,ledPort,HIGH);
}
void LED_off(uint8_t ledPort, uint8_t ledPin)
{
	GPIO_write(ledPin,ledPort,LOW);
}
void LED_blink(uint8_t ledPort, uint8_t ledPin)
{
	
	
		GPIO_toggle(ledPin,ledPort);

}

