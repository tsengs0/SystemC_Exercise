#include <systemc.h>
#include <math.h>

#define WIDTH 4

SC_MODULE(adder) {
	sc_in< sc_uint<WIDTH> > a, b;
	sc_out< sc_uint<WIDTH> > sum;

	void do_add(void) {
		sum.write(a.read() + b.read());
	}


	SC_CTOR(adder) {
		SC_METHOD(do_add);
		sensitive << a << b;	
	};

};


int sc_main(int argc, char **argv)
{
	int i, tb_cnt;
	sc_signal< sc_uint<WIDTH> > a, b, sum;
	sc_uint<8> cnt;

	// Connecting the DUT
	adder u0("ADDER");
	u0.a     (a);
	u0.b     (b);
	u0.sum   (sum);

	a = 0x0; b = 0x0;
	cnt = 0x00;

	sc_start(1, SC_NS);

	// Opening .VCD file
	sc_trace_file *waveform = sc_create_vcd_trace_file("adder");
	
	//Dumping the desired signals
	sc_trace(waveform, a, "a");
	sc_trace(waveform, b, "b");
	sc_trace(waveform, sum, "sum");
	
	tb_cnt = pow(2, (float) WIDTH*2);
	for(int i = 0; i < tb_cnt; i++) {
		cnt += 0x01;
		a = cnt >> WIDTH;
		b = cnt & 0x0F;
		sc_start(1, SC_NS);
	}	
	
	sc_close_vcd_trace_file(waveform);
	
	return 0;
}
