#include "counter.h"

void Counter_26::proc(void) {

	if(counter_rst.read() == true) {
		val.range(25, 0) = reload_val.range(25, 0);
		zero.write(false);	
	} 
	else { // rising edge of clock source
		if(val == 0) {
			zero.write(true);
		}
		else {
			val -= 1;
			cout << sc_time_stamp() << ",  " <<  clk << ",  " << val << endl;
		}
	}
}
