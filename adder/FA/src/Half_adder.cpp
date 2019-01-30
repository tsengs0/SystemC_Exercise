#include "../inc/Half_adder.h"

void Half_Adder::Half_Adder_Proc(void)
{

	Y = InA ^ InB;
	C = InA & InB;

}
