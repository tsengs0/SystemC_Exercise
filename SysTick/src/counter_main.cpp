#include "../inc/counter.h"

#define SIMULATION_FINISH 5

// Simulating 26-bit count is too long
//#define RELOAD_VALUE 0x3FFFFFF
#define RELOAD_VALUE 0xFF

using std::cout;
using std::cin;
using std::endl;

int sc_main(int argc, char *argv[]) {
//========================================================================================//
	// Clock source
	//sc_clock xtal_clk("external_clock", 20, SC_NS, 0.5); // 50MHz clock with 50% duty cycle	
	sc_signal<bool> xtal_clk;

	// Output port
	sc_signal<bool> zero;
	sc_signal<bool> preset_flag;
	
	// Input port
	sc_signal<bool> counter_rstn;
	sc_signal< sc_uint<26> > reload_val;
	reload_val.write((sc_uint<26>) RELOAD_VALUE);
	
	// Port mapping
	Counter_26 *counter;
	counter = new Counter_26("counter");
	counter -> zero(zero);
	counter -> preset_flag(preset_flag);
	counter -> clk(xtal_clk);
	counter -> counter_rstn(counter_rstn);
	counter -> reload_val(reload_val);

	// Parameter for simulation
	short counter_cnt;
	counter_cnt = 0;
//========================================================================================//
	// Runing the simulation till sc_stop is invoked
	sc_start(); // Runing the simulation till sc_stop is invoked
	cout << "Run" << endl;

	// Creating .vcd file for visualisation in waveform
	sc_trace_file *waveform = sc_create_vcd_trace_file("Counter26_sim");

	// Dumping the desired signals
	sc_trace(waveform, xtal_clk, "xtal_clk");
	sc_trace(waveform, zero, "zero");
	sc_trace(waveform, preset_flag, "preset_flag");
	sc_trace(waveform, counter_rstn, "counter_rstn");
	sc_trace(waveform, reload_val, "reload_val");

	xtal_clk.write(false);
	counter_rstn.write(false); 
	sc_start(20, SC_NS); //next_trigger(20, SC_NS);
	counter_rstn.write(true); 
	while(counter_cnt < (short) SIMULATION_FINISH) {
		xtal_clk.write(false); sc_start(10, SC_NS);
		xtal_clk.write(true); sc_start(10, SC_NS);
		if(zero.read() == true) {
			cout << "counter_cnt: " << counter_cnt << endl;
			counter_rstn.write(false); 
			sc_start(20, SC_NS); //next_trigger(20, SC_NS);
			counter_rstn.write(true);
			counter_cnt++;
		}
		else {
		}
	}

	sc_close_vcd_trace_file(waveform);	
	sc_stop();
	return 0;
}
