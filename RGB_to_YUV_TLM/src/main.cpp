#include <systemc.h>
#include "/home/tsengs0/C_program/SystemC/RGB_to_YUV/inc/class.h"
#include "/home/tsengs0/C_program/SystemC/RGB_to_YUV/inc/testbench.h"
#include "/home/tsengs0/C_program/SystemC/RGB_to_YUV/inc/rgb_to_yuv.h"

int sc_main( int argc, char *argv[] )
{

	sc_clock clock( "clock", 10, 0.5, 0, false );
	
	sc_fifo<rgb8_t> offset;
	sc_fifo<rgb8_t> rgb;
	sc_fifo<yuv8_t> yuv;

	rgb_to_yuv i0( "rgb_to_yuv" );
	testbench t0( "tb0" );

	i0.clock( clock );
	i0.offset_in( offset );
	i0.rgb_in( rgb );
	i0.yuv_out( yuv );

	t0.clk( clock );
	t0.offset_out( offset );
	t0.rgb_out( rgb );
	t0.yuv_in( yuv );

	sc_start();
	return 0;	


}
