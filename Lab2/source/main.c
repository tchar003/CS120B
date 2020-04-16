/*	Author: tchar003
 *  Partner(s) Name: 
 *	Lab Section: 028
 *	Assignment: Lab 2  Exercise 4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; //Configure port A's 8 pins as inputs
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00; //Configure port D's 8 pins as ouputs, initialize to 0s
	unsigned char tempA = 0x00;
	unsigned char tempB = 0x00;
	unsigned char tempC = 0x00;
	unsigned char totweight = 0x00; // 
	unsigned char tempD = 0x00;
    	while (1) {
		// 1) Read input (rightmost 4 bits)
		tempA = PINA;
		tempB = PINB;
		tempC = PINC;
		// 2) Compute sums of weights
		totweight = tempA + tempB + tempC; //totweight is the sum of the weights of the 3 passengers
		// 3) If totweight > 140, set PD0 to 1
		tempD = (totweight > 140) ? 0x01: 0x00;
		// 4) If the difference between A and C is greater than 80, set PD1 to 1
		if (tempA > tempC) {
			if (tempA - tempC > 80) {
				tempD = tempD | 0x02; //Force PD1 to 1
			}
		}
		else if (tempC > tempA) {
			if (tempC - tempA > 80) {
				tempD = tempD | 0x02;
			}
		}

		totweight = totweight & 0xFC; //Force left 2 bits to 0
		
		tempD = totweight | tempD;
		PORTD = tempD; // Weight +- 3 | PD1PD0
	}	
    	return 0;
}
