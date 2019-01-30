#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <systemc.h>
#include "../inc/Parity.h"

using namespace std;

int sc_main( int argc, char *argv[] )
{

	unsigned char i;
	sc_signal< sc_uint<8> > Data;
	sc_signal<bool> CHK;
	
	Parity *parity_check;
	parity_check = new Parity("Parity_0");
	( *parity_check ) ( Data, CHK );

	sc_trace_file *trace_f;
	trace_f = sc_create_vcd_trace_file( "1rity" );
	//( ( vcd_trace_file* ) trace_f ) -> sc sc_set_vcd_time_unit( -9 );
	sc_trace( trace_f, Data, "Data" );
	sc_trace( trace_f, CHK, "CHK" );
	sc_initialize();

	cout << "DATA | CHK" << endl;
	cout << "--------" << endl;
	
	
	for( i = 0; i < 8; i++ ) {
		Data = ( sc_uint<8> ) i;	
		sc_start( 50, SC_NS );
		cout << Data << "      " << " | "  << CHK << endl;
	}

	sc_close_vcd_trace_file( trace_f );

	return 0;





}
