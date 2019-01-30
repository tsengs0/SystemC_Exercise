#include "../inc/counter_4bit.h"

int sc_main(int argc, char **argv)
{
	int i;
	sc_signal<bool> sys_clk;
	sc_signal<bool> rstn;
	sc_signal<bool> en;
	sc_signal< sc_uint<4> > counter_out;

	// Connecting the DUT
	counter_4bit u0("COUNTER");
	u0.sys_clk     (sys_clk    );
	u0.rstn        (rstn       );
	u0.en          (en         );
	u0.counter_out (counter_out);	  	
	
	sc_start(1, SC_NS);

	// Opening .VCD file
	sc_trace_file *waveform = sc_create_vcd_trace_file("counter");

	//Dumping the desired signals
	sc_trace(waveform, sys_clk, "sys_clk");
	sc_trace(waveform, rstn, "rstn");
	sc_trace(waveform, en, "en");
	sc_trace(waveform, counter_out, "counter_out");

	// Initialising all variables
	rstn = 1; 
	en = 0;
	for(i = 0; i < 5; i++) {
		sys_clk = 0;
		sc_start(1, SC_NS);

		sys_clk = 1;
		sc_start(1, SC_NS);
	}

	rstn = 0; // Asserting the reset
	cout << "@" << sc_time_stamp() << "Asserting reset" << endl;
	for(i = 0; i < 10; i++) {
		sys_clk = 0;
		sc_start(1, SC_NS);

		sys_clk = 1;
		sc_start(1, SC_NS);
	}

	rstn = 1; // De-Asserting the reset
	cout << "@" << sc_time_stamp() << "De-Asserting reset" << endl;
	for(i = 0; i < 5; i++) {
		sys_clk = 0;
		sc_start(1, SC_NS);

		sys_clk = 1;
		sc_start(1, SC_NS);
	}
	
	cout << "@" << sc_time_stamp() << "Asserting Enable" << endl;
	en = 1; // Asserting the enable
	for(i = 0; i < 20; i++) {
		sys_clk = 0;
		sc_start(1, SC_NS);

		sys_clk = 1;
		sc_start(1, SC_NS);
	}
	
	cout << "@" << sc_time_stamp() << "De-Asserting Enable" << endl;
	en = 0; // De-Asserting the enable

	cout << "@" << sc_time_stamp() << "Terminating simulation" << endl;
	sc_close_vcd_trace_file(waveform);
	
	return 0;
}
