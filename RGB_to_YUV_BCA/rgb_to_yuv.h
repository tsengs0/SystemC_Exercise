#ifndef _RGB_TO_YUV_
#define _RGB_TO_YUV_

#include "systemc.h"
#include "class.h"

SC_MODULE( rgb_to_yuv ) {


	sc_in<bool>   clk;
	sc_in<bool>   rst;

	sc_in<rgb8_t> offset_in;
	sc_in<rgb8_t> rgb_in;
	sc_out<bool>  in_ready;
	sc_in<bool>   in_valid;

	sc_out<yuv8_t> yuv_out;
	sc_in<bool>    out_ready;
	sc_out<bool>   out_valid;

	void initialise();
	rgb8_t get();
	void put( yuv8_t &yuv );
	yuv8_t calc_rgb_to_yuv( rgb8_t rgb );

	void thread0();

	rgb8_t rgb;
	yuv8_t yuv;

	SC_CTOR( rgb_to_yuv ) {

		SC_CTHREAD( thread0, clk.pos() );
		//watching( rst.delayed() == 0 );
		
	}	


};

#endif
