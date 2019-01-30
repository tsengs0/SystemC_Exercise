#ifndef __MUX_H
#define __MUX_H

#include <systemc>

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

SC_MODULE( mux_2x1 )
{
	sc_in< sc_uint<1> > Data0;
	sc_in< sc_uint<1> > Data1;
	sc_in< sc_uint<1> > SEL;
	sc_out<bool> Dout;

	void MUX_Proc(void);

	SC_CTOR( mux_2x1 )
	{

		SC_METHOD( MUX_Proc );
		sensitive << Data0 << Data1 << SEL;

	}
};

#endif // __MUX_H
