/*
 * Praktikum04.c
 *
 * Created: 12/12/2021 07:21:18
 * Author : haypsilcn
 */ 

#include "keys.h"
#include "sevenseg.h"

/*
logical 0: on
logical 1: off

	.gfe dcba
0 :  100 0000	= 64
1 :  111 1001	= 121
2 :  010 0100	= 36
3 :	 011 0000	= 48
4 :  001 1001	= 25
5 :  001 0010	= 18
6 :  000 0010	= 2
7 :  111 1000	= 120
8 :  000 0000	= 0
9 :  001 0000	= 16
*/

int number[10] = { 64, 121, 36, 48, 25, 18, 2, 120, 0, 16 };		// display number from 0 to 9;
volatile uint32_t count = 0;

ISR(PCINT0_vect){
	if (bit_is_clear(PINB, PINB1)) {								// sw1 is pressed
		if (count == 0) {									
			count = 100;											// if count == 0 and sw1 is pressed, set count = 100 then minus 1 and leds will display 99
		}
		count--;
	}
	if (bit_is_clear(PINB, PINB2)) {								// sw2 is pressed
		if (count == 99) {
			count = -1;												// if count == 99 and sw2 is pressed, set count = -1 then plus 1 and leds will display 00
		}
		count++;
	}
}

int main(void)
{
	init();
	while(1) {
		int led03 = count % 10;
		int led02 = (count - led03) / 10;
			
		display(led03, number);
		display(led02, number);
	}
}


