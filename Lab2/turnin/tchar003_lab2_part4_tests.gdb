# Test file for "Lab2"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

# Example test:
test "PINA: 0, PINB: 0, PINC: 0 => PORTD: 0x00"
# Set inputs
setPINA 0x00
setPINB 0x00
setPINC 0x00
# Continue for several ticks
continue 10
# Set expect values
expectPORTD 0x00
# Check pass/fail
checkResult

# Add tests below
test "PINA: 32, PINB: 64, PINC: 32 => PORTD: 0x80"
setPINA 32
setPINB 64
setPINC 32
continue 10
expectPORTD 0x80
checkResult

test "PINA: 8, PINB: 8, PINC: 128 => PORTD: 0x93"
setPINA 8
setPINB 8
setPINC 128
continue 10
expectPORTD 0x93
checkResult

test "PINA: 64, PINB: 64, PINC: 64 => PORTD: 0xC1"
setPINA 64
setPINB 64
setPINC 64
continue 10
expectPORTD 0xC1
checkResult


test "PINA: 64, PINB: 13, PINC: 64 => PORTD: 0x8D"
setPINA 64
setPINB 13
setPINC 64
continue 10
expectPORTD 0x8D
checkResult

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
