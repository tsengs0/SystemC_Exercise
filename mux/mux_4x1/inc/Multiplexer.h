#ifndef __MUX__
#define __MUX__


#include <systemc.h>

SC_MODULE( mux_4x1 )
{

	sc_in< sc_uint<4> > Data;
	sc_in< sc_uint<2> > SEL;
	sc_out<bool> Dout;

	void MUX_Proc(void);

	SC_CTOR( mux_4x1 )
	{

		SC_METHOD( MUX_Proc );
		sensitive << Data << SEL;

	}




};






#endif
