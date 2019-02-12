#ifndef __SYS_TICK_TB_H
#define __SYS_TICK_TB_H
#include "timer_reg.h"

SC_MODULE(SysTick_init)
{
	int interrupt_cnt;
	sc_out<bool> counter_rstn;
	sc_in<bool> preset_flag;
	sc_in<bool> zero_flag;	
	
	void SysTick_Initialise(void) {
		SysTick_CTRL -> Register[CNT_EN_INDEX].write(0); // Stopping the coutner temporarily
		interrupt_cnt++; // For giving the finsih signal of whole simulation
		counter_rstn.write(false); // Control counter to preset count value and clear the zero flag
		while(preset_flag.read() == false); // Wait until counter finishes preseting the count value
		counter_rstn.write(true); // De-assert reset signal	
		
		SysTick_CTRL -> Register[CNT_EN_INDEX].write(1); // Finish initialisation and enable the counter's clock source
	}

	SC_CTOR(SysTick_init)
	{
		interrupt_cnt = 0;
		SysTick_CTRL -> Register[CNT_EN_INDEX].write(0); // Disable  the system tick before all configuration
		counter_rstn.write(false); // For simulation, presetting the value to counter first 
		while(preset_flag.read() == false); // Wait until counter finishes preseting the count value
		counter_rstn.write(true); // De-assert reset signal	
		SysTick_CTRL -> Register[TICK_INT_INDEX].write(1); // Always turning on the function of system tick 
		SysTick_CTRL -> Register[CNT_EN_INDEX].write(1); // Enable  the system tick before all configuration
		
		SC_METHOD(SysTick_Initialise);
		sensitive << zero_flag;		
	}
};
#endif // __SYS_TICK_TB_H
