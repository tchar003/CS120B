/* Debug information for SimAVR */
#include <stdio.h>
#ifndef F_CPU
#define F_CPU 8000000
#endif

#include <avr/sleep.h>
#include "include/simavr/avr/avr_mcu_section.h"
//F_CPU will define the clock frequency (8MHz in the ATmega1284)
//AVR_MCU(...) lets SimAVR know that we are simulating on the ATmega1284 with an F_CPU clock
AVR_MCU(F_CPU,"atmega1284");
//AVR_MCU_VCD_FILE(...) allows us to name the generated trace file
AVR_MCU_VCD_FILE("build/results/Lab2_trace.vcd",1000);


//avr_mmcu_vcd_trace_t is a struct used by SimAVR to know which signals to trace and generate a wave form.
//You can set the name of the traced symbol using AVR_MCU_VCD_SYMBOL(...), set the signal using 
//	.what=(void*)&<signal>
//and even set a mask if you only want one or two bits (we’ll see an example of this later). 
const struct avr_mmcu_vcd_trace_t _mytrace[] _MMCU_ = {
    { AVR_MCU_VCD_SYMBOL("PINA"), .what = (void*)&PINA, } , // Example individual pin
    { AVR_MCU_VCD_SYMBOL("PORTB"), .what = (void*)&PORTB, } , // Example full port
    { AVR_MCU_VCD_SYMBOL("PINA0"), .mask = 1 << 0, .what = (void*)&PINA, } ,
    { AVR_MCU_VCD_SYMBOL("PINB"), .what = (void*)&PINB, } , // Example full port
    { AVR_MCU_VCD_SYMBOL("PORTD"), .what = (void*)&PORTD, } , // Example full port
    { AVR_MCU_VCD_SYMBOL("PINC"), .what = (void*)&PINC, } , // Example full port

};

/* Function to output through UART */
static int uart_putchar(char c, FILE *stream) {
    if (c == '\n') {
        uart_putchar('\r',stream);
    }
    loop_until_bit_is_set(UCSR0A,UDRE0);
    UDR0 = c;
    return 0;
}

/* Setup filestream for debugging */
FILE mystdout = FDEV_SETUP_STREAM(uart_putchar,NULL,_FDEV_SETUP_WRITE);
/* End SimAVR section */
