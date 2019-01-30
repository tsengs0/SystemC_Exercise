#include "../inc/mutex_bus.h"

int sc_main(int argc, char *argv[]) {
	sc_clock sys_clk("my_clock", 20, SC_NS, 0.5); // 50MHz clock with 50% duty cycle
	
	mutex_bus_t MutexBus("Wait");
	MutexBus.sys_clk(sys_clk);

// Old syntax in previous version of SystemC
//	sc_start(0); // First time called will initialise scheduler
	sc_start();  // Runing the simulation till sc_stop is invoked
	return 0;
}
