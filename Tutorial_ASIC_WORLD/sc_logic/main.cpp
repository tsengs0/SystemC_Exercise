#include <systemc.h>

int sc_main(int argc, char **argv)
{
	// sc_bv is for multi "bit" vector declaration
	sc_bv<8> data_bus;
	sc_bv<16> addr_bus;
	sc_bit parity;
	
	// sc_lv is for multi "logic" vector declaration
	sc_lv<8> data_bus_l (sc_logic ('z')); // All bits are Z
	sc_lv<16> addr_bus_l (sc_logic ('x'));
	sc_logic parity_l;

	// Example: Arbitrary Width Bit Type
	data_bus = "00001011";
	cout << "Value of data_bus: " << data_bus << endl;

	// Use range operator
	addr_bus.range(7, 0) = data_bus.range(7, 0);
	cout << "Value of addr_bus: " << addr_bus << endl;

	// Assign reverse to addr bus using range operator
	addr_bus.range(0, 7) = data_bus;
	cout << "Value of addr_bus: " << addr_bus << endl;

	// Use bit select to set the value
	addr_bus[10] = "1";
	cout << "Value of addr_bus: " << addr_bus << endl;

	// Use reduction operator
	parity = data_bus.xor_reduce();
	cout << "Value of parity: " << parity << endl;

	// Example: Arbitrary Width Logic Type
	// Print default value of data_bus
	cout << "Value of data_bus: " << data_bus_l << endl;

	// Assign value to sc_bv
	data_bus_l = "00001011";
	cout << "Value of data_bus: " << data_bus_l << endl;
	
	// Use range operator
	addr_bus_l.range(7, 0) = data_bus_l.range(7, 0);
	cout << "Value of addr_bus: " << addr_bus_l << endl;	

	// Use  bit select to set the value
	addr_bus_l[10] = 'z';
	cout << "Value of addr_bus: " << addr_bus_l << endl;	

	// Use reduction XOR operator
	parity_l = data_bus_l.xor_reduce();
	cout << "Value of parity: " << parity_l << endl;
	
	// Use reduction AND operator
	parity_l = data_bus_l.and_reduce();
	cout << "Value of parity: " << parity_l << endl;
	
	// Use reduction OR operator
	parity_l = data_bus_l.or_reduce();
	cout << "Value of parity: " << parity_l << endl;

	return 0;
}



