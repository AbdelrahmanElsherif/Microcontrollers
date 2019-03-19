#include "tm4c123gh6pm.h"
#include "dio.h"
#include "port.h"
#include "typedefs.h"
#include "project.h"
#include "tm4c123gh6pmm.h"

// Delay (in nanoseconds) = (delay * 12.5)
void SysTick_Wait(uint32 delay)
{
	NVIC_ST_RELOAD_R		=delay - 1;
	NVIC_ST_CURRENT_R		=0;
	while(((NVIC_ST_CTRL_R & 0X00010000) == 0));
}

//Delay (in seconds) = (delay/100)

void Systick_wait10ms(uint32 delay)
{
	uint32 i;
	for(i = 0; i < delay; i++)
	SysTick_Wait (20000);
}
