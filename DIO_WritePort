#include "typedefs.h"
#include "dio.h"
#include "port.h"
#include "tm4c123gh6pm.h"

void DIO_WritePort(uint8 port_index, uint8 pins_mask, Dio_LevelType pins_level)
{
  if(pins_level == STD_HIGH)
  {
    if(port_index == PORTA_INDEX)		    GPIO_PORTA_DATA_R |= pins_mask;
    else if(port_index == PORTB_INDEX)	GPIO_PORTB_DATA_R |= pins_mask;
    else if(port_index == PORTC_INDEX)	GPIO_PORTC_DATA_R |= pins_mask;
    else if(port_index == PORTD_INDEX)	GPIO_PORTD_DATA_R |= pins_mask;
    else if(port_index == PORTE_INDEX)	GPIO_PORTE_DATA_R |= pins_mask;
    else if(port_index == PORTF_INDEX)	GPIO_PORTF_DATA_R |= pins_mask;
  }
  
  else if(pins_level == STD_LOW)
  {
    if(port_index == PORTA_INDEX)		    GPIO_PORTA_DATA_R &= ~pins_mask;
    else if(port_index == PORTB_INDEX)	GPIO_PORTB_DATA_R &= ~pins_mask;
    else if(port_index == PORTC_INDEX)	GPIO_PORTC_DATA_R &= ~pins_mask;
    else if(port_index == PORTD_INDEX)	GPIO_PORTD_DATA_R &= ~pins_mask;
    else if(port_index == PORTE_INDEX)	GPIO_PORTE_DATA_R &= ~pins_mask;
    else if(port_index == PORTF_INDEX)	GPIO_PORTF_DATA_R &= ~pins_mask;
  }
}
