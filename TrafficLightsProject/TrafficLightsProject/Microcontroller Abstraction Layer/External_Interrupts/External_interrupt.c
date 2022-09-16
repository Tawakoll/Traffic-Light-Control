/*
* External_interrupt.c
*
* Created: 14/09/2022 04:18:49 PM
*  Author: main user
*/
#include "External_interrupt.h"

/************************************************************************/
/*   Global pointer to function                                                                    */
/************************************************************************/
 volatile void (*CallBackPtr) (void) = NULL ;	//it should be volatile since it is adjusted by ISR which is activated by hardware so we disable optimization
ISR(INT0_vect)
{
	if(CallBackPtr != NULL)
	{
		CallBackPtr();
		
	}
}

ISR(INT1_vect)
{
	if(CallBackPtr != NULL)
	{
		CallBackPtr();
		
	}
}

ISR(INT2_vect)
{
	if(CallBackPtr != NULL)
	{
		CallBackPtr();
		
	}
}

void ExternalInterrupt_init(ExInterrupt_ConfigStruct_t *configStruct)
{
	switch(configStruct->extInt)
	{
		case INT_0 :
		if(configStruct->edge==RISING)
		{
			MCUCR |= (1<<ISC01) | (1<<ISC00) ;//Set bits isc01 & isc00 for to select rising edge
		}
		else if(configStruct->edge==FALLING)
		{
			MCUCR |= (1<<ISC01); //Set bit isc01 for to select falling edge
		}
		
		
		else if(configStruct->edge==ANYCHANGE)
		{
			MCUCR |= (1<<ISC00); //Set bit isc00 for to select int0 on any logical change

		}
		else if(configStruct->edge==LOWLEVEL)
		{
			// no need to adjust MCUCR register because its already initialized to 0 so
			// we already have low level by default
		}
		
		else
		{
			//error handling
		}
		
		GICR |= (1<<INT0); //ENABLE external interrupt 0 in GICR register
		
		break ;
		
		case INT_1 :
		
		if(configStruct->edge==RISING)
		{
			MCUCR |= (1<<ISC11) | (1<<ISC10) ;//Set bits isc11 & isc10  to select RISING edge
		}
		else if(configStruct->edge==FALLING)
		{
			MCUCR |= (1<<ISC11); //Set bit isc11  to select falling edge
		}
		
		
		else if(configStruct->edge==ANYCHANGE)
		{
			MCUCR |= (1<<ISC10); //Set bit isc10  to select int0 on any logical change

		}
		else if(configStruct->edge==LOWLEVEL)
		{
			// no need to adjust MCUCR register because its already initialized to 0 so
			// we already have low level by default
		}
		
		else
		{
			//error handling
		}
		
		GICR |= (1<<INT1); //ENABLE external interrupt 1 in GICR register

		
		break ;
		
		case INT_2 :
		
		if(configStruct->edge==RISING)
		{
			MCUCSR |= (1<<ISC2) ;//Set bit ISC2  to select RISING edge
		}
		else if(configStruct->edge==FALLING)
		{
			//Set bit ISC2  to 0 TO select falling edge 
			// its default is zero so we do nothing
		}
		else
		{
			//error handling
		}
		
		GICR |= (1<<INT2); //ENABLE external interrupt 0 in GICR register
		
		break ;
		
		//default : //for error handling
		
		
	}
	
	
}
void ExternalInterrupt_setCallBack( void (*FuncPtr) (void))
{
	CallBackPtr=FuncPtr;
}

void ExternalInterrupt_reset(en_selectExInterrupt_t exinterrupt)
{	// to reset the external interrupt we simply need to know if its int0 1 or int 2 then
	// we basically reset all the used registers to their initial state which is 0
	
	if(exinterrupt==INT_0 )
	{
		//reset MCUCR and GICR
		MCUCR &=~(1<<ISC01) & ~(1<<ISC00); 
		GICR &=~(1<<INT0);
		 
	}
		else if(exinterrupt==INT_1)
		{		//reset MCUCR and GICR
			MCUCR &=~(1<<ISC11) & ~(1<<ISC10);
			GICR &=~(1<<INT1);
		}
	else if(exinterrupt==INT_2)
	{	//reset MCUCSR and GICR
		MCUCSR &=~(1<<ISC2);
		GICR &=~(1<<INT2);
	}
	else 
	{
		//error handling
	}
	
}
