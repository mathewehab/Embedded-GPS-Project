#include "tm4c123gh6pm.h"
#include "define.h"

void RGBLED_Init(void) {
	
    SYSCTL_RCGCGPIO_R |= 0x20;
    while ((SYSCTL_PRGPIO_R &= 0x20) == 0);
    GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
    GPIO_PORTF_CR_R |= RGB;
    GPIO_PORTF_DIR_R |= RGB;
    GPIO_PORTF_DEN_R |= RGB;
    GPIO_PORTF_AMSEL_R &= ~RGB;
    GPIO_PORTF_AFSEL_R &= ~RGB;
    GPIO_PORTF_PCTL_R &= ~0X0000FFF0;
    GPIO_PORTF_DATA_R &= ~RGB;
	
}

void LED_Output (unsigned char input){
    
     GPIO_PORTF_DATA_R  &= ~RGB ;
     GPIO_PORTF_DATA_R  |= input;
}