#include <stdio.h>

unsigned long long factorial(unsigned);
void print_fibonacci(unsigned);
void print_odd_numbers(unsigned);
void print_even_numbers(unsigned);

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

void print_fibonacci(unsigned number)
{
  unsigned term1 = 0, term2 = 1, count, sum;

  for(count = 0; count < number; count++)
  {
    printf("%d ", term1);
    sum = term1 + term2;
    term1 = term2;
    term2 = sum;
  }
}

void print_odd_numbers(unsigned number)
{
  unsigned odd_number;

  for(odd_number = 1; odd_number <= number; odd_number += 2)
  {
    printf("%d ", odd_number);
  }
}

void print_even_numbers(unsigned number)
{
  unsigned even_number;

  for(even_number = 0; even_number <= number; even_number += 2)
  {
    printf("%d ", even_number);
  }
}

int main(void)
{
  unsigned number;

  printf("1. Factorial\n");
  printf("Enter a Numbers: ");
  scanf("%u", &number);
  printf("factorial(%u): %llu\n\n", number, factorial(number));

  printf("2. Fibonacci\n");
  printf("Enter a Count: ");
  scanf("%d", &number);
  print_fibonacci(number);
  printf("\n\n");

  printf("3. Odd Number Series");
  printf("Enter a positive number: ");
  scanf("%u", &number);
  print_odd_numbers(number);
  printf("\n\n");

  printf("4. Even Number Series");
  printf("Enter a positive number: ");
  scanf("%u", &number);
  print_even_numbers(number);
  printf("\n\n");

  return 0;
}