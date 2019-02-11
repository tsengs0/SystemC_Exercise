#include "../inc/counter.h"

void Counter_26::proc(void) {
	if(counter_rstn.read() == false) {
		//cout << "@" << sc_time_stamp() << " => Reset Counter-26" << endl;
		val.range(25, 0) = reload_val;
		zero.write(false);	
		preset_flag.write(true);
	} 
	else { // rising edge of clock source
		if(val == 0) {
			//cout << "@" << sc_time_stamp() << " => Zero triggered by Counter-26" << endl;
			zero.write(true);
		}
		else {
			if(val.range(25, 0) == reload_val.read()) preset_flag.write(false);
			//cout << "@" << sc_time_stamp() << " => Waiting for overflow from Counter-26" << endl;
			val = val - 1;
			//cout << sc_time_stamp() << ",  " <<  clk << ",  " << val << endl;
		}
	}
}
