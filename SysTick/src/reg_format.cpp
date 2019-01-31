#include "../inc/reg_format.h"

int StrCnt(char *src) {
	int cnt;
	cnt = 0;
	while(src[++cnt] != '\0'); 

	return cnt;
}

SReg_32::SReg_32(char *name_in, sc_uint<32> val_in) {
	// To count the size of the register name
	int cnt = StrCnt(name_in);

	reg_name = new char[cnt];
	strncpy(reg_name, name_in, cnt);
	Register.range(31, 0) = val_in.range(31, 0);
	
	getRegName();
	cout << " is created and initialised (the value is given): " << Register.to_string(SC_HEX) << endl; 
		
}

SReg_32::SReg_32(char *name_in) {
	// To count the size of the register name
	int cnt = StrCnt(name_in);

	reg_name = new char[cnt];
	strncpy(reg_name, name_in, cnt);
	Register.range(31, 0) = 0x00000000;
	
	getRegName();
	cout << " is created and initialised: " << Register.to_string(SC_HEX) << endl; 
}

void SReg_32::getRegName(void) {
	printf("Register \"%s\"", reg_name);
}

