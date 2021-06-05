#include "define.h"
#include "tm4c123gh6pm.h"
#include "fpu.h"
#include <stdint.h>

void RGBLED_Init(void);


void Startup(void){
		     FPUEnable();
				 FPULazyStackingEnable();
				 RGBLED_Init();
}