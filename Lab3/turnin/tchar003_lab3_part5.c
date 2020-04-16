/*	Author: tchar003
 *  Partner(s) Name: 
 *	Lab Section: 028
 *	Assignment: Lab 3  Exercise 2
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
	DDRD = 0x00; PORTD = 0xFF; //Configure port D's 8 pins as inputs
	DDRB = 0xFE; PORTB = 0x01; //(Attempt to)Configure B's leftmost 7 pins as outputs and bit 0 as input
	//DDRC = 0x00; PORTC = 0xFF;
	//DDRC = 0xFF; PORTC = 0x00; //Configure port C's 8 pins as ouputs, initialize to 0s
	unsigned short weight = 0x00;
	unsigned char B_out = 0x00;
	//unsigned char tempD = 0x00;
    	while (1) {
		weight = PIND << 1;
		weight = weight + (PINB & 0x01);

		if (weight >= 70) {
			B_out = 0x02;
		}
		else if (weight > 5) {
			B_out = 0x04;
		}
		else {
			B_out = 0x00;
		}
		
		PORTB = B_out;
	}	
    	return 0;
}
