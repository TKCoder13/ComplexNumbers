#include "ComplexNumber.h"

#include <string>
#include <typeinfo>

using namespace std;

double real;
double imag;

ComplexNumber::ComplexNumber(): real(0), imag(0) {}

ComplexNumber::ComplexNumber(double realNum, double imagNum) {
    this->real = realNum;
    this->imag = imagNum;
}

ComplexNumber::ComplexNumber(const ComplexNumber &src) {
    this->real = src.real;
    this->imag = src.imag;
}

void ComplexNumber::setR(double num) {
    this->real = num;
}

void ComplexNumber::setI(double num) {
    this->imag = num;
}

double ComplexNumber::getR() {
    return this->real;
}

double ComplexNumber::getI() {
    return this->imag;
}

string ComplexNumber::toString() {
    return "";
}

ComplexNumber ComplexNumber::add(ComplexNumber rhs) {
    double realOutput = this->real + rhs.real;
    double imagOutput = this->imag + rhs.imag;
    ComplexNumber output(realOutput, imagOutput);
    return output;
}

ComplexNumber ComplexNumber::sub(ComplexNumber rhs) {
    double realOutput = this->real - rhs.real;
    double imagOutput = this->imag - rhs.imag;
    ComplexNumber output(realOutput, imagOutput);
    return output;
}

ComplexNumber ComplexNumber::mult(ComplexNumber rhs) {
    double realOutput = this->real * rhs.real;
    double imagOutput = this->imag * rhs.imag;
    ComplexNumber output(realOutput, imagOutput);
    return output;
}

ComplexNumber ComplexNumber::div(ComplexNumber rhs) {
    
} 