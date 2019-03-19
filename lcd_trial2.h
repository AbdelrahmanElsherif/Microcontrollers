#ifndef LCD_H
#define LCD_H

#include "typedefs.h"
#include "tm4c123gh6pm.h"


void lcd_init();
void lcd_send_command(unsigned char cmd);
void lcd_SendData(unsigned char data);
void lcd_clear(void);
void lcd_set_cursor(unsigned char x,unsigned char y);
void lcd_SendString(char *str);
void lcd_out(unsigned char x , unsigned char y ,char*str );
char* convertData(unsigned int var);
void Systick_wait10ms(uint32 delay);

#endif