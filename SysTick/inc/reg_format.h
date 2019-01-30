#ifndef __REG_FORMAT_H
#define __REG_FORMAT_H
#include <systemc.h>
#include <stdio.h>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;

int StrCnt(char *src) {
	int cnt;
	cnt = 0;
	while(src[++cnt] != '\0'); 

	return cnt;
}

class SReg_32 {
	private:
	char *reg_name;
	sc_uint<32> Register;

	public:
	SReg_32(char *name_in, sc_uint<32> val_in) {
		// To count the size of the register name
		int cnt = StrCnt(name_in);

		reg_name = new char[cnt];
		strncpy(reg_name, name_in, cnt);
		Register.range(31, 0) = val_in.range(31, 0);
		
		getRegName();
		cout << " is created and initialised (the value is given): " << Register.to_string(SC_HEX) << endl; 
		
	}

	SReg_32(char *name_in) {
		// To count the size of the register name
		int cnt = StrCnt(name_in);

		reg_name = new char[cnt];
		strncpy(reg_name, name_in, cnt);
		Register.range(31, 0) = 0x00000000;
		
		getRegName();
		cout << " is created and initialised: " << Register.to_string(SC_HEX) << endl; 
	}

	void getRegName(void) {
		printf("Register \"%s\"", reg_name);
	}
};

#endif // __REG_FORMAT_H
