/*
* Application.c
*
* Created: 14/09/2022 04:17:39 PM
*  Author: main user
*/



#define FCPU 1000000UL
#include "Application.h"
#include <avr/io.h>

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
			
			LED_on(CARS_PORT,CARS_YELOW_LED);
			LED_on(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW_LED);
			carLedState=YELLOW;
			
			AllLedsOFF();
			
			carLedState=RED;
			LED_on(CARS_PORT,CARS_RED_LED);
			LED_on(PEDESTRIAN_PORT,PEDESTRIAN_GREEN_LED);
			
			
				LED_on(CARS_PORT,CARS_GREEN_LED);
				LED_on(CARS_PORT,CARS_RED_LED);
				LED_on(CARS_PORT,CARS_YELOW_LED);
			
			
			break;
			
			case PEDESTRIAN:
			AllLedsOFF();
			LED_on(PEDESTRIAN_PORT,PEDESTRIAN_GREEN_LED);
			LED_on(PEDESTRIAN_PORT,PEDESTRIAN_RED_LED);
			LED_on(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW_LED);
			
			break;
			
			default :
			break;
			//error handling
		}
		
	}
	
	
}