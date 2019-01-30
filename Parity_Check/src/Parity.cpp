#include <systemc.h>
#include "../inc/Parity.h"

void Parity::Parity_Proc(void)
{
	bool Check_Sum;

	Check_Sum = InA.read().xor_reduce();

	CHK.write( Check_Sum );



}
