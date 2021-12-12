/*
 * keys.c
 *
 * Created: 12/12/2021 07:26:18
 *  Author: haypsilcn
 */ 

#include"keys.h"


void init(){
	DDRD = 0xff;		//set pins D0 ->D6: output pins
	DDRB = 0x01;		//set pin  B0 as output pins. B1,B2 as input pin
	PORTD = (1<<PIND0);
	PORTB |= (1<<PINB1)|(1<<PINB2); // pull ups for pin B1, B2
	
	cli();
	PCICR |= (1<<PCIE0);			//Interrupt from Port B
	PCMSK0|= (1<<PINB1)|(1<<PINB2); // Pins b1 and b2 will interrupts
	sei();
}
