#include "define.h"
#include "tm4c123gh6pm.h"
#include <stdint.h>
#include <stdio.h>


//initializing button 1 (PF0)
void SW1_Init(void){

    SYSCTL_RCGCGPIO_R |=0x20;
    while((SYSCTL_PRGPIO_R & 0x20) == 0);
    GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY ;

    GPIO_PORTF_CR_R  |= SW1;
    GPIO_PORTF_DIR_R &= ~SW1;
    GPIO_PORTF_DEN_R |= SW1;
    GPIO_PORTF_AMSEL_R &= ~SW1;
    GPIO_PORTF_AFSEL_R &=~ SW1;
    GPIO_PORTF_PCTL_R &= ~0x000F0000;
    GPIO_PORTF_PUR_R |= SW1;
    
}

 
//initializing button 2 (PF4)
void SW2_Init(void){

    SYSCTL_RCGCGPIO_R |=0x20;
    while((SYSCTL_PRGPIO_R & 0x20) == 0);
    GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY ;

    GPIO_PORTF_CR_R |=SW2 ;
    GPIO_PORTF_DIR_R &= ~SW2 ;
    GPIO_PORTF_DEN_R  |= SW2 ;
    GPIO_PORTF_AMSEL_R &= ~SW2 ;
    GPIO_PORTF_AFSEL_R &=~ SW2 ;
    GPIO_PORTF_PCTL_R &= ~0x0000000F;
    GPIO_PORTF_PUR_R  |=SW2 ;
    
}
 
//taking input from the switch

unsigned char SW1_Input(void){
    
     return GPIO_PORTF_DATA_R  & SW1;
    
}
 

unsigned char SW2_Input(void){
    
     return GPIO_PORTF_DATA_R  & SW2;
    
}