// main.c
// Runs on LM4F120/TM4C123
// this connection occurs in the USB debugging cable
// U1Rx (PB0)
// U1Tx (PB1)
// Ground connected ground in the USB cable


// Header files 
#include "tm4c123gh6pm.h"
#include "UART.h"
#include "string.h"

void Delay(void);

// main function for programming BT device with no UI
int main(void) {
	char String[30];
	UART_Init();
  
  // setup the HC-05 bluetooth module
		UART0_OutString("AT+NAME=CECS447\r\n"); 		// Name = CECS447
		UART1_OutString("AT+NAME=CECS447\r\n"); 		// Name = CECS447
    while ((UART1_FR_R&UART_FR_BUSY) != 0){};
    BLT_InString(String);
    UART0_OutString(String);

		UART0_OutString("AT+UART=57600,0,1\r\n"); // baud rate = 57600, 1 stop bit, odd parity
		UART1_OutString("AT+UART=57600,0,1\r\n"); // baud rate = 57600, 1 stop bit, odd parity
    while ((UART1_FR_R&UART_FR_BUSY) != 0){};
    BLT_InString(String);
    UART0_OutString(String);

		UART0_OutString("AT+PSWD=0824\r\n"); 		  // Pass = 0824
		UART1_OutString("AT+PSWD=0824\r\n"); 		  // Pass = 0824
    while ((UART1_FR_R&UART_FR_BUSY) != 0){};
    BLT_InString(String);
    UART0_OutString(String);

		UART0_OutString("AT+ROLE=0\r\n");				  // Mode = Slave
		UART1_OutString("AT+ROLE=0\r\n");				  // Mode = Slave
    while ((UART1_FR_R&UART_FR_BUSY) != 0){};
    BLT_InString(String);
    UART0_OutString(String);

  // query the HC-05 bluetooth module
		UART0_OutString("AT+UART?\r\n"); // baud rate = 57600, 1 stop bit, odd parity
		UART1_OutString("AT+UART?\r\n"); // baud rate = 57600, 1 stop bit, odd parity
    while ((UART1_FR_R&UART_FR_BUSY) != 0){};
    BLT_InString(String);
    UART0_OutString(String);

		UART0_OutString("AT+PSWD?\r\n"); 		  // Pass = 0824
		UART1_OutString("AT+PSWD?\r\n"); 		  // Pass = 0824
    while ((UART1_FR_R&UART_FR_BUSY) != 0){};
    BLT_InString(String);
    UART0_OutString(String);

		UART0_OutString("AT+ROLE?\r\n");				  // Mode = Slave
		UART1_OutString("AT+ROLE?\r\n");				  // Mode = Slave
    while ((UART1_FR_R&UART_FR_BUSY) != 0){};
    BLT_InString(String);

    UART0_OutString(String);
		UART0_OutString("AT+NAME?\r\n"); 		// Name = CECS447
		UART1_OutString("AT+NAME?\r\n"); 		// Name = CECS447
    while ((UART1_FR_R&UART_FR_BUSY) != 0){};
    BLT_InString(String);
    UART0_OutString(String);

  while (1) {}
}
