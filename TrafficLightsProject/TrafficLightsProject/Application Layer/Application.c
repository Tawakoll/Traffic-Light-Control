/*
 * Application.c
 *
 * Created: 14/09/2022 04:17:39 PM
 *  Author: main user
 */ 


#include "Application.h"

#define PEDESTRIAN_PORT PORT_A
#define PEDESTRIAN_GREEN_LED PA0 //PIN 0 port A
#define PEDESTRIAN_RED_LED  PA1//PIN 1 port A
#define PEDESTRIAN_YELLOW_LED PA2//PIN 2 port A


#define CARS_PORT PORT_B
#define CARS_GREEN_LED PB0 //PIN 0 port B
#define CARS_RED_LED PB1 //PIN 1port B
#define CARS_YELOW_LED PB2 //PIN 2 port B

void APP_init(void)//Initialize all application functions that are needed to be initialized one time only
{
	
	
	LED_init(PEDESTRIAN_PORT,PEDESTRIAN_GREEN_LED);
	LED_init(PEDESTRIAN_PORT,PEDESTRIAN_RED_LED);
	LED_init(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW_LED);
	
	LED_init(CARS_PORT,CARS_GREEN_LED);
	LED_init(CARS_PORT,CARS_RED_LED);
	LED_init(CARS_PORT,CARS_YELOW_LED);
	
}
void APP_flow(void)
{
	
}