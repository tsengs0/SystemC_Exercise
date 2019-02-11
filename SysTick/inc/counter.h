#ifndef __COUNTER_H
#define __COUNTER_H
#include<systemc.h>

SC_MODULE(Counter_26)
{
	sc_out<bool> zero;
	sc_out<bool> preset_flag;

	sc_in_clk clk;
	sc_in<bool> counter_rstn;
	sc_in< sc_uint<26> > reload_val;
	
	sc_uint<26> val;

	void proc();

	SC_CTOR(Counter_26) 
	{
		SC_METHOD(proc);
		sensitive << clk.pos() << counter_rstn;

		// The port should not be accessed inside constructor
		//val.range(25, 0) = reload_val;
	}	
};

#endif // __COUNTER_H
