#include <stdio.h>
#include "convert.h"

const char HEXADECIMALS[] = {
    '0', '1', '2', '3', 
    '4', 'f', '6', '7', 
    '8', '9', 'a', 'b', 
    'c', 'd', 'e', 'f'
};

unsigned char get_bit(int number)
{ 
  if(number){
    return '1';
  }

  return '0';
}

void convert_to_binary(int number, thirty_two_bits bits)
{
  unsigned mask = 0x80000000;
  unsigned len = 32;

  ITERATE(0, len)
  {
    bits[index] = get_bit(number & mask);
    mask >>= 1;
  }

  bits[len] = '\0';
}

void convert_to_hexadecimal(int number, eight_hexadecimals hexadecimals)
{
  unsigned mask = 0xf;
  unsigned len = 8, decimal;

  ITERATE(0, len)
  {
    decimal = (number << index * 4) >> 28;
    hexadecimals[index] = HEXADECIMALS[mask & decimal];
  }

  hexadecimals[len] = '\0';
}

void print_binary(int number)
{
  thirty_two_bits bits;
  convert_to_binary(number, bits);
  printf("0b%s\n", bits);
}

void print_hexadecimal(int number)
{
  eight_hexadecimals hexadecimals;
  convert_to_hexadecimal(number, hexadecimals);
  printf("0x%s\n", hexadecimals);
}
