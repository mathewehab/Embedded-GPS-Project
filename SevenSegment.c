#include "define.h"
#include "tm4c123gh6pm.h"

void RGBLED_Init(void);
void delay_ms(int);
void delay_us(int);
void LED_Output(unsigned char);

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

void SevenSeg_Data(int number, int seconds) {

	int units;
	int tens;
	int hundreds;

	SevenSeg_Init();

	if (number < 1000 && number > 0) {
		units = number % 10;
		tens = (number / 10) % 10;
		hundreds = (number / 100) % 10;

		for (k = 0; k < (66 * seconds); k++) {
			GPIO_PORTB_DATA_R &= ~digit1;	// turn on digit 1
			GPIO_PORTB_DATA_R |= digit2;	// turn off digit 2
			GPIO_PORTB_DATA_R |= digit3;	// turn off digit 3
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

	}
	else {
		RGBLED_Init();

		for (k = 0; k < (66 * seconds); k++) {
			LED_Output(RED);
			GPIO_PORTB_DATA_R &= ~digit1;
			GPIO_PORTB_DATA_R |= digit2;
			GPIO_PORTB_DATA_R |= digit3;
			GPIO_PORTB_DATA_R &= ~0x0F;
			delay_ms(5);
			GPIO_PORTB_DATA_R |= digit1;
			GPIO_PORTB_DATA_R &= ~digit2;
			GPIO_PORTB_DATA_R |= digit3;
			GPIO_PORTB_DATA_R &= ~0x0F;
			delay_ms(5);
			GPIO_PORTB_DATA_R |= digit1;
			GPIO_PORTB_DATA_R |= digit2;
			GPIO_PORTB_DATA_R &= ~digit3;
			GPIO_PORTB_DATA_R &= ~0x0F;
			delay_ms(5);
		}

	}

	GPIO_PORTB_DATA_R &= ~0x0F;
	GPIO_PORTB_DATA_R |= 0x70;

}
