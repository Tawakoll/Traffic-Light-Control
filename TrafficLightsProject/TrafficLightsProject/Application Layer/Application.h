/*
 * Application.h
 *
 * Created: 14/09/2022 04:17:52 PM
 *  Author: main user
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

// includes from other used drivers
#include "Microcontroller Abstraction Layer\gpio\gpio.h"
#include "Microcontroller Abstraction Layer\External_Interrupts\External_interrupt.h"
#include "Microcontroller Abstraction Layer\Timer\timer.h"
#include "Hardware Abstraction Layer\led.h"

//Enums to represent states or running modes in the application
typedef enum en_mode_t {PEDESTRIAN,CARS}en_mode_t;
typedef enum en_lightState_t {RED,GREEN,YELLOW}en_lightState_t;



#endif /* APPLICATION_H_ */