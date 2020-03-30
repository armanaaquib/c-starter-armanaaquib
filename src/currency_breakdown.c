#include <stdio.h>

void print_currency_breakdown(unsigned long);
unsigned get_notes_count(unsigned long, unsigned);
void print_notes_count(unsigned long, unsigned);
unsigned long deduct_money(unsigned long, unsigned);

unsigned get_notes_count(unsigned long amount, unsigned denomination)
{
  return amount / denomination;
}

void print_notes_count(unsigned long amount, unsigned denomination)
{
  unsigned no_of_notes = get_notes_count(amount, denomination);

  if(no_of_notes)
  {
    printf("%u x Rs %u\n", no_of_notes, denomination);
  }
}

unsigned long deduct_money(unsigned long money, unsigned denomination)
{
  return money - get_notes_count(money, denomination) * denomination;
}

void print_currency_breakdown(unsigned long amount)
{
  unsigned long money = amount;
  unsigned no_of_notes, denomination;

  denomination = 2000;
  print_notes_count(money, denomination);
  money = deduct_money(money, denomination);

  denomination = 500;
  print_notes_count(money, denomination);
  money = deduct_money(money, denomination);

  denomination = 200;
  print_notes_count(money, denomination);
  money = deduct_money(money, denomination);

  denomination = 100;
  print_notes_count(money, denomination);
  money = deduct_money(money, denomination);

  denomination = 50;
  print_notes_count(money, denomination);
  money = deduct_money(money, denomination);

  denomination = 10;
  print_notes_count(money, denomination);
  money = deduct_money(money, denomination);

  denomination = 5;
  print_notes_count(money, denomination);
  money = deduct_money(money, denomination);

  denomination = 1;
  print_notes_count(money, denomination);
  money = deduct_money(money, denomination);
}

int main(void)
{
  unsigned long int amount;

  printf("Currency Breakdown(ATM)\n");
  printf("Enter an amount: ");
  scanf("%lu", &amount);
  print_currency_breakdown(amount);

  return 0;
}