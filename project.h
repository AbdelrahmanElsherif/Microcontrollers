#ifndef PROJECT_H
#define PROJECT_H

#include "typedefs.h"
#include "dio.h"
#include "port.h"
#include "tm4c123gh6pm.h"

typedef enum {
	falling, rising, both
}InterruptEdge;

typedef enum {
	down, up, disable
}PullResistor;

void InterruptInit();
void SwitchInit();
void SevenSegmentInit();
void SysTick_Wait(uint32 delay);
void Systick_wait10ms(uint32 delay);
void display(uint16 counter);
void systick_init(void);

#endif
