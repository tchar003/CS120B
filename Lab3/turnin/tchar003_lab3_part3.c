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
	//DDRB = 0x00; PORTB = 0xFF;
	//DDRC = 0x00; PORTC = 0xFF;
	DDRC = 0xFF; PORTC = 0x00; //Configure port C's 8 pins as ouputs, initialize to 0s
	unsigned char tempA = 0x00;
	//unsigned char tempB = 0x00;
	unsigned char tempC = 0x00;
	//unsigned char tempD = 0x00;
    	while (1) {
		// 1) Read input (rightmost 4 bits)
		tempA = PINA & 0x0F;
		if (tempA > 12) {
			tempC = 0x3F;
		}
		else if (tempA > 9) {
			tempC = 0x3E;
		}
		else if (tempA > 6) {
			tempC = 0x3C;
		}
		else if (tempA > 4) {
			tempC = 0x38;
		}
		else if (tempA > 2) {
			tempC = 0x70;
		}
		else if (tempA > 0) {
			tempC = 0x60;
		}
		else {
			tempC = 0x40;
		}
		tempA = PINA;//Ensured high bits don't mess with algorithm above in previous exercise. Now, we need those high bits back. 
		if ((tempA & 0x70) == 0x30) { //If A & b0111 0000 evaluates to b0011 0000, then the seatbelt(bit 6) is not fastened while the driver is seated(bit 5) with the key in the ignition(bit 4).
			tempC = tempC | 0x80;
		}

		PORTC = tempC; // All of the lights, all of the lights
	}	
    	return 0;
}
