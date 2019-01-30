#include "/home/tsengs0/C_program/SystemC/RGB_to_YUV/inc/testbench.h"

#define NUM 20

void testbench :: source()
{

	int data_r, data_g, data_b;
	int i;
	rgb8_t rgb;

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
		
		rgb_out.write( rgb );
		wait();   

	}


}

void testbench :: sink()
{

	yuv8_t yuv;
	int i;
	
	fprintf( fo, "	Y	U	V\n" );
	
	for( i = 0; i < NUM; i++ ) {
	
		yuv = yuv_in.read();
		fprintf( fo , "%3d %3d %3d\n", (int) yuv.y, (int) yuv.u, (int) yuv.v );

		wait();

	}


}


