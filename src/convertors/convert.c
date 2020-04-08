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
  unsigned index, len = 32;

  for(index = 0; index < len; index++)
  {
    bits[index] = get_bit(number & mask);
    mask >>= 1;
  }

  bits[index] = '\0';
}

void convert_to_hexadecimal(unsigned number, eight_hexadecimals hexadecimals)
{
  unsigned index, len = 8, decimal;

  for(index = 0; index < len; index++)
  {
    decimal = (number << index * 4) >> 28;
    hexadecimals[index] = HEXADECIMALS[decimal];
  }

  hexadecimals[index] = '\0';
}

void print_binary(int number)
{
  thirty_two_bits bits;
  convert_to_binary(number, bits);
  printf("0b%s\n", bits);
}

void print_hexadecimal(unsigned number)
{
  eight_hexadecimals hexadecimals;
  convert_to_hexadecimal(number, hexadecimals);
  printf("0x%s\n", hexadecimals);
}
