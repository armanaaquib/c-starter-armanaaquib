#include <stdio.h>
#include <math.h>

unsigned char is_even(int);
unsigned char is_odd(int);
double square(double);
double cube(double);

unsigned char is_even(int number){
  return number % 2 == 0;
}

unsigned char is_odd(int number){
  return ! is_even(number);
}

double square(double number){
  return pow(number, 2);
}

double cube(double number){
  return square(number) * number;
}

int main(void)
{
  int number;

  printf("1. isEven\n");
  printf("Enter a Number: ");
  scanf("%d", &number);
  printf("%d: %s\n\n", number, is_even(number)?"EVEN":"NOT EVEN");

  printf("2. isOdd\n");
  printf("Enter a Number: ");
  scanf("%d", &number);
  printf("%d: %s\n\n", number, is_odd(number)?"ODD":"NOT ODD");

  printf("3. square\n");
  printf("Enter a Number: ");
  scanf("%d", &number);
  printf("%d: %lf\n\n", number, square(number));

  printf("4. cube\n");
  printf("Enter a Number: ");
  scanf("%d", &number);
  printf("%d: %lf\n\n", number, cube(number));

  return 0;
}
