/*
 * Praktikum04.c
 *
 * Created: 12/12/2021 07:21:18
 * Author : haypsilcn
 */ 

#include "keys.h"
#include "sevenseg.h"

int number[10] = {64,79,36,48,25,18,2,88,0,16}; //display number from 0 to 9;
volatile uint32_t count = 99;

ISR(PCINT0_vect){
	if(bit_is_clear(PINB,PINB1)) //when sw1 is pressed
	count++;
	if(bit_is_clear(PINB,PINB2)) // when sw2 is pressed
	count--;
}

int main(void)
{
	init();
	while(1){
		int z = count/10;
		int e = count - z*10;
		display(e,number);
		display(z,number);
	}
}


