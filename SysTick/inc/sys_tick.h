#ifndef __SYS_TICK_H
#define __SYS_TICK_H
#include  "../inc/logic_gate.h"

SC_MODULE( SysTick )
{
	sc_out<bool> SysTick_Interrupt;
	
	// From AHB clock source 
	sc_in<bool> external_clk; // => AHB_CLK / 8 
	sc_in<bool> proc_clk;
//========================================================================================//
// The selection either extenal clock or processor clock	
	mux_2x1 *clk_mux; // Mutiplexer for selecting the clock source 
	sc_signal<bool> ClkSrc; // Clock source to 24-bit down counter of SysTick 
//========================================================================================//
// The control signals from specific registers

	// SysTick controls and status register (SysTick_CTRL)
	sc_out<bool> COUNTFLAG; // To SysTick_CTRL[16]
	sc_in<bool> ClkSrc_sel; // From SysTick_CTRL[2]
	sc_in<bool> TICKINT;    // From SysTick_CTRL[1]
	sc_in<bool> counter_en; // From SysTick_CTRL[0]

	sc_in< uint<26> > reload_val; // From SysTick_LOAD[25:0];
//========================================================================================//
// The 24-bit down counter
	sc_in<bool> SysTick_rst;
	And_2x1 *clk_en;
	And_2x1 *interrupt_en;
	Counter_26 *counter;
	sc_in< uint<26> > reload_val;
//========================================================================================//
	SC_CTOR( SysTick )
	{
		counter = new Counter_26("counter");
		counter -> zero(COUNTFLAG);
		counter -> clk(ClkSrc);
		counter -> reload_val(reload_val);
		counter -> counter_rst(SysTick_rst);

		clk_mux = new mux_2x1("clk_mux");
		clk_mux -> Data0(external_clk);
		clk_mux -> Data1(proc_clk);
		clk_mux -> SEL(ClkSrc_sel);
		clk_mux -> Dout(ClkSrc);	

		clk_en = new And_2x1("clk_en");
		clk_en -> InA(clk_mux -> Dout);
		clk_en -> InB(counter_en);
		//clk_en -> Dout(counter -> clk);

		interrupt_en = new And_2x1("interrupt_en");
		interrupt_en -> InA(TICKINT);
		interrupt_en -> InB(COUNTFLAG);
		interrupt_en -> Dout(SysTick_Interrupt);

		SC_METHOD( MUX_Proc );
		sensitive << Data << SEL;

	}
};

#endif // __SYS_TICK_H
