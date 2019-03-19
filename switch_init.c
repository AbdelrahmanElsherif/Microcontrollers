#include "tm4c123gh6pm.h"
#include "dio.h"
#include "port.h"
#include "typedefs.h"
#include "tm4c123gh6pmm.h"

void SwitchInit()
{
	Port_Init(PORTA_INDEX);
	Port_SetPinDirection(PORTA_INDEX, 0xE0, PORT_PIN_IN); //11100000
	Port_SetPinPullUp (PORTA_INDEX,0xE0, 1);
}
