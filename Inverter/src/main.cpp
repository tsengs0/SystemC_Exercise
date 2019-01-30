#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <systemc.h>
#include "../inc/Inverter.h"

using namespace std;

int sc_main( int argc, char *argv[] )
{

	char i;
	sc_signal< bool > InA, Dout;
	
	Inverter *inverter;
	inverter = new Inverter("inv_0");
	inverter -> InA( InA );
	inverter -> Dout( Dout );

	sc_trace_file *trace_f;
	trace_f = sc_create_vcd_trace_file( "Inverter" );
	//( ( vcd_trace_file* ) trace_f ) -> sc sc_set_vcd_time_unit( -9 );
	sc_trace( trace_f, InA, "InA" );
	sc_trace( trace_f, Dout, "Dout" );
	sc_initialize();

	cout << "InA | Dout" << endl;
	cout << "------------" << endl;
	
	for( i = 0; i < 50; i++ ) {
		
		InA = ( i <= 24 ) ? true : false;	
		sc_start( 50, SC_NS );
		cout << InA << " | " <<  Dout << endl;
		
	}

	sc_close_vcd_trace_file( trace_f );

	return 0;





}
