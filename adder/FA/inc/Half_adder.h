#ifndef __HA_ADDER__
#define __HA_ADDER__


#include <systemc.h> 



SC_MODULE( Half_Adder )
{

	sc_in<bool> InA;
	sc_in<bool> InB;
	sc_out<bool> Y;
	sc_out<bool> C;

	void Half_Adder_Proc(void);

	SC_CTOR( Half_Adder )
	{

		SC_METHOD( Half_Adder_Proc );
		sensitive << InA << InB;


	}




};




#endif
