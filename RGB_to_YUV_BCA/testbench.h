#ifndef _TESTBENCH_
#define _TESTBENCH_

#include <systemc.h>
#include "class.h"

#define input_file "input.dat"
#define output_file "output.dat"

SC_MODULE( testbench ) {


	sc_in<bool>  clk;
	sc_out<bool> rst;

	sc_out<rgb8_t> offset_out;
	sc_out<rgb8_t> rgb_out;
	sc_in<bool>   out_ready;
	sc_out<bool>  out_valid;

	sc_in<yuv8_t> yuv_in;
	sc_out<bool>  in_ready;
	sc_in<bool>   in_valid;

	FILE *fi;
	FILE *fo;

	void source();
	void sink();

	SC_CTOR( testbench ) {

		if( ( fi = fopen( input_file, "r" ) ) == NULL  ) {
			
			fprintf( stderr, "Can't open file : %s\n", input_file );
			sc_stop();

		}

		if( ( fo = fopen( output_file, "w" ) ) == NULL  ) {
			
			fprintf( stderr, "Can't open file : %s\n", output_file );
			sc_stop();

		}

		SC_CTHREAD( source, clk.pos() );
		SC_CTHREAD( sink  , clk.pos() );


	}

	~testbench() {

		fclose( fi );
		fclose( fo );

	}


};

#endif
