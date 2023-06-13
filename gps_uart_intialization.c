#include "tm4c123gh6pm.h"
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

void UART_Init(void) {

	SYSCTL_RCGCUART_R |= 0x0004;	// enable uart4
	SYSCTL_RCGCGPIO_R |= 0x0008;	// enable port D
	UART2_CTL_R &= ~0x0001;			// diable uart uartctl
	// in uart0 use it as alternate function afsel
	// pctl of uart

	UART2_IBRD_R = 104;
	UART2_FBRD_R = 11;			// baudrate
	UART2_LCRH_R = 0x0070;      // uartlcrh: data lengh 8bit bit5,bit6 ==1 --one stop bit bit3 ==0 -- no parity bit1,bit2 ==0 --enable fifo bit4 ==1
	UART2_CTL_R |= 0x0301;		// enable uartctl

	GPIO_PORTD_AFSEL_R |= 0xC0;
	GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R & 0x00FFFFFF) + 0x11000000;
	GPIO_PORTD_DEN_R |= 0xC0;		// digital enable
	GPIO_PORTD_AMSEL_R &= ~0XC0;	// analog

}

char UART_Inchar(void) {	// uart character input
	while ((UART2_FR_R & 0X10) != 0);
	return(char)(UART2_DR_R & 0xFF);
}
