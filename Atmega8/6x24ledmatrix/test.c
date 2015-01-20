#include <avr/io.h>
#include <util/delay.h>
#include "stdio.h"
#include "74hc595.h"
#include "cd4017.h"

int main(void){
    uint8_t led_pattern[8]={
                         0b11111111,
                         0b00000010,
                         0b00000100,
                         0b00001000,
                         0b00010000,
                         0b00100000,
                         0b01000000,
                         0b10000000,
                      };
    //Initialize 74HC595
    HC595Init();
    
    //Initialize CD4017
    CD4017Init();

    //Resets the row's
    CD4017Reset();
    //FIX  RESET doesn't work.
    while(1){
 	
	for(uint8_t i=0;i<8;i++){
	    HC595Write(led_pattern[i]);   //Write the data to HC595
	    CD4017Pulse();
	    _delay_ms(500);
	}
    }
}
