#ifndef LED_LETTERS_H
#define LED_LETTERS_H

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

const char* numbers[10] = {zero, one, two, three, four, five, six, seven, eight, nine};

#endif
