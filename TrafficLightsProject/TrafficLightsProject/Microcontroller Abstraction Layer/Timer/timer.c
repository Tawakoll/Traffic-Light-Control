/*
* timer.c
*
* Created: 14/09/2022 11:40:28 PM
*  Author: main user
*/

#include "timer.h"

//call back pointer is assigned the address of the callback function which will be called in the app (higher layer generally)
  void (*CallBackPtr1) (void) = NULL;

//interrupt service routines to be called when interrupt flag is raised
ISR(TIMER0_COMP_vect)
{
	if(CallBackPtr1 != NULL)
	{
		CallBackPtr1();
	}
}
ISR(TIMER0_OVF_vect)
{
	if(CallBackPtr1 != NULL)
	{
		CallBackPtr1();
	}
	
}

ISR(TIMER1_COMPA_vect)
{
	if(CallBackPtr1 != NULL)
	{
		CallBackPtr1();
	}
}
ISR(TIMER1_OVF_vect)
{
	if(CallBackPtr1 != NULL)
	{
		CallBackPtr1();
	}
	
}

ISR(TIMER2_COMP_vect)
{
	if(CallBackPtr1 != NULL)
	{
		CallBackPtr1();
	}
}
ISR(TIMER2_OVF_vect)
{
	if(CallBackPtr1 != NULL)
	{
		CallBackPtr1();
	}
	
}


/************************************************************************/
/*	 functions implementations						                    */
/************************************************************************/
void TIMER_setCallback (void (*functionPtr) (void) )
{
	CallBackPtr1 =functionPtr;
	
}

void TIMER_init(st_timerConfig_t * configStruct)
{
	switch(configStruct->selectedTimer)
	{
		case timer0 :
		
		//initialize timer counter from the config struct entered by the user
		TCNT0 = configStruct->timerInitialValue;
		
		//set FOC0 to 1 since its non PWM mode always
		TCCR0 |= (1<<FOC0);
		
		// WGM00 is always 0(for normal and CTC modes)
		//so  WGM01 if  1 timer is in CTC mode and if 0 normal mode
		if(configStruct->timerMode==CTC)
		{
			//also we need to put compare value in OCR0 if mode is CTC
			OCR0 = configStruct->comparelValue;
			//set WGM01 For CTC mode
			TCCR0 |= (1<<WGM01);
			//Enable interrupt on compare match of timer0
			TIMSK |=(1<<OCIE0);
		}
		else if(configStruct->timerMode==normal)
		{
			TCCR0 &=~ (1<<WGM01); //set bit WGM01 to zero
			//Enable interrupt on overflow of timer0
			TIMSK |=(1<<TOIE0);
		}
		else
		{
			//error handling if input is not enum normal or CTC
		}

		//this equation is used to get the values of the prescaler into the first 3 bits
		// of the TCCR0 register we first & 0xF8 which is 0b11111000 in binary to make sure
		// that the other bits of the TCCR0 register stay the same and we 0 the bits that we want
		// to add the prescaler value to ,,, then we do the same with the prescaler value from the
		//config struct to make sure no more than the first 3 bits is taken from the user...
		// and finally the prescaler value is put into the TCCR0 register by the Or operation as shown
		
		TCCR0 = (TCCR0 & 0xF8) | ( (configStruct->prescaler) & 0x07 );


		break;
		
		case timer1 :
		//initialize timer counter from the config struct entered by the user
		TCNT1 = configStruct->timerInitialValue;
		
		//set FOC1A and FOC1B to 1 since its non PWM mode always
		TCCR1A |= (1<<FOC1A) | (1<<FOC1B);
		
		
		// WGM00 is always 0 (for normal and CTC modes)
		//so  WGM12 if  1 timer is in CTC mode and if 0 normal mode
		if(configStruct->timerMode==CTC)
		{
			//also we need to put compare value in OCR1A if mode is CTC
			OCR1A = configStruct->comparelValue;
			//set WGM12 For CTC mode
			TCCR1B |= (1<<WGM12);
			TCCR1B &=~ (1<<WGM13); //set bit WGM13 to zero

			//Enable interrupt on compare match of timer1
			TIMSK |=(1<<OCIE1A);
		}
		else if(configStruct->timerMode==normal)
		{
			//set WGM12 For NORMAL mode
			TCCR1B &=~ (1<<WGM12);//set bit WGM12 to zero
			TCCR1B &=~ (1<<WGM13); //set bit WGM13 to zero
			//Enable interrupt on overflow of timer0
			TIMSK |=(1<<TOIE1);
		}
		else
		{
			//error handling if input is not enum normal or CTC
		}

		//this equation is used to get the values of the prescaler into the first 3 bits
		// of the TCCR0 register we first & 0xF8 which is 0b11111000 in binary to make sure
		// that the other bits of the TCCR0 register stay the same and we 0 the bits that we want
		// to add the prescaler value to ,,, then we do the same with the prescaler value from the
		//config struct to make sure no more than the first 3 bits is taken from the user...
		// and finally the prescaler value is put into the TCCR0 register by the Or operation as shown
		
		TCCR1B = (TCCR1B & 0xF8) | ( (configStruct->prescaler) & 0x07 );
		
		
		
		
		
		break;
		
		case timer2 :
		
		//initialize timer counter from the config struct entered by the user
		TCNT2 = configStruct->timerInitialValue;
		
		//set FOC2 to 1 since its non PWM mode always
		TCCR2 |= (1<<FOC2);
		
		// WGM20 is always 0 (for normal and CTC modes)
		//so  WGM21 if  1 timer is in CTC mode and if 0 normal mode
		if(configStruct->timerMode==CTC)
		{
			//also we need to put compare value in OCR2 if mode is CTC
			OCR2 = configStruct->comparelValue;
			//set WGM21 For CTC mode
			TCCR2 |= (1<<WGM21);
			//Enable interrupt on compare match of timer0
			TIMSK |=(1<<OCIE2);
		}
		else if(configStruct->timerMode==normal)
		{
			TCCR0 &=~ (1<<WGM21); //set bit WGM21 to zero
			//Enable interrupt on overflow of timer2
			TIMSK |=(1<<TOIE2);
		}
		else
		{
			//error handling if input is not enum normal or CTC
		}

		//this equation is used to get the values of the prescaler into the first 3 bits
		// of the TCCR0 register we first & 0xF8 which is 0b11111000 in binary to make sure
		// that the other bits of the TCCR0 register stay the same and we 0 the bits that we want
		// to add the prescaler value to ,,, then we do the same with the prescaler value from the
		//config struct to make sure no more than the first 3 bits is taken from the user...
		// and finally the prescaler value is put into the TCCR0 register by the Or operation as shown
		
		TCCR2 = (TCCR2 & 0xF8) | ( (configStruct->prescaler) & 0x07 );
		
		
		
		
		break;
		
		
		default ://for error handling if input is not of the specified type
		break;
		
	}
}
void TIMER_reset(en_timer_t selectedTimer)
{
	switch(selectedTimer)
	{
		case timer0 :
		TCCR0=0x00; //reseting the control register will reset everything and stop the timer
		//since the prescaler bits will have 0
		
		// reset the compare register
		OCR0 =0x00 ;
		
		//disable interrupt on CTC and overflow of timer0
		TIMSK &=~(1<<TOIE0) &~(1<<OCIE0);
		
		break;
		
		case timer1 :
		
		TCCR1A=0x00;
		TCCR1B=0x00;
		
		// reset the compare register
		OCR1A = 0x00;
		
		//disable interrupt on Compare out A and overflow of timer1
		TIMSK &=~(1<<OCIE1A) &~(1<<TOIE1);
		break;
		
		case timer2 :
		TCCR2=0x00; //reseting the control register will reset everything and stop the timer
		//since the prescaler bits will have 0
		
		// reset the compare register
		OCR2 =0x00 ;
		
		//disable interrupt on CTC and overflow of timer2
		TIMSK &=~(1<<TOIE2) &~(1<<OCIE2);
		
		break;
		
		default : //for error handling if input is not enum timer0,timer1,timer2
		
		break;
		
	}
	
	
	
}
