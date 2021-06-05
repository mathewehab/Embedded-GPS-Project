#include "define.h"
#include "tm4c123gh6pm.h"
#include <math.h>
#include "fpu.h"
#include <stdint.h>
#include "fpu.c"
#include <stdio.h>

 
//initializing the LED
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


 
//initializing PORT B
void PortB_init(void) {
    SYSCTL_RCGCGPIO_R |= 0x20;
    while ((SYSCTL_PRGPIO_R &= 0x20) == 0);
    GPIO_PORTB_LOCK_R = GPIO_LOCK_KEY;
      GPIO_PORTB_LOCK_R = GPIO_LOCK_KEY;

 

    GPIO_PORTB_CR_R |= 0X03;
    
    GPIO_PORTB_DIR_R |= 0X02;
    GPIO_PORTB_DIR_R &= ~0X01;
    
    GPIO_PORTB_DEN_R |= 0X03;
    GPIO_PORTB_AMSEL_R &= ~0X03;
    
    GPIO_PORTB_AFSEL_R |= 0X03;
    GPIO_PORTB_PCTL_R |= 0X00000011;
    
    GPIO_PORTB_PUR_R  |=0x01;
    
}

 

//void LCD_Init(void) {
//       SYSCTL_RCGCGPIO_R |= 0x06;
//    while ((SYSCTL_PRGPIO_R &= 0x60) == 0);
//    GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
//    GPIO_PORTF_CR_R |= RGB;
//    GPIO_PORTF_DIR_R |= 0xFF;
//    GPIO_PORTF_DEN_R |= RGB;
//    GPIO_PORTF_AMSEL_R &= ~RGB;
//    GPIO_PORTF_AFSEL_R &= ~RGB;
//    GPIO_PORTF_PCTL_R &= ~0X0000FFF0;
//    GPIO_PORTF_DATA_R &= ~RGB;
//}

 


 
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

 

 

// Changing the LED outputs

 

void LED_Output (unsigned char input){
    
                GPIO_PORTF_DATA_R  &= ~RGB ;
                GPIO_PORTF_DATA_R  |= input;
}

 


unsigned char button_in;
unsigned char led_out = RED;

 

 

unsigned int i;

unsigned int Total_distance;

 

void distance_taken(double distance){  // accumulate calculated short distances
    Total_distance += distance;

 

} 

 

int min(int num1, int num2) { return (num1 > num2 ) ? num2 : num1; }
    



double haversine;
double temp;
double distance; 

double CalcGPSDistance(float latitud1, float longitud1, float latitud2, float longitud2){

    latitud1  *= DegreeToRadiant;
    longitud1 *= DegreeToRadiant;
    latitud2  *= DegreeToRadiant;
    longitud2 *= DegreeToRadiant;
 
    haversine = (pow(sin((1.0 / 2) * (latitud2 - latitud1)), 2)) + ((cos(latitud1)) * (cos(latitud2)) * (pow(sin((1.0 / 2) * (longitud2 - longitud1)), 2)));
    temp = 2 * asin(sqrt(haversine));
    distance = EarthRadius * temp;

    return distance;
}
 

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

 

 

/* Mili seconds delay function */
void delay_ms(int n)
{
 int i,j;
 for(i=0;i<n;i++)
 for(j=0;j<3180;j++)
 {}
}

 

/* Micro seconds delay function */
void delay_us(int n)
{
 int i,j;
 for(i=0;i<n;i++)
 for(j=0;j<3;j++)
 {}
 }

 

void LCD_Command(char com){ //Rs: PA5 ,, Rw: PA6 ,, EN: PA7 
    GPIO_PORTA_DATA_R = 0; //clear bits A5,A6 (rs&rw) 
    GPIO_PORTB_DATA_R= com;
    GPIO_PORTA_DATA_R|=0X80;// enable A7 for Enable latch
    delay_ms(1);
    GPIO_PORTA_DATA_R &= ~0xE0; //return Enable latch back to zero //return Enable latch back to zero
    
}

 

void LCD_Data(char data){
    GPIO_PORTA_DATA_R|=0X20;
    GPIO_PORTA_DATA_R &= ~0X40; //RW=0
    
    GPIO_PORTB_DATA_R=data;
    GPIO_PORTA_DATA_R|=0X80;// enable A7 for Enable latch
    delay_ms(3);
    GPIO_PORTA_DATA_R&=~0xE0; //return Enable latch back to zero
}

 

void LCD_start(){
//LCD_Command(0x30);//wake up
//delay_us(40);//delay
		LCD_Command(0x38);// 8 bit mode
		delay_us(40);    //delay
		LCD_Command(0x01);//clear lcd
		delay_ms(3);    //delay
		LCD_Command(0x0F); // Display ON cursor blinking
		delay_us(40);    //delay
		LCD_Command(0x80);// force cursor to begin at the beginning of 1st line
		delay_us(40);//delay
		LCD_Command(0x06);// increment cursor to right
		delay_us(40);    //delay
    
}

 

double dist;
 
void TestDistance(double distance){
    				 
				 if(distance >= 100.01){LED_Output(GREEN);}
         else{LED_Output(BLUE);}           

}

void SevenSeg_Init(void) {
    SYSCTL_RCGCGPIO_R |= 0x02;
    while ((SYSCTL_PRGPIO_R &= 0x02) == 0);
    GPIO_PORTB_LOCK_R = GPIO_LOCK_KEY;
    GPIO_PORTB_CR_R |= 0xFF;
    GPIO_PORTB_DIR_R |= 0xFF;
    GPIO_PORTB_DEN_R |= 0xFF;
    GPIO_PORTB_AMSEL_R &= ~0xFF;
    GPIO_PORTB_AFSEL_R &= ~0xFF;
    GPIO_PORTB_PCTL_R = 0;
    GPIO_PORTB_DATA_R &= ~0x0F;
	  GPIO_PORTB_DATA_R |= 0x70;

}


int k;
void SevenSeg_Data(int number, int seconds){
	int units;
	int tens;
	int hundreds;

	SevenSeg_Init();


	
	if(number<1000&& number>0){
		units = number % 10;
		tens= (number/10) %10;
		hundreds= (number/100) %10;
		
	for(k=0;k<(66*seconds);k++){
			GPIO_PORTB_DATA_R &= ~digit1; //turn on digit 1
			GPIO_PORTB_DATA_R |= digit2;  //turn off digit 2
			GPIO_PORTB_DATA_R |= digit3; //turn off digit 3
			GPIO_PORTB_DATA_R &= ~0x0F;
			GPIO_PORTB_DATA_R |= hundreds;
			delay_ms(5);
			GPIO_PORTB_DATA_R |= digit1;
			GPIO_PORTB_DATA_R &= ~digit2;
			GPIO_PORTB_DATA_R |= digit3;
			GPIO_PORTB_DATA_R &= ~0x0F;
			GPIO_PORTB_DATA_R |= tens;
			delay_ms(5);
			GPIO_PORTB_DATA_R |= digit1;
			GPIO_PORTB_DATA_R |= digit2;
			GPIO_PORTB_DATA_R &= ~digit3;
			GPIO_PORTB_DATA_R &= ~0x0F;
			GPIO_PORTB_DATA_R |= units;
			delay_ms(5);

		}			

	}else{
		RGBLED_Init();
		for(k=0;k<(66*seconds);k++){
			LED_Output(RED);
			GPIO_PORTB_DATA_R &= ~digit1;
			GPIO_PORTB_DATA_R |= digit2;
			GPIO_PORTB_DATA_R |= digit3;
			GPIO_PORTB_DATA_R &= ~ 0x0F;
			delay_ms(1);
			GPIO_PORTB_DATA_R |= digit1;
			GPIO_PORTB_DATA_R &= ~digit2;
			GPIO_PORTB_DATA_R |= digit3;
			GPIO_PORTB_DATA_R &= ~ 0x0F;
			delay_ms(1);
			GPIO_PORTB_DATA_R |= digit1;
			GPIO_PORTB_DATA_R |= digit2;
			GPIO_PORTB_DATA_R &= ~digit3;
			GPIO_PORTB_DATA_R &= ~ 0x0F;
			delay_ms(1);
		}

		
	}
		GPIO_PORTB_DATA_R &= ~ 0x0F;
	  GPIO_PORTB_DATA_R |= 0x70;

}





//int main() {   

//    
//            FPUEnable();
//						FPULazyStackingEnable();
//						RGBLED_Init();
////						SevenSeg_Data(578,5);
////						delay_ms(500);
////						SevenSeg_Data(123,10);
//						
//						
//	
//						dist = CalcGPSDistance(30.053716529290657, 31.255879108910797,30.05336944148598, 31.255492772461782); //small
//						TestDistance(dist);
//						SevenSeg_Data(dist,10);
//						delay_ms(500);
//	
//						dist = CalcGPSDistance(30.053716529290657, 31.255879108910797,30.052805288432584, 31.254816855794772); //Large
//						TestDistance(dist);
//						SevenSeg_Data(dist,10);
//						delay_ms(500);
//					
//						SevenSeg_Data(1000,10);
//            
//   

//    
//}