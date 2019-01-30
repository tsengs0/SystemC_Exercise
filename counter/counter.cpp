#include "counter.h"

void counter::process_func()
{
	val = 0;

	while(1)
	{
		wait();
		val = val + 1;
		cout << sc_time_stamp() << ",  " <<  clk << ",  " << val << endl;


	}	


}
