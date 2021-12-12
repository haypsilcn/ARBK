/*
 * sevenseg.h
 *
 * Created: 12/12/2021 07:25:14
 *  Author: haypsilcn
 */ 


#ifndef SEVENSEG_H_
#define SEVENSEG_H_

#define F_CPU 16000000
#include <util/delay.h>
#include "avr/io.h"

void display(int num, int numList[]);

#endif /* SEVENSEG_H_ */