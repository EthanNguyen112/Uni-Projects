# Serial Terminal Calculator

A serial communication calculator program built on the 8051 microcontroller. This project interfaces with a PC terminal emulator to perform arithmetic operations in decimal, binary, and hexadecimal number systems.

## Overview

This calculator application allows a user to input numerical expressions via a serial terminal. The 8051 receives input character-by-character, processes the data, performs the selected operation, and returns the result to the terminal. The project was developed in embedded C using the Keil µVision4 IDE.

## Features

- Supports three numeric bases:
  - Decimal (e.g. 1234 + 5678)
  - Binary (e.g. 1010 & 1100)
  - Hexadecimal (e.g. 1A2B - 0F0F)
- Arithmetic operations:
  - Decimal: addition, subtraction, multiplication, division, exponentiation
  - Binary: addition, subtraction, AND, OR
  - Hexadecimal: addition, subtraction
- Overflow warning for out-of-range input
- ASCII-to-decimal conversion and output formatting
- Full-duplex asynchronous serial communication (UART)

## How It Works

1. The program waits for user input from the serial terminal.
2. Inputs are received via UART and temporarily stored in the `SBUF` register.
3. Input characters are converted from ASCII to their numerical equivalents based on the selected number system.
4. Operands and operators are parsed, and calculations are performed using standard C logic.
5. The result is converted back to ASCII and displayed on the terminal.

### Supported Input Format

- Decimal: 4-digit values (e.g. `0123 + 0045`)
- Binary: up to 4-bit values (e.g. `1010 | 0101`)
- Hexadecimal: 4-digit hex values (e.g. `1A3F - 0F0F`)

### Limitations

- Maximum operand size is limited to 4 characters due to memory/code size constraints.
- Does not support negative values in binary or hex modes.
- Input must follow strict formatting (e.g., no spaces, fixed digit length).

## Technologies Used

- 8051 Microcontroller
- Embedded C (Keil µVision4)
- UART serial communication
- Terminal emulator (e.g., Tera Term, PuTTY)
<img width="534" height="426" alt="image" src="https://github.com/user-attachments/assets/4596ec57-11e2-4f69-aaa7-c5924a04df43" />

## Future Improvements

- Expand input size limits
- Add additional operations (modulus, bitwise shift)
- Improve error handling and user prompts
- Implement command-line-like input buffer with backspace support

## Getting Started

1. Flash the hex file to the 8051 board using Keil µVision4 or an appropriate programmer.
2. Connect the board to a PC via serial (USB-to-TTL if necessary).
3. Open a terminal emulator with the correct COM port settings:
   - Baud Rate: 9600
   - Data: 8 bits
   - Parity: None
   - Stop Bits: 1
4. Interact with the calculator via the terminal interface.


