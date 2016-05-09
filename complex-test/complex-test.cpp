#include <iostream>
#include "complex.h"

using namespace std;

// << overloading
ostream&
operator << (ostream& os, complex& x)
{
	return os << '(' << real(x) << ',' << imag(x) << ')';
}

int main()
{
	complex c1(1,2);
	cout << c1 << endl;
	complex c2(10,355.4447);
	cout << c2 << endl;
	c2 += c1;
	cout << c2 << endl;
	complex c3;
	c3 = c2 + c2;
	cout << c3 << endl;
	complex c4;
	c4 = conj(c3);
	cout << c4 << endl;


	return 0;
}