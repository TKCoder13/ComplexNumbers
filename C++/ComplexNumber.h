#pragma once

#include <string>
#include <iostream>

using namespace std;

class ComplexNumber {

    public:
        // -- Constructors
        ComplexNumber();
        ComplexNumber(double realNum, double imagNum);
        ComplexNumber(const ComplexNumber &src);
        ~ComplexNumber();

        // -- Methods
        void setReal(double num);
        void setImag(double num);
        double getReal();
        double getImag();
        string toString();
        ComplexNumber add(ComplexNumber rhs);
        ComplexNumber sub(ComplexNumber rhs);
        ComplexNumber mult(ComplexNumber rhs);
        ComplexNumber div(ComplexNumber rhs);
        double mag();
        ComplexNumber conj();
        ComplexNumber sqrt();
        bool equals(ComplexNumber rhs);

    private:
        double real;
        double imag;
};