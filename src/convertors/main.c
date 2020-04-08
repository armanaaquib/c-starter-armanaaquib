#include <stdio.h>
#include "convert.h"

int main(void)
{
  int num = 10;
  unsigned index;
  thirty_two_bits bits;
  eight_hexadecimals hexadecimals;

  convert_to_binary(num, bits);
  convert_to_hexadecimal(num, hexadecimals);
  
  printf("0b%s\n", bits);
  printf("0x%s\n", hexadecimals);

  return 0;
}