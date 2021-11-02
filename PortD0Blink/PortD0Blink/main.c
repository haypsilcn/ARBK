/*
 * PortD0Blink.c
 *
 * Created: 02/11/2021 06:18:25
 * Author : haypsilcn
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD = 0xff;
	
	PORTD = 0x00;
    /* Replace with your application code */
    while (1) 
    {
		PORTD = 0xff;
		_delay_ms(200);
		PORTD = 0x00;
		_delay_ms(200);
    }
}

