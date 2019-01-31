#include "../inc/logic_gate.h"


void Inverter::proc(void) {
	Dout = !InA;
}

void And_2x1::proc(void) {
	Dout = InA & InB;
}
