#include <stdio.h>

typedef unsigned char thirty_two_bits[32];

void convert_to_binary(int, thirty_two_bits);
unsigned char get_bit(int bit);

const unsigned BITS[32] = {
    0x80000000, 0x40000000, 0x20000000, 0x10000000,
    0x8000000, 0x4000000, 0x2000000, 0x1000000,
    0x800000, 0x400000, 0x200000, 0x100000,
    0x80000, 0x40000, 0x20000, 0x10000,
    0x8000, 0x4000, 0x2000, 0x1000,
    0x800, 0x400, 0x200, 0x100,
    0x80, 0x40,  0x20, 0x10,
    0x8,  0x4,  0x2, 0x1
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
  unsigned index, len = 32;

  for(index = 0; index < len; index++)
  {
    bits[index] = get_bit(number & BITS[index]);
  }
}

int main(void)
{
  int num = 10;
  unsigned index;
  thirty_two_bits bits;

  convert_to_binary(num, bits);

  for(index = 0; index < 32; index++)
  {
    if(index % 8 == 0)
    {
      printf(" ");
    }

    printf("%c", bits[index]);
  }
  printf("\n");

  return 0;
}