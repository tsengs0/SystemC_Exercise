#include "../inc/counter_4bit.h"

void counter_4bit::incr_count(void) {
	if(!rstn.read()) {
		count = 0;
	}
	else if(en.read() == 1) {
		count = count + 1;
		cout << "@" << sc_time_stamp() << "::Incremented Counter"
		     << counter_out.read() << endl; 
	}
	else {
		count = count;
	}
	counter_out.write(count);
}
