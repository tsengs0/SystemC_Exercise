#include "light.h"

void light::method_func()
{
	if(on)
	{
		printf("%6lld ps: %s\r\n", sc_time_stamp().value(), name());


	}



}
