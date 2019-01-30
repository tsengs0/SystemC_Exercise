#include "rgb_to_yuv.h"

void rgb_to_yuv :: thread0()
{

	rgb8_t offset;
	

	initialise();	wait();

	offset = offset_in.read();	wait();


	while( 1 )
	{

		rgb = get();
		rgb = rgb + offset;

		yuv = calc_rgb_to_yuv( rgb );

		put( yuv );  

	} 


}

void rgb_to_yuv :: initialise()
{

	//CYN_PROTOCOL("init");
	//CYN_PROTOOOCOL(), it will maintain the accuracy of the cycle
	in_ready  = 0;
	out_valid = 0;

}

rgb8_t rgb_to_yuv :: get()
{

	//CYN_PROTOCOL("get");
	in_ready = 1;
	do { wait(); }while( !( in_valid == true ) );
	in_ready = 0;
	return rgb_in.read();

}

void rgb_to_yuv :: put( yuv8_t &yuv )
{

	//CYN_PROTOCOL("put");
	do { wait(); }while( !( out_ready == true ) );
	yuv_out.write( yuv );
	out_valid = 1;
	wait();
	out_valid = 0;	

}

yuv8_t rgb_to_yuv :: calc_rgb_to_yuv( rgb8_t rgb ) 
{

	yuv8_t yuv;

	yuv.y = ( rgb.r * 77 + rgb.g * 151 + rgb.b * 29 ) / 256;
	yuv.u = ( rgb.r * ( -43 ) - rgb.g * 85 + rgb.b * 128 ) / 256 + 128;
	yuv.v = ( rgb.r * 128 - rgb.g * 107 - rgb.b * 21 ) / 256 +128;

	cout << "rgb = " << rgb << " yuv = " << yuv << endl;

	return yuv;
	


}
