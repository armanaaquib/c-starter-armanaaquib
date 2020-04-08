#include <stdio.h>
#include "convert.h"

#define NEW_LINE printf("\n");

int main(void)
{
  int num = 20;

  print_binary(num);
  print_hexadecimal(num);

  return 0;
}