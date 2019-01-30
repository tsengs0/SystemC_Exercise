#ifndef __COMPARATOR__
#define __COMPARATOR__

#include <systemc.h>

SC_MODULE( Comparator )
{
	sc_in< sc_uint<4> > InA;
	sc_in< sc_uint<4> > InB;
	sc_out< bool > GT;
	sc_out< bool > EQ;

	void Comparator_Proc(void);

	SC_CTOR( Comparator )
	{
		SC_METHOD( Comparator_Proc );
		sensitive << InA << InB;
	}

};

#endif
