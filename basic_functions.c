#include <stdio.h>
#include <math.h>

unsigned char is_even(int);
unsigned char is_odd(int);
double square(double);
double cube(double);

unsigned char is_even(int number){
  return number % 2 == 0 ? 'T' : 'F';
}

unsigned char is_odd(int number){
  return is_even(number) == 'T' ? 'F' : 'T';
}

double square(double number){
  return pow(number, 2);
}

double cube(double number){
  return square(number) * number;
}

int main(void)
{
  printf("is 2 Even? %c\n", is_even(2));
  printf("is 1 Even? %c\n", is_even(1));

  printf("is 1 Odd? %c\n", is_odd(1));
  printf("is 2 Odd? %c\n", is_odd(2));

  printf("Square of 2: %lf\n", square(2));
  printf("Square of 2.2: %lf\n", square(2.2));

  printf("Cube of 2: %lf\n", cube(2));
  printf("Cube of 2.2: %lf\n", cube(2.2));

  return 0;
}
