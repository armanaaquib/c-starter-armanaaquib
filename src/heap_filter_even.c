#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int length;
  int *numbers;
} Evens;


Evens *filter_even(int *, unsigned);
unsigned char is_even(int);

unsigned char is_even(int number){
  return number % 2 == 0;
}

Evens *filter_even(int *numbers, unsigned count)
{
  int temp_evens[count];
  unsigned no_of_even_nos = 0, temp_index = 0;
  int *even_numbers;

  for(int index = 0; index < count; index++)
  {
    int number = numbers[index];

    if(is_even(number))
    {
      temp_evens[temp_index++] = number;
      no_of_even_nos += 1;
    }
  }

  even_numbers = malloc(sizeof(int) * no_of_even_nos);

  for(int index = 0; index < no_of_even_nos; index++)
  {
    even_numbers[index] = temp_evens[index];
  }

  Evens *evens = malloc(sizeof(int) + sizeof(int *));
  evens->length = no_of_even_nos;
  evens->numbers = even_numbers;

  return evens;
}

int main(void)
{
  int numbers[] = {1, 2, 3, 4};

  Evens * evens = filter_even(numbers, 4);

  for(int index = 0; index < evens->length; index++)
  {
    printf("%d ", evens->numbers[index]);
  }
  printf("\n");
  
  return 0;
}
