#ifndef __INVERTER__
#define __INVERTER__

#include <systemc.h>

SC_MODULE( Inverter )
{
	sc_in < bool > InA;
	sc_out< bool > Dout;

	sc_signal< bool > Sig0, Sig1;

	void Inv0_Proc(void);
	void Inv1_Proc(void);
	void Inv2_Proc(void);

	SC_CTOR( Inverter )
	{
		SC_METHOD( Inv0_Proc );
		sensitive << InA;

		SC_METHOD( Inv1_Proc );
		sensitive << Sig0;

		SC_METHOD( Inv2_Proc );
		sensitive << Sig1;
	}
};

#endif
