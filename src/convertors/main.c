#include <stdio.h>
#include "convert.h"

int main(void)
{
  int num = 10;
  unsigned index;
  thirty_two_bits bits;

  convert_to_binary(num, bits);
  
  printf("0b%s\n", bits);

  return 0;
}