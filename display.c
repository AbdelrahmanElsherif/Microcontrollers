#include "tm4c123gh6pm.h"
#include "dio.h"
#include "port.h"
#include "typedefs.h"
#include "project.h"
#include "tm4c123gh6pmm.h"

void display (uint16 counter )
{
	GPIO_PORTD_DATA_R &= ~0x0F;
	GPIO_PORTE_DATA_R &= ~0x0F;
	GPIO_PORTB_DATA_R &= ~0x0F;
	GPIO_PORTD_DATA_R |= (uint8)((uint8)(counter %10)) & 0x0F;
	GPIO_PORTE_DATA_R |= (uint8)((uint8)((uint8)(counter/10)%10)) & 0x0F;
	GPIO_PORTB_DATA_R |= (uint8)((uint8)((uint8)(counter/100)%10)) & 0x0F;
	if(GPIO_PORTD_DATA_R & 0x01)
	{
		GPIO_PORTB_DATA_R |= 0x01 << 6;
	}
	else
	{
		GPIO_PORTB_DATA_R &= ~(0x01 << 6);
	}
	if(GPIO_PORTD_DATA_R & 0x02)
	{
		GPIO_PORTB_DATA_R |= 0x01 << 7;
	}
	else
	{
		GPIO_PORTB_DATA_R &= ~(0x01 << 7);
	}
}
