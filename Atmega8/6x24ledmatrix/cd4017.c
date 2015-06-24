#include <avr/io.h>
#include <util/delay.h>
#include "cd4017.h"
#include "stdint.h"

#define CD4017_DDR        DDRC
#define CD4017_PORT       PORTC
#define CD4017_SC         PINC5    //Shift clock
#define CD4017_RESET      PINC4    //Row reset

//CD4017 INIT
void CD4017Init(void){
    CD4017_DDR |= 1 << CD4017_SC;
    CD4017_PORT &= ~ 1 << CD4017_SC;
}

//Send's a pulse to the clock
void CD4017Pulse(void){
    CD4017_PORT |= 1 << CD4017_SC;
    _delay_ms(2);
    CD4017_PORT &= ~ 1 << CD4017_SC;
}

//Send's a pulse to reset the row's
void CD4017Reset(void){
    CD4017_PORT |= 1 << CD4017_RESET;
    _delay_ms(2);
    CD4017_PORT &= ~ 1 << CD4017_RESET;
}
