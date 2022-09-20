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
void LED_blink_halfSecond(uint8_t ledPort, uint8_t ledPin)
{
		delayHalfSecond();
		GPIO_toggle(ledPin,ledPort);
	//_delay_ms(blinkTime); //replace later with timer delay function 
}
void delayHalfSecond(void)
{
	// I implement this 5 second delay using timer1 since it's 16 bit and it's
	//better to have lowest amount of interrupts , for example if we use max prescaler = 1024
	// and we need to count to 4883 which is required for 5 sec interrupt 8 bit timers 0,2
	// will have a big number of interrupts to make it to 5 seconds which is not the best
	
	sei();
	
	// timer prescaler will be 1024 so we reach 5 seconds or 5000 ms in 4883 counts in OCRn
	//(output compare register , n: for any timer)
	st_timerConfig_t timerConfiguration ={0,489,N_1024,timer1,CTC,ENABLE};
	TIMER_setCallback(Led_timerProcessing);
	TIMER_init(&timerConfiguration); // send the init function the config struct we defined above
	//timer TCNTn Register start counting right after we select the prescaler bits
	//which happen last thing in the TIMER_init function
	while(g_interruptCounterLed != 1 )
	{
		// waiting for interrupt to occur hence waiting the desired 5 seconds

	}
	g_interruptCounterLed=0;

	TIMER_reset(timer1);
	
}
void Led_timerProcessing(void)
{

	
	g_interruptCounterLed++;
	

	//when we enter this function means an ovf or CTC interrupt occured
	// so we increment this counter and use polling in the delay functions to wait for the interrupt
	
	
	
	
}