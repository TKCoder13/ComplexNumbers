#include <iostream>
#include "ComplexNumber.h"
#include "ComplexNumber.cpp"

using namespace std;

int main(int argc, char** argv)
{

	cout << "double Version" << endl;
	ComplexNumber lhs(1, 2);
	ComplexNumber rhs(3, 4);

	ComplexNumber result;

	result = lhs.add(rhs);
	cout << "(" << lhs.toString() << ") + (" << rhs.toString() << ") = ";
	cout << "(" << result.toString() << ")" << endl;

	result = lhs.sub(rhs);
	cout << "(" << lhs.toString() << ") - (" << rhs.toString() << ") = ";
	cout << "(" << result.toString() << ")" << endl;

	result = lhs.mult(rhs);
	cout << "(" << lhs.toString() << ") * (" << rhs.toString() << ") = ";
	cout << "(" << result.toString() << ")" << endl;

	result = lhs.div(rhs);
	cout << "(" << lhs.toString() << ") / (" << rhs.toString() << ") = ";
	cout << "(" << result.toString() << ")" << endl;

	try {
		ComplexNumber rhs;
		cout << "(" << lhs.toString() << ") / (" << rhs.toString() << ") = ";
		result = lhs.div(rhs);
		cout << "(" << result.toString() << ")" << endl;
	}
	catch (const char* msg) {
		cout << "Exception: " << msg << endl;
	}

	cout << "|(" << lhs.toString() << ")|) = ";
	cout << lhs.mag() << endl;

	cout << "conjugate(" << lhs.toString() << ")) = ";
	cout << lhs.conj().toString() << endl;

	cout << "sqrt(" << lhs.toString() << ")) = ";
	cout << lhs.sqrt().toString() << endl;
	cout << "sqrt(" << lhs.toString() << ") * sqrt(" << lhs.toString() << ") = " << lhs.sqrt().mult(lhs.sqrt()).toString() << endl;

	cout << "(" << lhs.toString() << ") == (" << rhs.toString() << ") = ";
	cout << (lhs.equals(rhs) ? "true" : "false") << endl;

	rhs.setReal(lhs.getReal());
	rhs.setImag(lhs.getImag());
	cout << "(" << lhs.toString() << ") == (" << rhs.toString() << ") = ";
	cout << (lhs.equals(rhs) ? "true" : "false") << endl;


	return 0;
}