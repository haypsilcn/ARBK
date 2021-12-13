/*
 * sevenseg.c
 *
 * Created: 12/12/2021 07:25:37
 *  Author: haypsilcn
 */ 

#include "sevenseg.h"
void display(int num, int numList[]) {

	PORTD = numList[num];
	_delay_ms(10);
	PORTB ^= (1 << PINB0);

}
