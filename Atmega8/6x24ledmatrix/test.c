#include <avr/io.h>
#include <util/delay.h>
#include "stdio.h"
#include "74hc595.h"

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
    //Initialize HC595 system
    HC595Init();

    while(1){
       for(uint8_t i=0;i<8;i++){
          HC595Write(led_pattern[i]);   //Write the data to HC595
          _delay_ms(500);
       }
    }
}
