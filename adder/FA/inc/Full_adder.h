#ifndef __FA_ADDER__
#define __FA_ADDER__


#include <systemc.h> 
#include "Half_adder.h"



SC_MODULE( Full_Adder )
{

	sc_in<bool> InA;
	sc_in<bool> InB;
	sc_in<bool> Cin;
	sc_out<bool> S;
	sc_out<bool> C;
	sc_signal<bool> S_sig;
	sc_signal<bool> C_sig;
	sc_signal<bool> C_2;
	Half_Adder *HA1, *HA2;
	void Full_Adder_Proc(void);

	SC_CTOR( Full_Adder )
	{
		SC_METHOD( Full_Adder_Proc );
		sensitive << InA << InB << Cin;
		(*HA1) (InA, InB, S_sig, C_sig);
		(*HA2) (S_sig, Cin, S, C_2);
	}
};




#endif
