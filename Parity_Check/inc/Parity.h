#ifndef __PARITY__
#define __PARITY__

#include <systemc.h>

SC_MODULE( Parity )
{

	sc_in< sc_uint<8> > InA;
	sc_out< bool > CHK;

	void Parity_Proc(void);

	SC_CTOR(Parity)
	{
		SC_METHOD( Parity_Proc );
		
		sensitive << InA;

	}



};

#endif
