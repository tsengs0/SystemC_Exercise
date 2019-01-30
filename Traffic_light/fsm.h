#include<systemc.h>

SC_MODULE(fsm)
{
	//port declarations
	sc_out<bool> red_on, yellow_on, green_on;
	sc_in_clk clk;

	//process delarations
	void method_func();


	//contructor
	SC_CTOR(fsm)
	{
		SC_CTHREAD(method_func, clk.pos() );



	}	



};
