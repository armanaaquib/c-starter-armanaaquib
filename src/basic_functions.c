#include <stdio.h>
#include <math.h>

unsigned char is_even(int);
unsigned char is_odd(int);
double square(float);
double cube(float);
unsigned gcd(unsigned, unsigned);
unsigned long lcm(unsigned, unsigned);
double simple_interest(float, float, float);

unsigned char is_even(int number){
  return number % 2 == 0;
}

unsigned char is_odd(int number){
  return ! is_even(number);
}

double square(float number){
  return pow(number, 2);
}

double cube(float number){
  return square(number) * number;
}

unsigned gcd(unsigned num1, unsigned num2){
  unsigned greatest_common_divisor;
  unsigned dividend = num1;
  unsigned divisor = num2;

  if(num2 > num1)
  {
    dividend = num2;
    divisor = num1;
  }

  greatest_common_divisor = dividend;

  while(divisor != 0)
  {
    greatest_common_divisor = divisor;
    divisor = dividend % divisor;
    dividend = greatest_common_divisor;
  }

  return greatest_common_divisor;
}

unsigned long lcm(unsigned num1, unsigned num2)
{
  return (unsigned long) (num1 * num2) / gcd(num1, num2);
}

double simple_interest(float principal_amount, float interest_rate, float duration){
  return principal_amount * interest_rate * duration / 100;
}

int main(void)
{
  int number;
  float float_number, principal_amount, interest_rate, duration;
  unsigned num1, num2;

  printf("1. isEven\n");
  printf("Enter a Number: ");
  scanf("%d", &number);
  printf("is_even(%d): %s\n\n", number, is_even(number)?"EVEN":"NOT EVEN");

  printf("2. isOdd\n");
  printf("Enter a Number: ");
  scanf("%d", &number);
  printf("is_odd(%d): %s\n\n", number, is_odd(number)?"ODD":"NOT ODD");

  printf("3. square\n");
  printf("Enter a Number: ");
  scanf("%f", &float_number);
  printf("square(%f): %lf\n\n", float_number, square(float_number));

  printf("4. cube\n");
  printf("Enter a Number: ");
  scanf("%f", &float_number);
  printf("cube(%f): %lf\n\n", float_number, cube(float_number));

  printf("5. gcd\n");
  printf("Enter Number1,Number2: ");
  scanf("%u,%u", &num1, &num2);
  printf("gcd(%u, %u): %u\n\n", num1, num2, gcd(num1, num2));

  printf("5. lcm\n");
  printf("Enter Number1,Number2: ");
  scanf("%u,%u", &num1, &num2);
  printf("lcm(%u, %u): %lu\n\n", num1, num2, lcm(num1, num2));

  printf("6. Simple Interest\n");
  printf("Enter Principal Amount,Interest Rate,Duration: ");
  scanf("%f,%f,%f", &principal_amount, &interest_rate, &duration);
  printf("simple_interest(%f, %f, %f): ", principal_amount, interest_rate, duration);
  printf("%lf\n\n", simple_interest(principal_amount, interest_rate, duration));

  return 0;
}
