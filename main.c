#include "tm4c123gh6pm.h"
#include "dio.h"
#include "port.h"
#include "typedefs.h"
#include "project.h"
#include "tm4c123gh6pmm.h"

int main()
{
	
	
	uint16 counter=0;
	
	//FLAGS
	uint8 flag_inc=0;
	uint8 flag_dec=0;
	uint8 flag_reset=0;
	
	//FUNCTIONS INITILLIZATION
	systick_init();
	SwitchInit();
	SevenSegmentInit ();
	
	
	while(1){
		
		//FLAGS RESET
		if(flag_dec == 1 && (GPIO_PORTA_DATA_R & (0x01 << 5)))
				flag_dec = 0;
		if(flag_inc == 1 && (GPIO_PORTA_DATA_R & (0x01 << 6)))
			flag_inc = 0;
		if(flag_reset ==1 && (GPIO_PORTA_DATA_R & (0x01 << 7 )))
			 flag_reset =0;
		
		//DECREMENT
		if(!(GPIO_PORTA_DATA_R & (0x01 << 5)))
		{
			if(flag_dec == 0)
			{
				Systick_wait10ms(20);
				if(!(GPIO_PORTA_DATA_R & (0x01 << 5 )) && flag_dec == 0)
				{
					counter--;
					if(counter == 0xFFFF)
						counter = 999;
					display(counter);
					flag_dec = 1;
				}
			}
		}
		
		
		//INCREMENT
		else if(!(GPIO_PORTA_DATA_R & (0x01 << 6)))
		{	
			if(flag_inc == 0)
			{
				do{
					counter++;
					display(counter);
					Systick_wait10ms(200);
				}while(!(GPIO_PORTA_DATA_R & (0x01 << 6 )));
				flag_inc = 1;
			}
		}
	

		
		//RESET 
		else if (!(GPIO_PORTA_DATA_R & (0x01 << 7 )))
		{
			while(!(GPIO_PORTA_DATA_R & (0x01 << 7 ))) ;
			if(flag_reset ==0)
			{
				if(GPIO_PORTA_DATA_R & (0x01 << 7 ))
					{
						counter = 0;
						display (counter);
					}
					flag_reset=1;
			}
		}

	}
}
