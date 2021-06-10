#include "tm4c123gh6pm.h"
#include <string.h>
#include <stdint.h>


void UART0_Init(void){
SYSCTL_RCGCUART_R |=0x0001;   //enable uart0 and A
SYSCTL_RCGCGPIO_R |=0x0001;
UART0_CTL_R  &=~0x0001;    //diable uart uartctl
//in uart0 use it as alternate function afsel
//pctl of uart

UART0_IBRD_R = 104;
UART0_FBRD_R = 11;//baudrate 
UART0_LCRH_R = 0x0070;//uartlcrh: data lengh 8bit bit5,bit6 ==1 --one stop bit   bit3   ==0 -- no parity  bit1,bit2  ==0 --enable fifo  bit4    ==1
UART0_CTL_R = 0x0301;//enable uartctl

GPIO_PORTA_AFSEL_R  |=  0x03;
GPIO_PORTA_PCTL_R  =  (GPIO_PORTA_PCTL_R &0xFFFFFF00)+0x00000011 ;
GPIO_PORTA_DEN_R  |= 0x03;
GPIO_PORTA_AMSEL_R   &=~ 0X03;

}

void UART_outchar(char data){
	while((UART0_FR_R &0X0080)==0);
	UART0_DR_R =data;
}

 
void UART_outstring (char  *pt){
	while(*pt){
		UART_outchar(*pt);
		pt++;
	}
}
