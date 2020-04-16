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

unsigned char countSetBits(unsigned char n) 
{ 
    unsigned char count = 0; 
    while (n) { 
        count += n & 1; 
        n >>= 1; 
    } 
    return count; 
} 

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; //Configure port A's 8 pins as inputs
	DDRB = 0x00; PORTB = 0xFF;
	//DDRC = 0x00; PORTC = 0xFF;
	DDRC = 0xFF; PORTC = 0x00; //Configure port C's 8 pins as ouputs, initialize to 0s
	unsigned char tempA = 0x00;
	unsigned char tempB = 0x00;
	unsigned char tempC = 0x00;
	//unsigned char tempD = 0x00;
    	while (1) {
		// 1) Read input (rightmost 4 bits)
		tempA = PINA;
		tempB = PINB;
	
		tempC = countSetBits(tempA);
		tempC += countSetBits(tempB);
		PORTC = tempC; // Weight +- 3 | PD1PD0
	}	
    	return 0;
}
