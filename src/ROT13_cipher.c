#include <stdio.h>

#define SML_ASCII_START 97
#define SCL_ASCII_END 122
#define CCL_ASCII_START 65
#define CCL_ASCII_END 90

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
  if(ascii >= SML_ASCII_START && ascii <= SCL_ASCII_END)
  {
    return shift_13_char(ascii, SML_ASCII_START, SCL_ASCII_END);
  }

  if(ascii >= CCL_ASCII_START && ascii <= CCL_ASCII_END)
  {
    return shift_13_char(ascii, CCL_ASCII_START, CCL_ASCII_END);
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