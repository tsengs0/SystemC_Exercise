#ifndef __COUNTER_H
#define __COUNTER_H
#include<systemc.h>

SC_MODULE(Counter_26)
{
	sc_out<bool> zero;

	sc_in_clk clk;
	sc_in<bool> counter_rst;
	sc_in< uint<26> > reload_val;
	
	sc_signal< uint<26> > val;

	void proc();

	SC_CTOR(Counter_26) 
	{
		SC_METHOD(proc);
		sensitive << clk.pos() << counter_rst;

		val.range(25, 0) = reload_val(25, 0);
	}	
};

#endif // __COUNTER_H
