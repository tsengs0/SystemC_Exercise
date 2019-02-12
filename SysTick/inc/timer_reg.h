#ifndef __TIMER_REG_H
#define __TIMER_REG_H
#include "../inc/reg_format.h"

extern SReg_32 *SysTick_CTRL;
extern SReg_32 *SysTick_VAL;
extern SReg_32 *SysTick_LOAD;

#define SYSTICK_RELOAD 0xFF

enum {
	COUNTFLAG_INDEX   = 16, // SysTick_CTRL[16]
	CLK_SRC_SEL_INDEX = 2,  // SysTick_CTRL[2]
	TICK_INT_INDEX    = 1,  // SysTick_CTRL[1]
	CNT_EN_INDEX      = 0   // SysTick_CTRL[0]
};

void TimerReg_init(void);

#endif // __TIMER_REG_H
