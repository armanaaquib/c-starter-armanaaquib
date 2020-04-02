#include <stdio.h>

void currency_breakdown(unsigned long, unsigned *, unsigned *, unsigned);

void currency_breakdown(unsigned long amount, unsigned * denoms, unsigned * no_of_notes, unsigned length)
{
  unsigned long money = amount;
  unsigned index;

  for(index = 0; index < length; index++)
  {
    no_of_notes[index] = money / denoms[index];
    money = money % denoms[index];
  }
}

int main(void)
{
  unsigned long amount;
  unsigned denominations[8] = {2000, 500, 200, 100, 50, 10, 5, 1};
  unsigned no_of_notes[8], index;

  printf("Currency Breakdown(ATM)\n");
  printf("Enter an amount: ");
  scanf("%lu", &amount);
  currency_breakdown(amount, denominations, no_of_notes, 8);

  for(index = 0; index < 8; index++)
  {
    printf("%u x Rs %u\n", no_of_notes[index], denominations[index]);
  }

  return 0;
}