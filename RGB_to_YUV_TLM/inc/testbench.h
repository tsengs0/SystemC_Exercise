#ifndef _TESTBENCH_
#define _TESTBENCH_

#include <systemc.h>
#include "class.h"

#define input_file "input.dat"
#define output_file "output.dat"

SC_MODULE( testbench ) {


	sc_in<bool> clk;
	sc_fifo_out<rgb8_t> offset_out;
	sc_fifo_out<rgb8_t> rgb_out;
	sc_fifo_in<yuv8_t> yuv_in;

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

		SC_THREAD( source );
		sensitive_pos << clk;
		SC_THREAD( sink );
		sensitive_pos << clk;

	}

	~testbench() {

		fclose( fi );
		fclose( fo );

	}


};

#endif
