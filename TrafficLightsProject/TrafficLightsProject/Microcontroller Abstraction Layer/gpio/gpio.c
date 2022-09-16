/*
* gpio.c
*
* Created: 11/09/2022 02:08:50 PM
*  Author: main user
*/



// include .h to use macros and other common libraries included in the header file of the driver
#include "../gpio/gpio.h"

// global variables

// function definitions

void GPIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction) // Initialize GPIO pin direction
{
	switch(portNumber)
	{
		case PORT_A:
		if(direction == INPUT)
		{
			DDRA &= (1 << pinNumber); // input
		}
		else if(direction == OUTPUT)
		{
			DDRA |= (1 << pinNumber); // Output
		}
		else
		{
			//Error handling
		}
		break;
		
		case PORT_B:
		if(direction == INPUT)
		{
			DDRB &= (1 << pinNumber); // input
		}
		else if(direction == OUTPUT)
		{
			DDRB |= (1 << pinNumber); // Output
		}
		else
		{
			//Error handling
		}
		
		
		break;
		
		case PORT_C:
		if(direction == INPUT)
		{
			DDRC &= (1 << pinNumber); // input
		}
		else if(direction == OUTPUT)
		{
			DDRC |= (1 << pinNumber); // Output
		}
		else
		{
			//Error handling
		}
		
		
		break;
		
		case PORT_D:
		if(direction == INPUT)
		{
			DDRD &= (1 << pinNumber); // input
		}
		else if(direction == OUTPUT)
		{
			DDRD |= (1 << pinNumber); // Output
		}
		else
		{
			//Error handling
		}
		
		
		break;
		
		//default : //error handling in case input matches non of the ports values...
		
		
	}
}
void GPIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value) // Write data to GPIO
{
	switch(portNumber)
	{
		case PORT_A:
		if(value == LOW)
		{
			PORTA &= (1 << pinNumber); // LOW
		}
		else if(value == HIGH)
		{
			PORTA |= (1 << pinNumber); // HIGH
		}
		else
		{
			//Error handling
		}
		break;
		
		case PORT_B:
		if(value == LOW)
		{
			PORTB &= (1 << pinNumber); // LOW
		}
		else if(value == HIGH)
		{
			PORTB |= (1 << pinNumber); // HIGH
		}
		else
		{
			//Error handling
		}
		
		
		break;
		
		case PORT_C:
		if(value == LOW)
		{
			PORTC &= (1 << pinNumber); // LOW
		}
		else if(value == HIGH)
		{
			PORTC |= (1 << pinNumber); // HIGH
		}
		else
		{
			//Error handling
		}
		
		
		break;
		
		case PORT_D:
		if(value == LOW)
		{
			PORTD &= (1 << pinNumber); // LOW
		}
		else if(value == HIGH)
		{
			PORTD |= (1 << pinNumber); // HIGH
		}
		else
		{
			//Error handling
		}
		
		
		break;
		
		//default : //error handling in case LOW matches non of the ports values...
		
		
	}
}
void GPIO_toggle(uint8_t pinNumber, uint8_t portNumber) // toggle GPIO
{
	switch(portNumber)
	{
		case PORT_A:
		PORTA ^= (1 << pinNumber); // toggle pin

		
		break;
		
		case PORT_B:
		
		PORTB ^= (1 << pinNumber); // toggle pin
		
		break;
		
		case PORT_C:
		
		PORTC ^= (1 << pinNumber); // toggle pin
		
		
		
		break;
		
		case PORT_D:
		
		PORTD ^= (1 << pinNumber); // toggle pin
		
		
		
		break;
		
		//default : //error handling in case LOW matches non of the ports values...
		
		
	}
}
void GPIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value) // Read GPIO
{
	switch(portNumber)
	{
		case PORT_A:
		*value= ((1 << pinNumber)&PINA)>>pinNumber; // read pin state and adjusts the value

		
		break;
		
		case PORT_B:
		
		*value= ((1 << pinNumber)&PINB)>>pinNumber; // read pin state and adjusts the value

		
		break;
		
		case PORT_C:
		
		*value= ((1 << pinNumber)&PINC)>>pinNumber; // read pin state and adjusts the value
		
		
		
		break;
		
		case PORT_D:
		
		*value= ((1 << pinNumber)&PIND)>>pinNumber; // read pin state and adjusts the value
		
		
		
		break;
		
		//default : //error handling in case LOW matches non of the ports values...
		
		
	}
}

void GPIO_setPortDirection(uint8_t portNumber, uint8_t portDir) // set port direction by using a 1 byte value ex : 0xFF all port output 0x00 all port input
{
	
	switch(portNumber)
	{
		case PORT_A:
		
		break;
		
		case PORT_B:
		
		
		break;
		
		case PORT_C:
		
		
		break;
		
		case PORT_D:
		
		
		break;
		
		//default : //error handling in case input matches non of the ports values...
		
		
	}
	
	
	
	
}
void GPIO_writePort(uint8_t portNumber, uint8_t portValue) // set port value output or all internal pull up
{
	
}
void GPIO_readPort(uint8_t portNumber, uint8_t* portValue) // read port value and save it into a pointer to uint8_t
{
	
}