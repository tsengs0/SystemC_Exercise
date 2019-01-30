£ifndef __TRISTATE_BUS_H
£define __TRISTATE_BUS_H
#include <systemc.h>
 
/*
 -----------
|           |   A = 1
|  Module A | ________
| 	    |         |
 -----------	      |
		     \ /
		       ---------> Y = 1
		     / \
 -----------          |
|           |  B = z  |
|  Module A | ________|
| 	    |         
 -----------	      
*/

SC_MOUDLE(tristate_bus)
{
	// Resolved logic vectors
	sc_in_rv<1> in;
	sc_out_rv<1> out;
	sc_inout_rv<4> inout;

};

£endif // __TRISTATE_BUS_H
