#include "typedefs.h"
#include "dio.h"
#include "port.h"
#include "tm4c123gh6pm.h"
#include "project.h"
#include "LCD.h"

	
void lcd_init()
{
   SYSCTL_RCGCGPIO_R  |= 0x03;
	while ( ( SYSCTL_PRGPIO_R & 0x30)==0)
	{}
	 GPIO_PORTB_DIR_R   |= 0xFF;
	 GPIO_PORTB_DEN_R   |= 0xFF;
		
	 GPIO_PORTA_DIR_R   |= 0xFF;
	 GPIO_PORTA_DEN_R   |= 0xFF;
		
		GPIO_PORTA_AFSEL_R &= 0x00;
		GPIO_PORTB_AFSEL_R &= 0x00;
		GPIO_PORTA_AMSEL_R &= 0x00;
		GPIO_PORTB_AMSEL_R &= 0x00;
		
	
	/* Port_Init( PORTA_INDEX );
	 Port_Init( PORTB_INDEX );
	 Port_SetPinDirection (PORTB_INDEX, 0xFF, PORT_PIN_OUT);
   Port_SetPinDirection(PORTA_INDEX,0x03,PORT_PIN_OUT); */  
    Systick_wait10ms(15);
    lcd_send_command(0x06);
    Systick_wait10ms(1);
    lcd_send_command(0x0E);
    Systick_wait10ms(1);
    lcd_send_command(0x14);
    lcd_send_command(0x38);
    Systick_wait10ms(1);
    lcd_send_command(0x40);
    Systick_wait10ms(1);
    lcd_send_command(0x80);
    
}

void lcd_send_command(unsigned char cmd)
{
	  GPIO_PORTB_DATA_R =0;
		GPIO_PORTB_DATA_R |=cmd;
    GPIO_PORTA_DATA_R =1;
    Systick_wait10ms(1);
    GPIO_PORTA_DATA_R &= ~0x20;		
    Systick_wait10ms(1);
    GPIO_PORTB_DATA_R =0;
}


void lcd_SendData(unsigned char data)
{
   GPIO_PORTB_DATA_R =0;
	 GPIO_PORTB_DATA_R =data;
   GPIO_PORTA_DATA_R |= 0x20;
	 GPIO_PORTA_DATA_R &= ~0x40;
   Systick_wait10ms(1);
   GPIO_PORTA_DATA_R |= 0x40;
	 GPIO_PORTA_DATA_R &= ~0x20;
   Systick_wait10ms(1);
   GPIO_PORTB_DATA_R =0;
}

void lcd_clear(void)
{
   lcd_send_command(0x01);   
  Systick_wait10ms(2);
}

void lcd_set_cursor(unsigned char x , unsigned char y)
{
    if(y==0)
    {
        lcd_send_command(0x80+x);
    }
    else
    {
        lcd_send_command(0xC0+x);
    }
}


void lcd_SendString(char *str)
{
    while(*str != '\0')
    {
        lcd_SendData(*str);
        str++;
    }
}
void lcd_out(unsigned char x , unsigned char y ,char*str )
{
    lcd_set_cursor(x,y);
    lcd_SendString(str);
    
}

char* convertData(unsigned int var)
{
    static char data[17];
    char*arr=&data[16];
    *arr='\0';
    while(var !=0)
    {
        arr--;
        *arr=(var%10)+'0';
        var=var/10;
    }
    return arr;
}


