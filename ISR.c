#include "tm4c123gh6pm.h"
#include "dio.h"
#include "port.h"
#include "typedefs.h"
#include "project.h"
#include "tm4c123gh6pmm.h"

//global variables
static volatile uint16 counter=0;



void GPIOA_Handler ()
{
	//INCREMENT
	if(GPIO_PORTA_RIS_R & (0x01 << 5 ))
		{	
			//considering bouncing effect
			Systick_wait10ms (20);
			if(!(GPIO_PORTA_DATA_R & (0x01 << 5 )))
			{
		do{
			counter ++;
			if (counter== 1000)		counter=0;
			
			display (counter);
			Systick_wait10ms(200);
			}
		while(!(GPIO_PORTA_DATA_R & (0x01 << 5 )));
		}
	}
 //DECREMENT
	else if( GPIO_PORTA_RIS_R & (0x01 << 6 ))
	{
		//considering bouncing effect
		Systick_wait10ms (20);
		if(!(GPIO_PORTA_DATA_R & (0x01 << 6 )))
		{
			if(counter == 0) 	counter = 999;
		  else 						 	counter--;
		display (counter);
	}
}
	
	//RESET 
	else if(GPIO_PORTA_RIS_R & (0x01 << 7 ))
	{
		//considering bouncing effect
		Systick_wait10ms (20);
		if(GPIO_PORTA_DATA_R & (0x01 << 7 ))
		{
		counter = 0;
		display (counter);
		}
	}
	GPIO_PORTA_ICR_R |= 0xFF; //CLEARING FLAG OF INTERRUPT 
}
