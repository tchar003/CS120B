/*	Author: tchar003
 *  Partner(s) Name: 
 *	Lab Section: 028
 *	Assignment: Lab 2  Exercise 3
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
	DDRC = 0xFF; PORTC = 0x00; //Configure port B's 8 pins as ouputs, initialize to 0s
	unsigned char cntavail = 0x00; // Temporary variable to hold the value of C
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
    	while (1) {
		// 1) Read input (rightmost 4 bits)
		tmpA = PINA & 0x0F;
		cntavail = 4 - countSetBits(tmpA); //Subtract number of taken spaces from 4
		
		cntavail = (cntavail == 0) ? 0x80: cntavail & 0x0F;

		PORTC = cntavail;
	}	
    	return 0;
}
