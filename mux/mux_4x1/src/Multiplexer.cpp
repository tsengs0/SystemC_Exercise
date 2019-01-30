#include <systemc.h>
#include "../inc/Multiplexer.h"


void mux_4x1::MUX_Proc(void)
{

	sc_uint<4> Data_Temp;
	sc_uint<2> SEL_Temp;

	Data_Temp = Data.read();
	SEL_Temp  = SEL.read();

	Dout = Data_Temp[SEL_Temp];

}
