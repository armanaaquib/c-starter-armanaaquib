typedef unsigned char thirty_two_bits[33];
typedef unsigned char eight_hexadecimals[9];
typedef unsigned short ushort;

#define ITERATE(start, end) for(ushort index = start; index < end; index++)

void convert_to_binary(int, thirty_two_bits);
void convert_to_hexadecimal(int, eight_hexadecimals);
void print_binary(int);
void print_hexadecimal(int);

unsigned char get_bit(int bit);