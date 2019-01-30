#include<systemc.h>

SC_MODULE(counter)
{
	
	//port-declarstions
	sc_in_clk clk;
	sc_out<int> val;

	//process declarations
	void process_func();

	//module constructor
	SC_CTOR(counter) 
	{
		SC_CTHREAD(process_func, clk.pos());
	}	



};
