#include "../inc/mutex_bus.h"

void mutex_bus_t::do_bus(int who) {
	cout << "@" << sc_time_stamp() << " => Bus accessed by instance " << who << endl;
}

void mutex_bus_t::do_test1(void) {
	while(1) {
		wait(); // wait for the sensitive list event to occure; it cannot be use by sc_method()
		cout << "@" << sc_time_stamp() << " => Checking mutex instance 0" << endl;
		// Checking if mutex is available
		if(bus.trylock() != -1) {
			cout << "@" << sc_time_stamp() << " => Got mutex for instance 0" << endl;
			cnt++;
			do_bus(0);
			wait(2); // wait for n events to occur, events are the one in sensitive list, i.e., two rising-edge of sys_clk
			
			bus.unlock(); // Unlocking the mutex
		}
		if(cnt >= 3) {
			sc_stop(); // sc_stop triggers end of simulation
		}
	}
}

void mutex_bus_t::do_test2(void) {
	while(1) {
		wait();
		cout << "@" << sc_time_stamp() << " => Checking mutex instance 1" << endl;
		bus.lock(); // Waiting till mutex is available (i.e., unlocked)
		cout << "@" << sc_time_stamp() << " => Got mutex for instance 1" << endl;
		do_bus(1);
		wait(3);
		bus.unlock();
	}
}
