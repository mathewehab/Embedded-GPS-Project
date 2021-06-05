#include "define.h"
#include "tm4c123gh6pm.h"
#include <math.h>
#include "fpu.h"
#include <stdint.h>
#include <stdio.h>

void delay_ms(int);
void delay_us(int);


void LCD_init(void){
	
	   	SYSCTL_RCGCGPIO_R |=0x03;// enable clock for the ports i'm going to use (port B)
	   	while((SYSCTL_PRGPIO_R & 0x03) == 0){};
      GPIO_PORTA_LOCK_R = GPIO_LOCK_KEY ;
      GPIO_PORTB_LOCK_R = GPIO_LOCK_KEY ;
        
      GPIO_PORTB_CR_R |= 0xFF ;
      GPIO_PORTB_DIR_R |=0XFF;  //set data outputs from     PB0-PB7
      GPIO_PORTB_DEN_R |=0XFF;  //digital enable 
      GPIO_PORTB_PCTL_R =0x00000000; // 4) configure PB0-7 as GPIO
      GPIO_PORTB_AFSEL_R= 0x00; // 6) disable alt funct on PB0-7
      GPIO_PORTB_AMSEL_R= 0x00; //disable analog selection
        
      GPIO_PORTA_CR_R |= 0xE0 ;
      GPIO_PORTA_DIR_R |=0XE0;  //set data outputs from     PA5-PA7
      GPIO_PORTA_DEN_R |=0XE0;  //digital enable
      GPIO_PORTA_PCTL_R&=~ 0xFFF00000; // 4) configure PA5-7 as GPIO
      GPIO_PORTA_AFSEL_R &= ~0xE0; // 6) disable alt funct on
      GPIO_PORTA_AMSEL_R&= ~0xE0; //disable analog selection
}


