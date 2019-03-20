#include "typedefs.h"
#include "dio.h"
#include "port.h"
#include "tm4c123gh6pm.h"
#include "tm4c123gh6pmm.h"

void InterruptInit(void)
{
	GPIO_PORTA_IM_R &= ~0xE0;
	GPIO_PORTA_IS_R &= ~0xE0;
	GPIO_PORTA_IBE_R &= ~0xE0;
	GPIO_PORTA_IEV_R &= ~0x60;
	GPIO_PORTA_IEV_R |= 0x80;
	GPIO_PORTA_ICR_R |= 0xE0;
	GPIO_PORTA_IM_R |= 0xE0;
	NVIC_EN0_R |= 0x01 << 0;
	
	GPIO_PORTF_IM_R &= ~0x01;
	GPIO_PORTF_IS_R &= ~0x01;
	GPIO_PORTF_IBE_R &= ~0x01;
	GPIO_PORTF_IEV_R &= ~0x01;
	GPIO_PORTF_ICR_R |= 0x01;
	GPIO_PORTF_IM_R |= 0x01;
	NVIC_EN0_R |= 0x01 << 30;
}
