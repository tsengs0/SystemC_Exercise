#include <systemc.h>

SC_MODULE(counter_4bit)
{
	sc_in_clk sys_clk;
	sc_in<bool> rstn;
	sc_in<bool> en;
	sc_out< sc_uint<4> > counter_out;

	/*----------Local Variables---------------------*/
	sc_uint<4> count;
	
	/*------Functionalities-------------------------*/
	void incr_count(void);
	
	SC_CTOR(counter_4bit) {
		cout << "Constructor of 4-bit Counter" << endl << endl;
		SC_METHOD(incr_count);
		sensitive << rstn
			  << sys_clk.pos();
	};
};
