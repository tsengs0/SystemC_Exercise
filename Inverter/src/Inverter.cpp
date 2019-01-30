#include "../inc/Inverter.h"

void Inverter::Inv0_Proc(void)
{
	Sig0 = ! InA;
}

void Inverter::Inv1_Proc(void)
{
	Sig1 = ! Sig0;
}

void Inverter::Inv2_Proc(void)
{
	Dout = ! Sig1;
}
