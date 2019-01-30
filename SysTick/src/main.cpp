#include "../inc/reg_format.h"
#include "../inc/Multiplexer.h"

int sc_main(int argc, char *argv[]) {
	sc_clock external_clk("external_clock", 20, SC_NS, 0.5); // 50MHz clock with 50% duty cycle
	sc_clock proc_clk("processor_clock", 10, SC_NS, 0.5); // 100MHz clodk with 50% duty cycle
	SReg_32 SysTick_CTRL((char*) "SysTick_CTRL\0");
	SReg_32 SysTick_VAL((char*) "SysTick_VAL\0", (sc_uint<32>) 0x00000000);
	SReg_32 SysTick_LOAD((char*) "SysTick_LOAD\0", (sc_uint<32>) 0xFFFFFFFF);

//========================================================================================//
// The selection either extenal clock or processor clock	
	sc_signal< sc_uint<2> > Data;
	sc_signal< sc_uint<1> > SEL;
	sc_signal<bool> Dout;
	
	mux_2x1 *clk_mux;
	clk_mux = new mux_2x1("clk_mux");
	clk_mux -> Data0(external_clk);
	clk_mux -> Data1(proc_clk);
	clk_mux -> SEL(SEL);
	clk_mux -> Dout(Dout);
//========================================================================================//

	
//	sc_start();  // Runing the simulation till sc_stop is invoked
//	sc_stop();
	return 0;
}
