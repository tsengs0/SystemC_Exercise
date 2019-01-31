#ifndef __TIMER_REG_H
#define __TIMER_REG_H
#include "../inc/reg_format.h"

extern SReg_32 *SysTick_CTRL;
extern SReg_32 *SysTick_VAL;
extern SReg_32 *SysTick_LOAD;

void TimerReg_init(void);

#endif // __TIMER_REG_H
