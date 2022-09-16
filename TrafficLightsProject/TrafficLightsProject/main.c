/*
 * TrafficLightsProject.c
 *
 * Created: 14/09/2022 04:11:22 PM
 * Author : main user
 */ 

#include <avr/io.h>
#include "Application Layer/Application.h"

int main(void)
{
    
	/* Replace with your application code */
	APP_init();

	//APP flow includes application loop

	APP_flow();
	
	
    return 0 ;
}

