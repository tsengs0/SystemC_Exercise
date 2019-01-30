#include "fsm.h"

void fsm::method_func()
{
	while(1)
	{
		red_on = true; yellow_on = false; green_on = false;
		wait(10);

		red_on = false; yellow_on = false; green_on = true;
		wait(10);

		red_on = false; yellow_on = true; green_on = false;
		wait(2);		



	}


}
