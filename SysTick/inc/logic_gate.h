#ifndef __LOGIC_GATE_H
#define __LOGIC_GATE_H
#include <systemc.h>

SC_MODULE( Inverter )
{
	sc_in < bool > InA;
	sc_out< bool > Dout;

	void proc(void);

	SC_CTOR( Inverter )
	{
		SC_METHOD( Inv0_Proc );
		sensitive << InA;
	}
};

SC_MODULE( And_2x1 )
{
	sc_in<bool> InA;
	sc_in<bool> InB;
	sc_out<bool> Dout;

	void proc(void);

	SC_CTOR( And_2x1 )
	{
		SC_METHOD( proc );
		sensitive << InA << InB;
	}
};

#endif // __LOGIC_GATE_H
