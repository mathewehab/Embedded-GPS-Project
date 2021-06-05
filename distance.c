#include "define.h"
#include "tm4c123gh6pm.h"

void LED_Output();

void TestDistance(double distance){
    				 
				 if(distance >= 100.01){LED_Output(GREEN);}
         else{LED_Output(BLUE);}           

}

unsigned int Total_distance;

void distance_taken(double distance){  // accumulate calculated short distances
    Total_distance += distance;
} 
