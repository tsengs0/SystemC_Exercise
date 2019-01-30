#include "testbench.h"

#define NUM 20

void testbench :: source()
{

	int data_r, data_g, data_b;
	int i;
	rgb8_t rgb;

	rst = 0;
	out_valid = 0;
	wait(2);

	rst = 1;
	fscanf( fi, "%d", &data_r );
	fscanf( fi, "%d", &data_g );
	fscanf( fi, "%d", &data_b );

	rgb.write( data_r, data_g, data_b );

	offset_out.write( rgb );
	wait();

	for( i = 0; i < NUM; i++ ) {
	
		fscanf( fi , "%d", &data_r );
		fscanf( fi , "%d", &data_g );
		fscanf( fi , "%d", &data_b );

		rgb.write( data_r, data_g, data_b );
		do { wait(); }while( !( out_ready == true ) );
		rgb_out.write( rgb );
		out_valid.write(1);
		wait();   
		out_valid.write(0);

	}


}

void testbench :: sink()
{

	yuv8_t yuv;
	int i;
	
	fprintf( fo, "	Y	U	V\n" );
	
	for( i = 0; i < NUM; i++ ) {
		
		in_ready = 1;
		do { wait(); }while( !( in_valid == true ) );
	
		yuv = yuv_in.read();
		fprintf( fo , "%3d %3d %3d\n", (int) yuv.y, (int) yuv.u, (int) yuv.v );
		
	        in_ready = 0;

	}
	sc_stop();

}


