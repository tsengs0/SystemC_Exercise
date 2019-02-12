#ifndef __COUNTER_H
#define __COUNTER_H
#include<systemc.h>

SC_MODULE(Counter_24)
{
	sc_out<bool> zero;
	sc_out<bool> preset_flag;

	sc_in_clk clk;
	sc_in<bool> counter_rstn;
	sc_in< sc_uint<24> > reload_val;
	
	sc_uint<24> val;

	void proc();

	SC_CTOR(Counter_24) 
	{
		SC_METHOD(proc);
		sensitive << clk.pos()
		          << counter_rstn;
		
		val.range(23, 0) = (sc_uint<24>) 0;
		preset_flag.write(false);
		// The port should not be accessed inside constructor
		//val.range(25, 0) = reload_val;
	}	
};

#endif // __COUNTER_H
