#include <stdio.h>
#include <stdlib.h>

#define ITERATE(start, end) for(unsigned index = start; index < end; index++)

typedef struct
{
  int length;
  int *numbers;
} Evens;


Evens *filter_even(int *, unsigned);
unsigned char is_even(int);
void print_numbers(int *, unsigned);
void input_numbers(int *, unsigned);

unsigned char is_even(int number){
  return number % 2 == 0;
}

Evens *filter_even(int *numbers, unsigned count)
{
  int temp_evens[count];
  unsigned no_of_even_nos = 0, temp_index = 0;
  int *even_numbers;

  ITERATE(0, count)
  {
    int number = numbers[index];

    if(is_even(number))
    {
      temp_evens[temp_index++] = number;
      no_of_even_nos += 1;
    }
  }

  even_numbers = malloc(sizeof(int) * no_of_even_nos);

  ITERATE(0, no_of_even_nos)
  {
    even_numbers[index] = temp_evens[index];
  }

  Evens *evens = malloc(sizeof(int) + sizeof(int *));
  evens->length = no_of_even_nos;
  evens->numbers = even_numbers;

  return evens;
}

void print_numbers(int *array, unsigned length)
{
  ITERATE(0, length)
  {
    printf("%d ", array[index]);
  }
  printf("\n");
}

void input_numbers(int *array, unsigned length)
{
  printf("Enter %d numbers: ", length);
  ITERATE(0, length)
  {
    scanf("%d,", &array[index]);
  }
}

int main(void)
{
  unsigned length;
  int *numbers;

  printf("Enter length: ");
  scanf("%d", &length);

  numbers = malloc(sizeof(int) * length);

  input_numbers(numbers, length);

  Evens * evens = filter_even(numbers, length);

  printf("Even Numbers: ");
  print_numbers(evens->numbers, evens->length);

  return 0;
}
