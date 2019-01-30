#include <systemc.h>

SC_MODULE(logic_bus)
{
	// sc_lv is for multi "logic" vector declaration
	sc_lv<8> data_bus (sc_logic ('z')); // All bits are Z
	sc_lv<16> addr_bus (sc_logic ('x'));
	sc_logic parity;
	
	
	/*------Functionalities-------------------------*/
	SC_CTOR(logic_bus) {
		cout << "Constructor of logic_bus" << endl << endl;
	};
};
