#include <stdio.h>

unsigned long long factorial(unsigned);
void print_fibonacci(unsigned);
void print_odd_numbers(unsigned);
void print_even_numbers(unsigned);
void print_multiplication_table(int, unsigned);
unsigned long sum_of_N_numbers(unsigned, unsigned);
unsigned long product_of_N_numbers(unsigned, unsigned);
void print_all_odd_numbers(unsigned, unsigned);
void print_every_nth_number(int, int, unsigned);

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

void print_multiplication_table(int number, unsigned length)
{
  unsigned count;
  long mul;

  for(count = 1; count <= length; count++)
  {
    mul = number * (int)count;
    printf("%d X %u = %ld\n", number, count, mul);
  }
}

unsigned long sum_of_N_numbers(unsigned number, unsigned length)
{
  long sum = 0;
  unsigned count;

  for(count = 0; count < length; count++)
  {
    sum += number + count;
  }

  return sum;
}

unsigned long product_of_N_numbers(unsigned number, unsigned length)
{
  long mul = 1;
  unsigned count;

  for(count = 0; count < length; count++)
  {
    mul *= number + count;
  }

  return mul;
}

void print_all_odd_numbers(unsigned start, unsigned end)
{
  unsigned odd_number = start % 2 == 0 ? start + 1 : start;

  while(odd_number <= end)
  {
    printf("%d ", odd_number);
    odd_number += 2;
  }
}

void print_every_nth_number(int num1, int num2, unsigned n)
{
  int num;

  for(num = num1; num <= num2; num += n)
  {
    printf("%d ", num);
  }
}

int main(void)
{
  unsigned number, count;
  int num, num2;

  printf("1. Factorial\n");
  printf("Enter a Numbers: ");
  scanf("%u", &number);
  printf("factorial(%u): %llu\n\n", number, factorial(number));

  printf("2. Fibonacci\n");
  printf("Enter a Count: ");
  scanf("%d", &number);
  print_fibonacci(number);
  printf("\n\n");

  printf("3. Odd Number Series\n");
  printf("Enter a positive number: ");
  scanf("%u", &number);
  print_odd_numbers(number);
  printf("\n\n");

  printf("4. Even Number Series\n");
  printf("Enter a positive number: ");
  scanf("%u", &number);
  print_even_numbers(number);
  printf("\n\n");

  printf("5. Multiplication Table\n");
  printf("Enter Number,Count: ");
  scanf("%d,%u", &num, &count);
  print_multiplication_table(num, count);
  printf("\n\n");

  printf("6. Sum of any N number\n");
  printf("Enter Natural Number,Count: ");
  scanf("%u,%u", &number, &count);
  printf("sum_of_N_numbers(%u, %u): ", number, count);
  printf("%lu\n\n", sum_of_N_numbers(number, count));

  printf("7. Product of any N numbers\n");
  printf("Enter Natural Number,Count: ");
  scanf("%u,%u", &number, &count);
  printf("product_of_N_numbers(%u, %u): ", number, count);
  printf("%lu\n\n", product_of_N_numbers(number, count));

  printf("8. Print all odd numbers between any two numbers\n");
  printf("Enter a number,count: ");
  scanf("%u,%u", &number, &count);
  print_all_odd_numbers(number, count);
  printf("\n\n");

  printf("9. Print every nth number between any two number\n");
  printf("Enter Number1,Number2,n: ");
  scanf("%d,%d,%u", &num, &num2, &count);
  print_every_nth_number(num, num2, count);
  printf("\n\n");

  return 0;
}