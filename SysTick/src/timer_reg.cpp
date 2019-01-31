#include "../inc/timer_reg.h"

SReg_32 *SysTick_CTRL;
SReg_32 *SysTick_VAL;
SReg_32 *SysTick_LOAD;

void TimerReg_init(void) {
	SysTick_CTRL = new SReg_32((char*) "SysTick_CTRL\0");
	SysTick_VAL  = new SReg_32((char*) "SysTick_VAL\0", (sc_uint<32>) 0x00000000);
	SysTick_LOAD = new SReg_32((char*) "SysTick_LOAD\0", (sc_uint<32>) 0xFFFFFFFF);
}
