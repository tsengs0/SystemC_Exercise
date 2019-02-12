#include "../inc/reg_format.h"
#include "../inc/Multiplexer.h"
#include "../inc/timer_reg.h"
#include "../inc/logic_gate.h"
#include "../inc/counter.h"
#include "../inc/register.h"
#include "../inc/sys_tick_tb.h"
#include "../inc/sys_tick.h"

#define SIMULATION_FINISH 5

void sys_init(void);

int sc_main(int argc, char *argv[]) {
//========================================================================================//
// Signals for testbench
	// Output-port probe
	sc_signal<bool> SysTick_Interrupt;
	sc_signal<bool> COUNTFLAG; // To SysTick_CTRL[16]

	// Input-port probe
	sc_signal<bool> ClkSrc_sel; // From SysTick_CTRL[2]
	sc_signal<bool> TICKINT;    // From SysTick_CTRL[1]
	sc_signal<bool> counter_en; // From SysTick_CTRL[0]
	sc_signal< sc_uint<24> > reload_val; // From SysTick_LOAD[23:0];
	sc_signal<bool> counter_rstn;
	sc_signal<bool> preset_flag;
	
//========================================================================================//
// Clock source
	sc_signal<bool> external_clk;
	sc_signal<bool> proc_clk;
	//sc_clock external_clk("external_clock", 20, SC_NS, 0.5); // 50MHz clock with 50% duty cycle
	//sc_clock proc_clk("processor_clock", 10, SC_NS, 0.5); // 100MHz clodk with 50% duty cycle
//========================================================================================//
// Configuration of System Tick (System Timer)
	SysTick *sys_tick;
	sys_tick = new SysTick("sys_tick");
	sys_tick -> SysTick_Interrupt(SysTick_Interrupt);
	sys_tick -> COUNTFLAG(SysTick_CTRL -> Register[COUNTFLAG_INDEX]);
	sys_tick -> external_clk(external_clk);
	sys_tick -> proc_clk(proc_clk);
	sys_tick -> ClkSrc_sel(SysTick_CTRL -> Register[CLK_SRC_SEL_INDEX]);
	sys_tick -> TICKINT(SysTick_CTRL -> Register[TICK_INT_INDEX]);
	sys_tick -> counter_en(SysTick_CTRL -> Register[CNT_EN_INDEX]);
	sys_tick -> reload_val(SysTick_LOAD -> Register.range(23, 0));
	sys_tick -> counter_rstn(counter_rstn);
	sys_tick -> preset_flag(preset_flag);
//========================================================================================//
// Internal control signal
	SysTick_init *sys_tick_tb;
	sys_tick_tb -> counter_rstn(counter_rstn);
	sys_tick_tb -> preset_flag(preset_flag);
	sys_tick_tb -> zero_flag(SysTick_CTRL -> Register[COUNTFLAG_INDEX]);
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
	sc_trace(waveform, SysTick_Interrupt, "SysTick_Interrupt");
	sc_trace(waveform, SysTick_CTRL -> Register[COUNTFLAG_INDEX], "COUNTFLAG");
	sc_trace(waveform, SysTick_CTRL -> Register[CLK_SRC_SEL_INDEX], "ClkSrc_sel");
	sc_trace(waveform, SysTick_CTRL -> Register[TICK_INT_INDEX], "TICKINT");
	sc_trace(waveform, SysTick_CTRL -> Register[CNT_EN_INDEX], "counter_en");
	sc_trace(waveform, SysTick_LOAD -> Register.range(23, 0), "reload_val");
	sc_trace(waveform, counter_rstn, "counter_rstn");
	sc_trace(waveform, preset_flag, "preset_flag");

	while(sys_tick_tb -> interrupt_cnt < SIMULATION_FINISH) {
		external_clk.write(false); proc_clk.write(false); sc_start(10, SC_NS);	
		external_clk.write(true); proc_clk.write(true); sc_start(10, SC_NS);	
	}

	sc_close_vcd_trace_file(waveform);	
	sc_stop();
	return 0;
}

void sys_init(void) {
	// Configuring and initialising the timer-relative registers
	TimerReg_init();
}
