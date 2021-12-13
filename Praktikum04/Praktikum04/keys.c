/*
 * keys.c
 *
 * Created: 12/12/2021 07:26:18
 *  Author: haypsilcn
 */ 

#include"keys.h"


void init(){
	DDRD = 0xff;										// Data direction register D (D0 -> D6) as input
	PORTD = (1 << PIND0);								// setting bit for 7-segment
	
	DDRB = 0x01;										// Data direction register B0 as output, B1 & B2 as input
	PORTB |= (1 << PINB1) | (1 << PINB2);				// setting bit for SW1 and SW2
	
	cli();												// clear global interrupt flag: interrupts will be immediately disabled
	PCICR |= 0x01;										// Pin Change Interrupt Control Register: turn on PortB
	PCMSK0 |= (1 << PINB1) | (1 << PINB2);				// trigger interrupt when PB1's and PB2's state changes
	sei();												// set global interrupt enable
}
