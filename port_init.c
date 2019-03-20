#include "typedefs.h"
#include "dio.h"
#include "port.h"
#include "tm4c123gh6pm.h"

void Port_Init(uint8 port_index)
{
	uint8 delay;
	
	SYSCTL_RCGCGPIO_R |= 0x01 << port_index;
	
	delay = 1;
	delay = 2;
	delay = 3;
	delay = 4;
	
	if(port_index == PORTA_INDEX)
	{
		GPIO_PORTA_LOCK_R |= 0x4C4F434B;
		GPIO_PORTA_CR_R |= 0xFF;
		GPIO_PORTA_AMSEL_R &= ~0xFF;
		GPIO_PORTA_PCTL_R &= ~0xFF;
		GPIO_PORTA_AFSEL_R &= ~0xFF;
		GPIO_PORTA_DEN_R |= 0xFF;
	}
	else if(port_index == PORTB_INDEX)
	{
		GPIO_PORTB_LOCK_R |= 0x4C4F434B;
		GPIO_PORTB_CR_R |= 0xFF;
		GPIO_PORTB_AMSEL_R &= ~0xFF;
		GPIO_PORTB_PCTL_R &= ~0xFF;
		GPIO_PORTB_AFSEL_R &= ~0xFF;
		GPIO_PORTB_DEN_R |= 0xFF;
	}
	else if(port_index == PORTC_INDEX)
	{
		GPIO_PORTC_LOCK_R |= 0x4C4F434B;
		GPIO_PORTC_CR_R |= 0xF0;
		GPIO_PORTC_AMSEL_R &= ~0xF0;
		GPIO_PORTC_PCTL_R &= ~0xF0;
		GPIO_PORTC_AFSEL_R &= ~0xF0;
		GPIO_PORTC_DEN_R |= 0xF0;
	}
	else if(port_index == PORTD_INDEX)
	{
		GPIO_PORTD_LOCK_R |= 0x4C4F434B;
		GPIO_PORTD_CR_R |= 0xFF;
		GPIO_PORTD_AMSEL_R &= ~0xFF;
		GPIO_PORTD_PCTL_R &= ~0xFF;
		GPIO_PORTD_AFSEL_R &= ~0xFF;
		GPIO_PORTD_DEN_R |= 0xFF;
	}
	else if(port_index == PORTE_INDEX)
	{
		GPIO_PORTE_LOCK_R |= 0x4C4F434B;
		GPIO_PORTE_CR_R |= 0x3F;
		GPIO_PORTE_AMSEL_R &= ~0xFF;
		GPIO_PORTE_PCTL_R &= ~0xFF;
		GPIO_PORTE_AFSEL_R &= ~0xFF;
		GPIO_PORTE_DEN_R |= 0x3F;
	}
	else if(port_index == PORTF_INDEX)
	{
		GPIO_PORTF_LOCK_R |= 0x4C4F434B;
		GPIO_PORTF_CR_R |= 0x1F;
		GPIO_PORTF_AMSEL_R &= ~0xFF;
		GPIO_PORTF_PCTL_R &= ~0xFF;
		GPIO_PORTF_AFSEL_R &= ~0xFF;
		GPIO_PORTF_DEN_R |= 0x1F;
	}
}
