#ifndef _RGB_TO_YUV_
#define _RGB_TO_YUV_

#include "systemc.h"
#include "class.h"

SC_MODULE( rgb_to_yuv ) {


	sc_in<bool> clock;
	sc_fifo_in<rgb8_t> offset_in;
	sc_fifo_in<rgb8_t> rgb_in;
	sc_fifo_out<yuv8_t> yuv_out;

	void thread0();
	yuv8_t calc_rgb_to_yuv( rgb8_t &rgb );

	rgb8_t rgb;
	yuv8_t yuv;

	SC_CTOR( rgb_to_yuv ) {

		SC_THREAD( thread0 );
		sensitive_pos << clock;

	}	


};

#endif
