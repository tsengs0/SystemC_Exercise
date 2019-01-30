#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class test {
	public:
		int *a;
		int *b;
		float *c;
		test(char *str, void *a_inout, void *b_inout, void *c_inout);
		~test();
		
};

test::test(char *str, void *a_inout, void *b_inout, void *c_inout)
{
	a = (int*) a_inout;
	b = (int*) b_inout;
	c = (float*) c_inout;
	cout << "This is the constructor of " << str << endl;
}

int main()
{
	int A, B;
	float C;
	A = 1; B = 2; C = 3.5;
	test *temp;
	temp = new test((char*) "CTOR_1", (void*) &A, (void*) &B, (void*) &C);
	cout << "a: " << *(temp -> a) << endl
	     << "b: " << *(temp -> b) << endl
	     << "c: " << *(temp -> c) << endl;
	cout << "==============================================" << endl;
	
	A = 2; B = 3; C = 4.5;
	cout << "a: " << *(temp -> a) << endl
	     << "b: " << *(temp -> b) << endl
	     << "c: " << *(temp -> c) << endl;
	return 0;
}
