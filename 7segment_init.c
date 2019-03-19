#include "tm4c123gh6pm.h"
#include "dio.h"
#include "port.h"
#include "typedefs.h"
#include "project.h"
#include "tm4c123gh6pmm.h"

void SevenSegmentInit (){
	 Port_Init(PORTD_INDEX);
	 Port_Init(PORTE_INDEX);
	 Port_Init(PORTB_INDEX);
	
	 Port_SetPinDirection (PORTD_INDEX, 0xFF, PORT_PIN_OUT);
	 Port_SetPinDirection (PORTE_INDEX, 0xFF, PORT_PIN_OUT);
	 Port_SetPinDirection (PORTB_INDEX, 0xFF, PORT_PIN_OUT);
	
}
