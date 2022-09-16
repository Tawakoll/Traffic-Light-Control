/*
 * gpio.h
 *
 * Created: 11/09/2022 02:10:05 PM
 *  Author: main user
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include <avr/io.h>
#include "D:\Traffic Lights Embedded Project\TrafficLightsProject\TrafficLightsProject\types.h"

// all internal driver typedefs
// all driver macros
// all driver macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//Pin numbers enum
enum pinNo {PIN_0,PIN_1,PIN_2,PIN_3,PIN_4,PIN_5,PIN_6,PIN_7,};

//direction enum
enum dir {INPUT, OUTPUT};
	
//logic values
enum logicValue{ LOW,HIGH};

// all driver function prototypes
void GPIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction); // Initialize GPIO direction
void GPIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value); // Write data to GPIO
void GPIO_toggle(uint8_t pinNumber, uint8_t portNumber); // toggle GPIO
void GPIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value); // Read GPIO

void GPIO_setPortDirection(uint8_t portNumber, uint8_t portDir); // set port direction by using a 1 byte value ex : 0xFF all port output 0x00 all port input 
void GPIO_writePort(uint8_t portNumber, uint8_t portValue); // set port value output or all internal pull up
void GPIO_readPort(uint8_t portNumber, uint8_t* portValue); // read port value and save it into a pointer to uint8_t

#endif /* GPIO_H_ */