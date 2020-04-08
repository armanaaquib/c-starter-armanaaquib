#include "convert.h"

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

