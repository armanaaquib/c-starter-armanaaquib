#include <stdio.h>

const unsigned short small_case_ascii_start = 97;
const unsigned short small_case_ascii_end = 122;
const unsigned short capital_case_ascii_start = 65;
const unsigned short capital_case_ascii_end = 90;

void ROT13_cipher(unsigned *, unsigned *, unsigned);
unsigned ROT13_cipher_char(unsigned);
unsigned shift_13_char(unsigned, unsigned short, unsigned short);

unsigned shift_13_char(unsigned ascii, unsigned short start_ascii, unsigned short end_ascii)
{
  unsigned shifted_ascii = ascii + 13;
  
  if(shifted_ascii > end_ascii)
  {
    shifted_ascii = shifted_ascii - end_ascii + start_ascii - 1;
  }

  return shifted_ascii;
}

unsigned ROT13_cipher_char(unsigned ascii)
{
  if(ascii >= small_case_ascii_start && ascii <= small_case_ascii_end)
  {
    return shift_13_char(ascii, small_case_ascii_start, small_case_ascii_end);
  }

  if(ascii >= capital_case_ascii_start && ascii <= capital_case_ascii_end)
  {
    return shift_13_char(ascii, capital_case_ascii_start, capital_case_ascii_end);
  }

  return ascii;
}

void ROT13_cipher(unsigned * enc_ascii_seq, unsigned * dec_ascii_seq, unsigned len)
{
  unsigned index;

  for(index = 0; index < len; index++)
  {
    dec_ascii_seq[index] = ROT13_cipher_char(enc_ascii_seq[index]);
  }
}

int main(void)
{
  unsigned genome_seq[9] = {116, 98, 32, 112,98, 101, 98,  97, 110};
  // unsigned genome_seq[9] = {103, 111, 32, 99, 111, 114, 111, 110, 97};
  unsigned dec_genome_seq[9], index;

  ROT13_cipher(genome_seq, dec_genome_seq, 9);

  for(index = 0; index < 9; index++)
  {
    printf("%c", dec_genome_seq[index]);
  }
  printf("\n");

  return 0;
}