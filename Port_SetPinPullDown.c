#include "typedefs.h"
#include "dio.h"
#include "port.h"
#include "tm4c123gh6pm.h"

void Port_SetPinPullDown( uint8 port_index ,uint8 pins_mask ,uint8 enable)
{
if ( enable ==1 )
  {
	if(port_index == PORTA_INDEX)		GPIO_PORTA_PDR_R        |= pins_mask; 
	else if(port_index == PORTB_INDEX)	GPIO_PORTB_PDR_R        |= pins_mask; 
	else if(port_index == PORTC_INDEX)	GPIO_PORTC_PDR_R        |= pins_mask;  
	else if(port_index == PORTD_INDEX)	GPIO_PORTD_PDR_R        |= pins_mask; 
	else if(port_index == PORTE_INDEX)	GPIO_PORTE_PDR_R        |= pins_mask; 
	else if(port_index == PORTF_INDEX)	GPIO_PORTF_PDR_R        |= pins_mask; 
  }
else if ( enable == 0)
 {
	
	if(port_index == PORTA_INDEX)		GPIO_PORTA_PDR_R        &= (~pins_mask); 
	else if(port_index == PORTB_INDEX)	GPIO_PORTB_PDR_R        &= (~pins_mask); 
	else if(port_index == PORTC_INDEX)	GPIO_PORTC_PDR_R        &= (~pins_mask);  
	else if(port_index == PORTD_INDEX)	GPIO_PORTD_PDR_R        &= (~pins_mask); 
	else if(port_index == PORTE_INDEX)	GPIO_PORTE_PDR_R        &= (~pins_mask); 
	else if(port_index == PORTF_INDEX)	GPIO_PORTF_PDR_R        &= (~pins_mask);

  }
}