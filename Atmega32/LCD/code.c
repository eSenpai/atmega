#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"

void installing(void);
void complete(void);

int main(void){
	LCDInit();

	while(1){
		installing();
		_delay_ms(2000);
		LCDClear();
		_delay_ms(500);
		LCDString(1, 1, "Install Complete");
		_delay_ms(1500);
		LCDClear();
		_delay_ms(500);
		complete();
		_delay_ms(4000);
		LCDClear();
		_delay_ms(500);
	}
}

void installing(void){
	LCDString(1, 1, "Installing Gentoo");
	for(int i = 1; i <= 16; i++){
		LCDString(i, 2, "X");
		_delay_ms(400);
	}
}

void complete(void){
	LCDString(1, 1, "Running 100%");
	LCDString(1, 2, "  GENTOO  ");
}
