#ifndef __REG_FORMAT_H
#define __REG_FORMAT_H
#include <systemc.h>
#include <stdio.h>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;

int StrCnt(char *src);

class SReg_32 {
	private:
	char *reg_name;
	sc_uint<32> Register;

	public:
	SReg_32(char *name_in, sc_uint<32> val_in);
	SReg_32(char *name_in);
	void getRegName(void);
};

#endif // __REG_FORMAT_H
