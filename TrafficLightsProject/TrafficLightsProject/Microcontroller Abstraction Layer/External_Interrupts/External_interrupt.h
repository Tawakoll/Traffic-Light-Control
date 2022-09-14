/*
 * External_interrupt.h
 *
 * Created: 14/09/2022 04:19:03 PM
 *  Author: main user
 */ 


#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_
 
#define NULL ((void *)0) //definition of null address

#include <avr/interrupt.h> // to use ISR	 functions
#include <avr/io.h> // to use interrupt registers

/*enums*/
typedef enum {INT_0,INT_1,INT_2}en_selectExInterrupt_t;
typedef enum {FALLING,RISING,ANYCHANGE,LOWLEVEL}en_selectEdge_t;
/************************************************************************/
/*   Global pointer to function                                                                    */
/************************************************************************/ 
volatile void (*CallBackPtr) (void) = NULL ;	//it should be volatile since it is adjusted by ISR which is activated by hardware so we disable optimization
	
	/* configuration struct definition */
typedef struct 
{
	en_selectExInterrupt_t extInt;
	en_selectEdge_t edge;
	
}ExInterrupt_ConfigStruct_t;

/* function prototypes / API'S */
void ExternalInterrupt_init(ExInterrupt_ConfigStruct_t *configStruct);
void ExternalInterrupt_setCallBack( void (*FuncPtr) (void)) ;
void ExternalInterrupt_reset(en_selectExInterrupt_t exinterrupt);


#endif /* EXTERNAL_INTERRUPT_H_ */