#ifndef HC595_H
#define HC595_H

#include "stdint.h"

//Initialize HC595 System
void HC595Init(void);

//Sends a clock pulse on SH_CP line
void HC595Pulse(void);

//Sends a clock pulse on ST_CP line
void HC595Latch(void);

void HC595Write(uint8_t data[]);

/* Example main
int main(void){
    uint8_t led_pattern[8]={
                         0b00000001,
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
          wait();
       }
    }
}
*/

#endif
