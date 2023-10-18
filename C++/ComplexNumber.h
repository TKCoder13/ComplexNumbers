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
        void setR(double num);
        void setI(double num);
        double getR();
        double getI();
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