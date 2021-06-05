#include "code.c"

int main() {   

    
            FPUEnable();
						FPULazyStackingEnable();
						RGBLED_Init();
//					SevenSeg_Data(578,5);
//				delay_ms(500);
//				SevenSeg_Data(123,10);
						
						
	
						dist = CalcGPSDistance(30.053716529290657, 31.255879108910797,30.05336944148598, 31.255492772461782); //small
						TestDistance(dist);
						SevenSeg_Data(dist,10);
						delay_ms(500);
	
						dist = CalcGPSDistance(30.053716529290657, 31.255879108910797,30.052805288432584, 31.254816855794772); //Large
						TestDistance(dist);
						SevenSeg_Data(dist,10);
						delay_ms(500);
					
						SevenSeg_Data(1000,10);

}
