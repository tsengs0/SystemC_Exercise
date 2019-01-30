#include <systemc.h>

int sc_main(int argc, char *argv[])
{
	// sc_set_time_resol... should be called before sc_time
	//SC_FS, SC_PS, SC_NS, SC_US, SC_MS, SC_SEC
	sc_set_time_resolution(1, SC_PS);

	// Declare the sc_time variables
	sc_time t1(10, SC_NS);
	sc_time t2(5, SC_PS);
	sc_time t3, t4(1, SC_PS), t5(1, SC_PS);

	cout << "Value of t1 " << t1.to_string() << endl;
	cout << "Value of t2 " << t2.to_string() << endl;
	cout << "Value of t3 " << t3.to_string() << endl;
	cout << "Value of t4 " << t4.to_string() << endl;
	cout << "Value of t5 " << t5.to_string() << endl;

	// Start the sim
	sc_start(0, SC_PS); // First time called will init scheduler
	sc_start(1, SC_PS); // Increment simulation by 1 time unit
	//sc_start();  // Run simulation till sc_stop is encountered 
	
	t3 = sc_time_stamp(); // Get the current time
	cout << "Value of t3 " << t3.to_string() << endl;

	// Run for some more time
	sc_start(20, SC_PS);

	t4 = sc_time_stamp();
	cout << "Value of t4 " << t4.to_string() << endl;
	
	// This is how you do arth operation
	t5 = t4 - t3;
	cout << "Value of t5 " << t5.to_string() << endl;

	// This is how we do compare operation
	if(t5 > t2) {
		cout << "t5 > t2" << endl;
	}
	else {
		cout << "t5 < t2" << endl;
	}

	return 1;
}
