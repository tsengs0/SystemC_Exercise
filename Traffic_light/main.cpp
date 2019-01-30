#include "light.h"
#include "fsm.h"

int sc_main(int argc, char* argv[])
{

//	sc_signal<bool> red_on, yellow_on, green_on;
	sc_clock clk( "clk", 1, SC_NS, 0.5 );	

        light red("red"), yellow("yellow"), green( "green" );
	fsm FSM("FSM");	

	FSM.clk(clk);

	FSM.red_on(red.on);
	FSM.yellow_on(yellow.on);
	FSM.green_on(green.on);

//	red.on(FSM.red_on);
//	yellow.on(FSM.yellow_on);
//	green.on(FSM.green_on);


	sc_start(100, SC_NS);
	

	
	

	return 0;
	




}
