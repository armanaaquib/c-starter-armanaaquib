#include <stdio.h>

unsigned char is_even(int);

unsigned char is_even(int number){
  return number % 2 == 0 ? 'T' : 'F';
}

int main(void)
{
  printf("is 2 Even? %c\n", is_even(2));
  printf("is 1 Even? %c\n", is_even(1));
  return 0;
}
