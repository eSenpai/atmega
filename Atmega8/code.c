#define pin9 PIND1
#define pin8 PIND2
#define pin7 PINC3
#define pin6 PINC4
#define pin5 PIND0
#define pin4 PINC2
#define pin3 PINC5
#define pin2 PIND3
#define pin1 PINC1
#define l1 PIND6
#define l2 PIND7
#define l3 PINB0

#include <avr/io.h>
#include <util/delay.h>

void clear(void);
void initLed(void);
void layer1(void);
void layer2(void);
void layerUpDown(void);
void spin(void);

int main(void){
    initLed();

    while(1){
        layerUpDown();

    }
}

void clear(void){
    PORTC &= ~ 1 << pin1;
    PORTD &= ~ 1 << pin2;
    PORTC &= ~ 1 << pin3;
    PORTC &= ~ 1 << pin4;
    PORTD &= ~ 1 << pin5;
    PORTC &= ~ 1 << pin6;
    PORTC &= ~ 1 << pin7;
    PORTD &= ~ 1 << pin8;
    PORTD &= ~ 1 << pin9;
    PORTD &= ~ 1 << l1;
    PORTD &= ~ 1 << l2;
    PORTB &= ~ 1 << l3;
}

void initLed(void){
    DDRC |= 1 << pin1;
    DDRD |= 1 << pin2;
    DDRC |= 1 << pin3;
    DDRC |= 1 << pin4;
    DDRD |= 1 << pin5;
    DDRC |= 1 << pin6;
    DDRC |= 1 << pin7;
    DDRD |= 1 << pin8;
    DDRD |= 1 << pin9;
    DDRD |= 1 << l1;
    DDRD |= 1 << l2;
    DDRB |= 1 << l3;
}

void layer1(void){
    PORTD |= 1 << l1;
    PORTC |= 1 << pin1;
    _delay_ms(10);
    PORTC &= ~ 1 << pin1;
    PORTD |= 1 << pin2;
    _delay_ms(10);
    PORTD &= ~ 1 << pin2;
    PORTC |= 1 << pin3;
    _delay_ms(10);
    PORTC &= ~ 1 << pin3;
    PORTC |= 1 << pin4;
    _delay_ms(10);
    PORTC &= ~ 1 << pin4;
    PORTD |= 1 << pin5;
    _delay_ms(10);
    PORTD &= ~ 1 << pin5;
    PORTC |= 1 << pin6;
    _delay_ms(10);
    PORTC &= ~ 1 << pin6;
    PORTC |= 1 << pin7;
    _delay_ms(10);
    PORTC &= ~ 1 << pin7;
    PORTD |= 1 << pin8;
    _delay_ms(10);
    PORTD &= ~ 1 << pin8;
    PORTD |= 1 << pin9;
    _delay_ms(10);
    PORTD &= ~ 1 << pin9;
    PORTD &= ~ 1 << l1;
    _delay_ms(10);
}

void layer2(void){
    PORTD |= 1 << l2;
    PORTC |= 1 << pin1;
    _delay_ms(10);
    PORTC &= ~ 1 << pin1;
    PORTD |= 1 << pin2;
    _delay_ms(10);
    PORTD &= ~ 1 << pin2;
    PORTC |= 1 << pin3;
    _delay_ms(10);
    PORTC &= ~ 1 << pin3;
    PORTC |= 1 << pin4;
    _delay_ms(10);
    PORTC &= ~ 1 << pin4;
    PORTD |= 1 << pin5;
    _delay_ms(10);
    PORTD &= ~ 1 << pin5;
    PORTC |= 1 << pin6;
    _delay_ms(10);
    PORTC &= ~ 1 << pin6;
    PORTC |= 1 << pin7;
    _delay_ms(10);
    PORTC &= ~ 1 << pin7;
    PORTD |= 1 << pin8;
    _delay_ms(10);
    PORTD &= ~ 1 << pin8;
    PORTD |= 1 << pin9;
    _delay_ms(10);
    PORTD &= ~ 1 << pin9;
    PORTD &= ~ 1 << l2;
    _delay_ms(10);
}

void layer3(void){
    PORTB |= 1 << l3;
    PORTC |= 1 << pin1;
    _delay_ms(10);
    PORTC &= ~ 1 << pin1;
    PORTD |= 1 << pin2;
    _delay_ms(10);
    PORTD &= ~ 1 << pin2;
    PORTC |= 1 << pin3;
    _delay_ms(10);
    PORTC &= ~ 1 << pin3;
    PORTC |= 1 << pin4;
    _delay_ms(10);
    PORTC &= ~ 1 << pin4;
    PORTD |= 1 << pin5;
    _delay_ms(10);
    PORTD &= ~ 1 << pin5;
    PORTC |= 1 << pin6;
    _delay_ms(10);
    PORTC &= ~ 1 << pin6;
    PORTC |= 1 << pin7;
    _delay_ms(10);
    PORTC &= ~ 1 << pin7;
    PORTD |= 1 << pin8;
    _delay_ms(10);
    PORTD &= ~ 1 << pin8;
    PORTD |= 1 << pin9;
    _delay_ms(10);
    PORTD &= ~ 1 << pin9;
    PORTB &= ~ 1 << l3;
    _delay_ms(10);
}

void layerUpDown(void){
    layer1();
    _delay_ms(400);
    layer2();
    _delay_ms(400);
    layer3();
    _delay_ms(400);
}
/*
#define pin9 PIND1
#define pin8 PIND2
#define pin7 PINC3
#define pin6 PINC4
#define pin5 PIND0
#define pin4 PINC2
#define pin3 PINC5
#define pin2 PIND3
#define pin1 PINC1
#define l1 PIND6
#define l2 PIND7
#define l3 PINB0
*/

void spin(void){
    
}
