/*
 * Application.h
 *
 * Created: 14/09/2022 04:17:52 PM
 *  Author: main user
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_
// includes from other used drivers

#include <avr/io.h>
#include "../Microcontroller Abstraction Layer\gpio\gpio.h"
#include "../Microcontroller Abstraction Layer\External_Interrupts\External_interrupt.h"
#include "../Microcontroller Abstraction Layer\Timer\timer.h"
#include "../Hardware Abstraction Layer\led.h"

//macros to represent LED pins if their color and pedestrian or cars
#define PEDESTRIAN_PORT PORT_A
#define PEDESTRIAN_GREEN_LED PA0 //PIN 0 port A
#define PEDESTRIAN_RED_LED  PA1//PIN 1 port A
#define PEDESTRIAN_YELLOW_LED PA2//PIN 2 port A

#define CARS_PORT PORT_B
#define CARS_GREEN_LED PB0 //PIN 0 port B
#define CARS_RED_LED PB1 //PIN 1port B
#define CARS_YELOW_LED PB2 //PIN 2 port B

#define APPLICATION_LOOP for(;;)

//Enums to represent states or running modes in the application
typedef enum en_mode_t {PEDESTRIAN,CARS}en_mode_t;
typedef enum en_carsLightState_t {RED,GREEN,YELLOW}en_carsLightState_t;

//functions prototypes 

void APP_init(void);
void APP_flow(void);
void timerProcessing(void);
void delayFiveSeconds(void);



#endif /* APPLICATION_H_ */