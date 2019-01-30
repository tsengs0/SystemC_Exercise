#include <systemc.h>

SC_MODULE(hello_world)
{
	SC_CTOR(hello_world) {
		cout << "Constructor of Hello World" << endl;
	};

	void say_hello();
};


