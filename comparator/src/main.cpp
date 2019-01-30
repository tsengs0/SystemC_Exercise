#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <systemc.h>
#include "../inc/Comparator.h"

using namespace std;

int sc_main( int argc, char *argv[] )
{

	short i, j;
	sc_signal< sc_uint<4> > InA;
	sc_signal< sc_uint<4> > InB;
	sc_signal<bool> GT;
	sc_signal<bool> EQ;
	sc_uint<4> DB;
	
	Comparator *comparator;
	comparator = new Comparator("comparator_0");
	comparator -> InA( InA );
	comparator -> InB( InB );
	comparator -> GT( GT );
	comparator -> EQ( EQ );

	sc_trace_file *trace_f;
	trace_f = sc_create_vcd_trace_file( "Comparator" );
	//( ( vcd_trace_file* ) trace_f ) -> sc sc_set_vcd_time_unit( -9 );
	sc_trace( trace_f, InA, "InA" );
	sc_trace( trace_f, InB, "InB" );
	sc_trace( trace_f, GT, "GT" );
	sc_trace( trace_f, EQ, "EQ" );
	sc_initialize();

	cout << "InA | InB | GT | EQ" << endl;
	cout << "------------" << endl;
	DB.range(3,0) = 0x1;
	cout << "DB = " << DB << endl;
	
	for( i = 0; i < 16; i++ ) {
		InB = ( sc_uint<4> ) i;

		for( j = 0; j < 16; j++ ) {
			InA = ( sc_uint<4> ) j;	
			sc_start( 50, SC_NS );
			cout << InA << "  " << InB << "  " << " | "  << GT << "  "  << EQ << endl;
		}
	}

	sc_close_vcd_trace_file( trace_f );

	return 0;





}
