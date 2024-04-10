#ifndef LED_LETTERS_H
#define LED_LETTERS_H

const char spacech[] = 
{
  0b00000
};

const char exclamation[] =
{
  0b11101,
  0b00000  
};

const char dquote[] =
{
  0b11000,
  0b100000,
  0b11000,
  0b00000,
  
};

const char colon[] =
{
  0b01010,
  0b00000 
};

const char one[] = 
{
0b01001,
0b11111,
0b00001,
0b00000,
};

const char two[] = 
{
0b10111,
0b10101,
0b11101,
0b00000,
};

const char three[] = 
{
0b10101,
0b10101,
0b11111,
0b00000,
};

const char four[] = 
{
0b11100,
0b00100,
0b11111,
0b00000,
};

const char five[] = 
{
0b11101,
0b10101,
0b10111,
0b00000,
};

const char six[] = 
{
0b11111,
0b00101,
0b00111,
0b00000,
};

const char seven[] = 
{
0b11100,
0b10000,
0b11111,
0b00000,
};

const char eight[] = 
{
0b11111,
0b10101,
0b11111,
0b00000,
};

const char nine[] = 
{
0b11100,
0b10100,
0b11111,
0b00000,
};

const char zero[] = 
{
0b11111,
0b10001,
0b11111,
0b00000,
};

const char none[] = 
{
  0b00000
};

const char* numbers[10] = {zero, one, two, three, four, five, six, seven, eight, nine};
const char* ascii_letters[128]=
{
  //control character 0 ~ 31
  none,none,none,none,none, // 0~4
  none,none,none,none,none, // 5~9
  none,none,none,none,none, // 10~14
  none,none,none,none,none, // 15~19
  none,none,none,none,none, // 20~24
  none,none,none,none,none, // 25~29
  none,none, // 30~31

  //display character 32 ~ 126
  spacech, exclamation, dquote, none, none, // 32~36
  none, none, none, none, none, // 37~41
  none, none, none, none, none, // 42~46
  none, zero, one, two, three, // 47~51
  four, five, six, seven, eight, // 52~56
  nine, colon, none, none, none, // 57~61
  none, none, none, none, none, // 62~66
  none, none, none, none, none, // 67~71
  none, none, none, none, none, // 72~76
  none, none, none, none, none, // 77~81
  none, none, none, none, none, // 82~86
  none, none, none, none, none, // 87~91
  none, none, none, none, none, // 92~96
  none, none, none, none, none, // 97~101
  none, none, none, none, none, // 102~106
  none, none, none, none, none, // 107~111
  none, none, none, none, none, // 112~116
  none, none, none, none, none, // 117~121
  none, none, none, none, none, // 122~126

  none // 127
};

#endif
