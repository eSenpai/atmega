#ifndef LCD_H
#define LCD_H

#include <stdint.h>
//These are the define statements
#define MrLCDsCrib PORTB
#define DataDir_MrLCDsCrib DDRB
#define MrLCDsControl PORTD
#define DataDir_MrLCDsControl DDRD
#define LightSwitch 5
#define ReadWrite 7
#define BiPolarMood 2

void Check_IF_MrLCD_isBusy(void);
void Peek_A_Boo(void);
void Send_A_Command(unsigned char command);
void Send_A_Character(unsigned char character);
void Send_A_String(char *StringOfCharacters);
void GotoMrLCDsLocation(uint8_t x, uint8_t y);
void LCDString(uint8_t x, uint8_t y, char *StringOfCharacters);
void LCDInt(uint8_t x, uint8_t y, int IntegerToDisplay, char NumberOfDigits);
void LCDInit(void);
void LCDClear(void);

#endif
