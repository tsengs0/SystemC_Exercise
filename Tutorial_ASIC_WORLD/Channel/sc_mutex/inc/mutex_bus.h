#ifndef __H_MUTEX_BUS
#define __H_MUTEX_BUS
#include <systemc.h>

SC_MODULE(mutex_bus_t) {
	sc_in<bool> sys_clk;

	sc_mutex bus;
	int cnt;
	
	void do_bus(int who);
	void do_test1(void);
	void do_test2(void);
	
	SC_CTOR(mutex_bus_t) {
		cnt = 0;
		/*
		SC_METHOD(do_test1);
		sensitive << sys_clk.pos();
		*/
		SC_CTHREAD(do_test1, sys_clk.pos());
		
		SC_CTHREAD(do_test2, sys_clk.pos());
	}
};


#endif // __H_MUTEX_BUS
