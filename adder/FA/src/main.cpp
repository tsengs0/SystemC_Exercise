#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <systemc.h>
#include "../inc/Half_adder.h"
#include "../inc/Full_adder.h"

using namespace std;

int sc_main( int argc, char *argv[] )
{

	int i;
	sc_signal<bool> InA;
	sc_signal<bool> InB;
	sc_signal<bool> Cin;
	sc_signal<bool> Y;
	sc_signal<bool> C;
	Full_Adder *FA1;
	FA1 = new Full_Adder( "FA1" );

	(*FA1) (InA, InB, Cin, Y, C);

	sc_trace_file *trace_f;
	trace_f = sc_create_vcd_trace_file( "full_adder" );
	//( ( vcd_trace_file* ) trace_f ) -> sc sc_set_vcd_time_unit( -9 );
	sc_trace( trace_f, InA, "InA" );
	sc_trace( trace_f, InB, "InB" );
	sc_trace( trace_f, Cin, "Cin" );
	sc_trace( trace_f, Y, "Y" );
	sc_trace( trace_f, C, "C" );
	sc_initialize();

	cout << "InA InB Cin | Y C" << endl;
	cout << "----------------" << endl;

	for( i = 0; i < 20 ; i++ ) {
		InA = ( i % 2         ) ? true : false;
		InB = ( i % 2         ) ? true : false;
		Cin = ( ( i / 2 ) % 2 ) ? true : false;

		sc_start( 50, SC_NS );
		cout << InA << " " << InB << " " << Cin << " | " << Y << C << endl;
	}

	sc_close_vcd_trace_file( trace_f );

	return 0;





}
