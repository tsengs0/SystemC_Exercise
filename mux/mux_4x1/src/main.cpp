#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <systemc.h>
#include "../inc/Multiplexer.h"

using namespace std;

int sc_main( int argc, char *argv[] )
{

	unsigned char i;
	sc_signal< sc_uint<4> > Data;
	sc_signal< sc_uint<2> > SEL;
	sc_signal<bool> Dout;
	
	mux_4x1 *mux_0;
	mux_0 = new mux_4x1("mux_0");
	( *mux_0 ) ( Data, SEL, Dout );
	

	sc_trace_file *trace_f;
	trace_f = sc_create_vcd_trace_file( "mux_4x1" );
	//( ( vcd_trace_file* ) trace_f ) -> sc sc_set_vcd_time_unit( -9 );
	sc_trace( trace_f, Data, "Data" );
	sc_trace( trace_f, SEL, "SEL" );
	sc_trace( trace_f, Dout, "Dout" );
	sc_initialize();

	cout << "DATA | SEL | Dout" << endl;
	cout << "--------" << endl;
	
	Data = 0xA;

	for( i = 0; i < 4; i++ ) {
		
		SEL = i;
		sc_start( 50, SC_NS );
		cout << Data << "      " << SEL << " | " << Dout << endl;
	}

	sc_close_vcd_trace_file( trace_f );

	return 0;





}
