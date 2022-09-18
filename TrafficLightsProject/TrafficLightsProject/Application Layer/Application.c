/*
* Application.c
*
* Created: 14/09/2022 04:17:39 PM
*  Author: main user
*/



#define FCPU 1000000UL
#include "Application.h"

uint8_t g_interruptCounter=0;

en_mode_t trafficMode=CARS;// Initialize a traffic mode into cars first
en_carsLightState_t carLedState= GREEN;
void APP_InterruptProcessing(void){
	
	if(trafficMode==CARS)
	{
		trafficMode=PEDESTRIAN;
		
		
	}
	else
	{
		trafficMode=CARS;
	}
	
}

void AllLedsOFF(void)
{	LED_off(PEDESTRIAN_PORT,PEDESTRIAN_GREEN_LED);
	LED_off(PEDESTRIAN_PORT,PEDESTRIAN_RED_LED);
	LED_off(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW_LED);
	
	LED_off(CARS_PORT,CARS_GREEN_LED);
	LED_off(CARS_PORT,CARS_RED_LED);
	LED_off(CARS_PORT,CARS_YELOW_LED);
}

void APP_init(void)//Initialize all application functions that are needed to be initialized one time only
{
	
	//Enable global interrupt bit in SREG
	sei();
	//enable global interrupts or by SREG|=(1<<7);
	//Initialize the external interrupt , give values to the configuration struct
	ExInterrupt_ConfigStruct_t externalInterruptConfig = {INT_0,RISING};
	
	//pass to the init function the configuration struct we just initialized
	ExternalInterrupt_init(&externalInterruptConfig);
	
	//set call back function by passing the processing function name which is the address of the function
	ExternalInterrupt_setCallBack(APP_InterruptProcessing);
	
	//Initialize all application LED'S and initialize int0 PD2 pin to input pin
	GPIO_init(PIN_2,PORT_D,INPUT);
	
	LED_init(PEDESTRIAN_PORT,PEDESTRIAN_GREEN_LED);
	LED_init(PEDESTRIAN_PORT,PEDESTRIAN_RED_LED);
	LED_init(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW_LED);
	
	LED_init(CARS_PORT,CARS_GREEN_LED);
	LED_init(CARS_PORT,CARS_RED_LED);
	LED_init(CARS_PORT,CARS_YELOW_LED);
	

}
void APP_flow(void)
{
	APPLICATION_LOOP
	{
		AllLedsOFF(); // in the beginning of each loop turn off all LEDS
		
		switch(trafficMode)
		{
			case CARS: //in cars mode car green is on & pedestrian green on for 5 seconds then yellow blink on then all off
			LED_on(CARS_PORT,CARS_GREEN_LED);
			LED_on(PEDESTRIAN_PORT,PEDESTRIAN_RED_LED);
			carLedState= GREEN;
			delayFiveSeconds();

			
			LED_on(CARS_PORT,CARS_YELOW_LED);
			LED_on(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW_LED);
			carLedState=YELLOW;
			delayFiveSeconds();

			
			AllLedsOFF();
			
			carLedState=RED;
			LED_on(CARS_PORT,CARS_RED_LED);
			LED_on(PEDESTRIAN_PORT,PEDESTRIAN_GREEN_LED);
			delayFiveSeconds();

			
			LED_on(CARS_PORT,CARS_GREEN_LED);
			LED_on(CARS_PORT,CARS_RED_LED);
			LED_on(CARS_PORT,CARS_YELOW_LED);
			delayFiveSeconds();

			
			break;
			
			case PEDESTRIAN:
			AllLedsOFF();
			LED_on(PEDESTRIAN_PORT,PEDESTRIAN_GREEN_LED);
			LED_on(PEDESTRIAN_PORT,PEDESTRIAN_RED_LED);
			LED_on(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW_LED);
			delayFiveSeconds();
			
			AllLedsOFF();
			delayFiveSeconds();

			
			break;
			
			default :
			//error handling
			break;
			
		}
		
	}
	
	
}

void delayFiveSeconds(void)
{
	// I implement this 5 second delay using timer1 since it's 16 bit and it's
	//better to have lowest amount of interrupts , for example if we use max prescaler = 1024
	// and we need to count to 4883 which is required for 5 sec interrupt 8 bit timers 0,2
	// will have a big number of interrupts to make it to 5 seconds which is not the best
	

	
	// timer prescaler will be 1024 so we reach 5 seconds or 5000 ms in 4883 counts in OCRn
	//(output compare register , n: for any timer)
	st_timerConfig_t timerConfiguration ={0,4883,N_1024,timer1,CTC,ENABLE};
	TIMER_setCallback(timerProcessing);
	TIMER_init(&timerConfiguration); // send the init function the config struct we defined above
	//timer TCNTn Register start counting right after we select the prescaler bits
	//which happen last thing in the TIMER_init function
	while(g_interruptCounter<1)
	{
		// waiting for interrupt to occur hence waiting the desired 5 seconds

	}

	TIMER_reset(timer1);
	
}
void timerProcessing(void)
{
	if(g_interruptCounter==1)
	{
		g_interruptCounter=0;
	}
	else{
		g_interruptCounter++;
		
	}
	

	//when we enter this function means an ovf or CTC interrupt occured
	// so we increment this counter and use polling in the delay functions to wait for the interrupt
	
	
	
	
}