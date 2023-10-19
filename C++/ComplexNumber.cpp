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

ComplexNumber::~ComplexNumber() {}

void ComplexNumber::setReal(double num) {
    this->real = num;
}

void ComplexNumber::setImag(double num) {
    this->imag = num;
}

double ComplexNumber::getReal() {
    return this->real;
}

double ComplexNumber::getImag() {
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
    char divZeroMessage[] = "Cannot be divisible by 0";
    char *divZeroException = divZeroMessage;
    try {
        if (rhs.real == 0 || rhs.imag == 0) {
            throw divZeroException;
        }
        double realOutput = this->real / rhs.real;
        double imagOutput = this->imag / rhs.imag;
        ComplexNumber output(realOutput, imagOutput);
        return output;
    } catch (const char* exception) {
        cout << exception << endl;
    }
} 

double ComplexNumber::mag() {
    double output = std::sqrt((this->real * this->real) + (this->imag * this->imag));
    return output;
}

ComplexNumber ComplexNumber::conj() {
    double imagOutput = 0 - this->imag;
    ComplexNumber output(this->real, imagOutput);
}

ComplexNumber ComplexNumber::sqrt() {
    // -- sqrt(-1) = i
    // -- sqrt(i) = -1
    if (this->real < 0 && this->imag < 0) {
        double realOutput = std::sqrt(std::abs(this->imag));
        double imagOutput = std::sqrt(std::abs(this->real));
        ComplexNumber output(realOutput, imagOutput);
        return output;
    } else if (this->real < 0) {
        double realOutput = 0;
        double imagOutput = std::sqrt(std::abs(this->real)) + std::sqrt(this->imag);
        ComplexNumber output(realOutput, imagOutput);
        return output;
    } else if (this->imag < 0) {
        double realOutput = std::sqrt(this->real) + std::sqrt(std::abs(this->imag));
        double imagOutput = 0;
        ComplexNumber output(realOutput, imagOutput);
        return output;
    }
    double realOutput = std::sqrt(this->real);
    double imagOutput = std::sqrt(this->imag);
    ComplexNumber output(realOutput, imagOutput);
    return output;
}

bool ComplexNumber::equals(ComplexNumber& rhs) {
    if (typeid(*this) != typeid(rhs))
        return false;
    if (this->real == rhs.real && this->imag == rhs.imag)
        return true;
    return false;
}