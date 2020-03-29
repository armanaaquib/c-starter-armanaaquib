#include <stdio.h>

unsigned long long factorial(unsigned);

unsigned long long factorial(unsigned number)
{
  unsigned long long fact = 1;
  unsigned num;
  
  for(num = number; num > 0; num--)
  {
    fact *= num;
  }

  return fact;
}

int main(void)
{
  unsigned number;

  printf("1. Factorial\n");
  printf("Enter a Numbers: ");
  scanf("%u", &number);
  printf("factorial(%u): %llu\n\n", number, factorial(number));

  return 0;
}