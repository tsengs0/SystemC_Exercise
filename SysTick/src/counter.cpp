#include "../inc/counter.h"
#include "../inc/timer_reg.h"
void Counter_24::proc(void) {
	if(counter_rstn.read() == false) {
		cout << "@" << sc_time_stamp() << " => Reset Counter-24" << endl;
		val.range(23, 0) = reload_val;
		SysTick_VAL -> Register.range(23, 0) = val.range(23, 0);
		preset_flag.write(true);
		zero.write(false);	
	} 
	else { // rising edge of clock source
		if(val == 0) {
			cout << "@" << sc_time_stamp() << " => Zero triggered by Counter-24" << endl;
			zero.write(true);
		}
		else {
			if(val.range(23, 0) == reload_val.read()) preset_flag.write(false);
			//cout << "@" << sc_time_stamp() << " => Waiting for overflow from Counter-24" << endl;
			val = val - 1;
			SysTick_VAL -> Register.range(23, 0) = val.range(23, 0);
			//cout << sc_time_stamp() << ",  " <<  clk << ",  " << val << endl;
		}
	}
}
