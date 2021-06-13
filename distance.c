#include "define.h"
#include "tm4c123gh6pm.h"

void LED_Output();

void TestDistance(double distance) {
    				 
	if (distance >= 100.01) {
		LED_Output(GREEN);
	}
	
        else if (distance < 100.01) {
		LED_Output(BLUE);
	}           
}

double ConvertDegreeAngleTodouble(double degrees, double minutes, double seconds) {
    return degrees + (minutes/60) + (seconds/3600);
}
