#include "typedefs.h"
#include "dio.h"
#include "port.h"
#include "tm4c123gh6pm.h"

void Port_Init(uint8 port_index)
{
	SYSCTL->RCGCGPIO |= 0x01 << port_index;
	if(port_index == PORTA_INDEX)
	{
		GPIOA->LOCK |= 0x4C4F434B;
		GPIOA->DEN |= 0xFF;
	}
	else if(port_index == PORTB_INDEX)
	{
		GPIOB->LOCK |= 0x4C4F434B;
		GPIOB->DEN |= 0xFF;
	}
	else if(port_index == PORTC_INDEX)
	{
		GPIOC->LOCK |= 0x4C4F434B;
		GPIOC->DEN |= 0xFF;
	}
	else if(port_index == PORTD_INDEX)
	{
		GPIOD->LOCK |= 0x4C4F434B;
		GPIOD->DEN |= 0xFF;
	}
	else if(port_index == PORTE_INDEX)
	{
		GPIOE->LOCK |= 0x4C4F434B;
		GPIOE->DEN |= 0x3F;
	}
	else if(port_index == PORTF_INDEX)
	{
		GPIOF->LOCK |= 0x4C4F434B;
		GPIOF->DEN |= 0x1F;
	}
}
