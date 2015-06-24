#include <avr/io.h>
#include <util/delay.h>
#include "74hc595.h"
#include "cd4017.h"
#include "stdint.h"

#define HC595_PORT        PORTB
#define HC595_DDR         DDRB
#define HC595_DS_POS      PB0      //Data pin (DS) pin location
#define HC595_SH_CP_POS   PB1      //Shift Clock (SH_CP) pin location
#define HC595_ST_CP_POS   PB2      //Store Clock (ST_CP) pin location
 
//74HC595 INIT
void HC595Init(){
    //Make the Data(DS), Shift clock (SH_CP), Store Clock (ST_CP) lines output
    HC595_DDR |= ((1 << HC595_SH_CP_POS) | (1 << HC595_ST_CP_POS) | (1 << HC595_DS_POS));
}

//Set data bit high
void HC595DataHigh(){
    HC595_PORT |= (1 << HC595_DS_POS);
}

//Set data bit low
void HC595DataLow(){
    HC595_PORT &= (~(1 << HC595_DS_POS));
}

//Sends a clock pulse on SH_CP line
void HC595Pulse(){
    //Pulse the Shift Clock
    HC595_PORT |= (1 << HC595_SH_CP_POS);     //HIGH
    HC595_PORT &= (~(1 << HC595_SH_CP_POS));  //LOW
}

//Sends a clock pulse on ST_CP line
void HC595Latch(){
   //Pulse the Store Clock
   HC595_PORT |= (1 << HC595_ST_CP_POS);//HIGH
   _delay_loop_1(1);
   HC595_PORT &= (~(1 << HC595_ST_CP_POS));//LOW
   _delay_loop_1(1);
}


void HC595Write(uint8_t data[]){
    CD4017Init();
    for(uint8_t z = 0; z < 24; z++){
	if(data[z] == 0){
	    HC595DataLow();
	}else{
	    HC595DataHigh();
	}
	HC595Pulse();
	if(z == 8 || z == 16 || z == 24){
	    HC595Latch();
	}
    }
    //CD4017Pulse();
    

    /*

    //Send each 8 bits serially
    //Order is MSB first
    for(uint8_t i=0;i<8;i++){
	//Output the data on DS line according to the
	//Value of MSB
	if(data & 0b10000000){
	    //MSB is 1 so output high
	    
	    HC595DataHigh();
	}else{
	    //MSB is 0 so output high
	    HC595DataLow();
	}
	HC595Pulse();  //Pulse the Clock line
	data=data<<1;  //Now bring next bit at MSB position
    }
    //Now all 8 bits have been transferred to shift register
    //Move them to output latch at one
    HC595Latch();*/
}
