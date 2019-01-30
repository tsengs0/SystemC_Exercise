#include <systemc.h>

int sc_main(int argc, char **argv)
{
	// Note that, sc_int cannot be more than 64-bit
	sc_int<1> bit_size = 0;
	sc_int<4> nibble_size = 1;
	sc_int<8> byte_size = 2;
	sc_int<32> word_size = 3;
	
	// sc_bigint allow the designer to work on integers of any size (more than 64-bit is valid)
	sc_bigint<128> large_size;

	word_size++;
	cout << "Value of word_size: " << word_size << endl;

	byte_size += nibble_size;
	cout << "Value of byte_size: " << byte_size << endl;

	bit_size = word_size[2];
	cout << "Value of bit_size: " << bit_size << endl;

	nibble_size = word_size.range(4,1);
	cout << "Value of nibble_size: " << nibble_size << endl;

	word_size = (byte_size, byte_size, byte_size, byte_size);
	cout << "Value of word_size: " << word_size << endl;

	large_size = 1000 << 1;
	cout << "Value of large_size: " << large_size << endl;

	return 0;
}



