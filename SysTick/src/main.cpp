#include "../inc/reg_format.h"
#include "../inc/Multiplexer.h"
#include "../inc/timer_reg.h"

#define SIMULATION_FINISH 100

void sys_init(void);

int sc_main(int argc, char *argv[]) {
//========================================================================================//
// Clock source
	sc_clock external_clk("external_clock", 20, SC_NS, 0.5); // 50MHz clock with 50% duty cycle
	sc_clock proc_clk("processor_clock", 10, SC_NS, 0.5); // 100MHz clodk with 50% duty cycle
//========================================================================================//
// The selection either extenal clock or processor clock	
	sc_signal< sc_uint<2> > Data;
	sc_signal< sc_uint<1> > ClkSrc_sel;
	sc_signal<bool> ClkSrc;
	
	mux_2x1 *clk_mux;
	clk_mux = new mux_2x1("clk_mux");
	clk_mux -> Data0(external_clk);
	clk_mux -> Data1(proc_clk);
	clk_mux -> SEL(ClkSrc_sel);
	clk_mux -> Dout(ClkSrc);	
//========================================================================================//

	// Initialisation of system
	sys_init();

	sc_start(1, SC_NS);  // Runing the simulation till sc_stop is invoked
	cout << "Run" << endl;

	// Creating .vcd file for visualisation in waveform
	sc_trace_file *waveform = sc_create_vcd_trace_file("SysTick");

	// Dumping the desired signals
	sc_trace(waveform, external_clk, "external_clk");
	sc_trace(waveform, proc_clk, "proc_clk");
	sc_trace(waveform, ClkSrc_sel, "ClkSrc_sel");
	sc_trace(waveform, ClkSrc, "ClkSrc");

	for(int i = 0; i < (int) SIMULATION_FINISH; i++) {
		ClkSrc_sel.write(0);
		sc_start((double) (SIMULATION_FINISH / 2) * 10, SC_NS);
		
		ClkSrc_sel.write(1);
		sc_start((double) (SIMULATION_FINISH / 2) * 10, SC_NS);
	}

	sc_close_vcd_trace_file(waveform);	
	sc_stop();
	return 0;
}

void sys_init(void) {
	// Configuring and initialising the timer-relative registers
	TimerReg_init();
}
