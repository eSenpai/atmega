#include <avr/io.h>
#include <util/delay.h>
#include "stdio.h"
//#include "stdint.h"

#define CD4017_DDR      DDRC
#define CD4017_PORT     PORTC
#define CD4017_SC       PINC5    //Shift clock 
#define HC595_PORT      PORTB
#define HC595_DDR       DDRB
#define HC595_DS_POS    PB0      //Data pin (DS) pin location
#define HC595_SH_CP_POS PB1      //Shift Clock (SH_CP) pin location
#define HC595_ST_CP_POS PB2      //Store Clock (ST_CP) pin location

//Data related
int matrix[6][24] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

//Initialize HC595 System

void HC595Init(void){
    //Make the Data(DS), Shift clock (SH_CP), Store Clock (ST_CP) lines output
    HC595_DDR |= ((1 << HC595_SH_CP_POS) | (1 << HC595_ST_CP_POS) | (1 << HC595_DS_POS));
}

//Low level macros to change data (DS)lines

#define HC595DataHigh() (HC595_PORT |= (1 << HC595_DS_POS))
#define HC595DataLow() (HC595_PORT &= (~(1 << HC595_DS_POS)))

//Sends a clock pulse on SH_CP line
void HC595Pulse(void){
    //Pulse the Shift Clock
    HC595_PORT |= (1 << HC595_SH_CP_POS);//HIGH
    HC595_PORT &= (~(1 << HC595_SH_CP_POS));//LOW
}

//Sends a clock pulse on ST_CP line
void HC595Latch(void){
    //Pulse the Store Clock
    HC595_PORT |= (1 << HC595_ST_CP_POS);//HIGH
    _delay_loop_1(1);
    HC595_PORT &= (~(1 << HC595_ST_CP_POS));//LOW
    _delay_loop_1(1);
}

void HC595SendBit1(void){
    HC595DataHigh();
    HC595Pulse();
    HC595DataLow();
}

void HC595SendBit0(void){
    HC595DataLow();
    HC595Pulse();
}

void HC595SendByte(uint8_t data){
    for(uint8_t i = 0; i < 8; i++){
	if(data & 0b10000000){
	    HC595DataHigh();
	}else{
	    HC595DataLow();
	}
	HC595Pulse();
	data = data << 1;
    }
    HC595Latch();
    CD4017Pulse();
    _delay_ms(1);
}

void CD4017Init(void){
    CD4017_DDR |= 1 << CD4017_SC;
    CD4017_PORT &= ~ 1 << CD4017_SC;
}

void CD4017Pulse(void){
    //Send a pulse to the clock
    _delay_ms(500);
    CD4017_PORT |= 1 << CD4017_SC;
    _delay_ms(500);
    CD4017_PORT &= ~ 1 << CD4017_SC;
}

int main(void){
    //Debug
    // DDRC |= 1 << PINC3;
    //PORTC |= 1 << PINC3;
    //CD4017Init();
    //HC595Init();
  
    while(1){
    
    }
}
