#ifndef _CLASS_H_
#define _CLASS_H_

#include "systemc.h"

typedef  std::string sc_string;

class rgb8_t
{
	
  public:
	sc_uint<8> r;
	sc_uint<8> g;
	sc_uint<8> b;

	rgb8_t() {}
	
	rgb8_t( const int cr, const int cg, const int cb ) :
		r( cr ), g( cg ), b( cb ) {}

	rgb8_t read() {

		rgb8_t obj;
		obj.r = r; obj.g = g; obj.b = b;
		return obj;

	}

	void write( const rgb8_t &obj ) {

		r  = obj.r; g = obj.g; b = obj.b;

	}

	void write( const int &a1, const int &a2, const int &a3 ) {
		
		r = a1; g = a2; b = a3;

	}

	void operator=( const rgb8_t &obj ) {

		write( obj );

	}

	bool operator==( const rgb8_t &obj ) {

		if( r == obj.r && g == obj.g && b == obj.b )	return ( true );
		else return 	( false );

	}

	friend rgb8_t operator+( rgb8_t &a, rgb8_t &b ) {


		rgb8_t obj;
		
		obj.r = ( ( a.r + b.r ) > 255  ) ? ( sc_uint<8> ) 255 : ( sc_uint<8> ) ( a.r + b.r );
		obj.b = ( ( a.b + b.b ) > 255  ) ? ( sc_uint<8> ) 255 : ( sc_uint<8> ) ( a.b + b.b );
		obj.g = ( ( a.g + b.g ) > 255  ) ? ( sc_uint<8> ) 255 : ( sc_uint<8> ) ( a.g + b.g );
		
		return obj;

	}
};

	//Definition of waveform using sc_trace
	inline void sc_trace( sc_trace_file *tf, const rgb8_t &o, const sc_string &n ) {

		
		sc_trace( tf, o.r, n + "_r" );
		sc_trace( tf, o.g, n + "_g" );
		sc_trace( tf, o.b, n + "_b" );

	} 

	//Definition of output using ostream
	inline ostream& operator << ( ostream &os, const rgb8_t &o ) {

		       os << o.r << "  " << o.g << "  " << o.b;
		       return os;

	}




class yuv8_t
{

	public:
		sc_uint<8> y;
		sc_uint<8> u;
		sc_uint<8> v;

	yuv8_t() {}
	
	yuv8_t( const int cy, const int cu, const int cv ) :
		y( cy ), u( cu ), v( cv ) {}

	yuv8_t read() {
	
		yuv8_t obj;
		obj.y = y; obj.u = u; obj.v = v;
		
		return obj;
	}

	void write( const yuv8_t &obj ) {

		y = obj.y; u = obj.u; v = obj.v;

	}

	void operator=( const yuv8_t &obj ) {
	
		write( obj );

	}

	bool operator==( const yuv8_t &obj ) {

		if( y == obj.y && u == obj.u && v == obj.v )	return ( true );
		else return ( false );

	}

	friend yuv8_t operator + ( yuv8_t &a, yuv8_t &b ) {

		yuv8_t obj;
		
		obj.y = ( ( a.y + b.y ) > 255  ) ? ( sc_uint<8> ) 255 : ( sc_uint<8> ) ( a.y + b.y );
		obj.u = ( ( a.u + b.u ) > 255  ) ? ( sc_uint<8> ) 255 : ( sc_uint<8> ) ( a.u + b.u );
		obj.v = ( ( a.v + b.v ) > 255  ) ? ( sc_uint<8> ) 255 : ( sc_uint<8> ) ( a.v + b.v );

		return obj;

	}



};

	inline void sc_trace( sc_trace_file *tf, const yuv8_t &o, const sc_string &n ) {

		sc_trace( tf, o.y, n + "_y" );
		sc_trace( tf, o.u, n + "_u" );
		sc_trace( tf, o.v, n + "_v" );


	}

	inline ostream& operator << ( ostream &os, const yuv8_t &o ) {

		os << o.y << "  " << o.u << "  " << o.v;
		return os;

	}



#endif


