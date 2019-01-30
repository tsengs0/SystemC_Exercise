#include "/home/tsengs0/C_program/SystemC/RGB_to_YUV/inc/rgb_to_yuv.h"

void rgb_to_yuv :: thread0()
{

	rgb8_t offset;

	offset = offset_in.read();

	while( 1 )
	{

		rgb = rgb_in.read();
		rgb = rgb + offset;

		yuv = calc_rgb_to_yuv( rgb );

		yuv_out.write( yuv );  

	} 


}

yuv8_t rgb_to_yuv :: calc_rgb_to_yuv( rgb8_t &rgb ) 
{

	yuv8_t yuv;

	yuv.y = ( rgb.r * 77 + rgb.g * 151 + rgb.b * 29 ) / 256;
	yuv.u = ( rgb.r * ( -43 ) - rgb.g * 85 + rgb.b * 128 ) / 256 + 128;
	yuv.v = ( rgb.r * 128 - rgb.g * 107 - rgb.b * 21 ) / 256 +128;

	cout << "rgb = " << rgb << " yuv = " << yuv << endl;

	return yuv;
	


}
