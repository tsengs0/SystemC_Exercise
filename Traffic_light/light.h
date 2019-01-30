#include<systemc.h>

SC_MODULE(light)
{
	//port declarations
	sc_signal<bool> on;

	//process delarations
	void method_func();


	//contructor
	SC_CTOR(light)
	{
		SC_METHOD(method_func);

		sensitive << on;

	}	



};
