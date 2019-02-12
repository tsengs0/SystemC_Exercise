#include "../inc/timer_reg.h"


void TimerReg_init(void) {
	SysTick_CTRL = new SReg_32((char*) "SysTick_CTRL\0");
	SysTick_VAL  = new SReg_32((char*) "SysTick_VAL\0", (sc_uint<32>) 0x00000000);
	SysTick_LOAD = new SReg_32((char*) "SysTick_LOAD\0", (sc_uint<32>) SYSTICK_RELOAD);
}
