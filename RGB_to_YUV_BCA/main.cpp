#include <systemc.h>
#include "class.h"
#include "testbench.h"
#include "rgb_to_yuv.h"

int sc_main( int argc, char *argv[] )
{

	sc_clock clk( "clk", 10, 0.5, 0, false );
	
	sc_signal<bool> rst;
	sc_signal<bool> rgb_ready;
	sc_signal<bool> rgb_valid;
	sc_signal<bool> yuv_ready;
	sc_signal<bool> yuv_valid;

	sc_signal<rgb8_t> offset;
	sc_signal<rgb8_t> rgb;
	sc_signal<yuv8_t> yuv;

	rgb_to_yuv i0( "rgb_to_yuv" );
	testbench t0( "tb0" );

	i0.clk( clk );
	i0.rst( rst );
	i0.offset_in( offset );
	i0.rgb_in( rgb );
	i0.in_ready( rgb_ready );
	i0.in_valid( rgb_valid );
	i0.yuv_out( yuv );
	i0.out_ready( yuv_ready );
	i0.out_valid( yuv_valid );

	t0.clk( clk );
	t0.rst( rst );
	t0.offset_out( offset );
	t0.rgb_out( rgb );
	t0.out_ready( rgb_ready );
	t0.out_valid( rgb_valid );
	t0.yuv_in( yuv );
	t0.in_ready( yuv_ready );
	t0.in_valid( yuv_valid );

	sc_trace_file *fp;
	fp = sc_create_vcd_trace_file( "rgb_to_yuv" );
	sc_trace( fp, clk, "clk" );
	sc_trace( fp, rst, "rst" );
	sc_trace( fp, offset, "offset" );
	sc_trace( fp, rgb_ready, "rgb_ready" );
	sc_trace( fp, rgb_valid, "rgb_valid" );
	sc_trace( fp, rgb, "rgb" );
	sc_trace( fp, yuv_ready, "yuv_ready" );
	sc_trace( fp, yuv_valid, "yuv_valid" );
	sc_trace( fp, yuv, "yuv" );

	sc_start();
	return 0;	


}
