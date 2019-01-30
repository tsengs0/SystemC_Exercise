#include "counter.h"

int sc_main( int argc, char* argv[] )
{
	//signal delaration
	sc_clock clk( "clk", 1, SC_NS, 0.5 );
	sc_signal<int> val;

	//module decaration
	counter counter0( "counter0" );

	//signal connection
	counter0.clk(clk);
	counter0.val(val);

	//run simulation
	sc_start(100, SC_NS);

	return 0;



}
