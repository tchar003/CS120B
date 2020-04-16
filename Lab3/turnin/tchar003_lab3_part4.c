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
	DDRA = 0x00; PORTA = 0xFF; //Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00;
	//DDRC = 0x00; PORTC = 0xFF;
	DDRC = 0xFF; PORTC = 0x00; //Configure port C's 8 pins as ouputs, initialize to 0s
	unsigned char tempA = 0x00;
	unsigned char tempB = 0x00;
	unsigned char tempC = 0x00;
	//unsigned char tempD = 0x00;
    	while (1) {
		tempA = PINA;
		tempB = tempA >> 4;
		tempC = tempA << 4;
		PORTB = tempB;
		PORTC = tempC; 
	}	
    	return 0;
}
