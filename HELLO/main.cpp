#include "hello.h"

int sc_main(int argc, char **argv)
{
	hello_world hello("HELLO");

	hello.say_hello();

	return 0;
}
