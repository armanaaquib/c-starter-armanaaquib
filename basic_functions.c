#include <stdio.h>

unsigned char is_even(int);
unsigned char is_odd(int);

unsigned char is_even(int number){
  return number % 2 == 0 ? 'T' : 'F';
}

unsigned char is_odd(int number){
  return is_even(number) == 'T' ? 'F' : 'T';
}

int main(void)
{
  printf("is 2 Even? %c\n", is_even(2));
  printf("is 1 Even? %c\n", is_even(1));

  printf("is 1 Odd? %c\n", is_odd(1));
  printf("is 2 Odd? %c\n", is_odd(2));

  return 0;
}
