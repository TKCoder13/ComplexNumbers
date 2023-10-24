#include "ComplexNumber.h"

#include <string>
#include <typeinfo>
#include <cmath>

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
    bool realNegative = false;
    bool imagNegative = false;
    if (this->real < 0) realNegative = true;
    if (this->imag < 0) imagNegative = true;
    
    double realOutput = std::abs(this->real);
    double imagOutput = std::abs(this->imag);

    if (realOutput == 0.0 && imagOutput == 0.0) {
        return "0";
    } else if (realOutput != 0.0 && imagOutput == 0.0) {
        if (realNegative) 
            return "-" + to_string(realOutput);
        return to_string(realOutput);
    } else if (realOutput == 0.0 && imagOutput != 0.0) {
        if (imagNegative)
            return "0 - " + to_string(imagOutput) + "i";
        return to_string(imagOutput) + "i";
    }
    if (realNegative && imagNegative) {
        return "-" + to_string(realOutput) + " - " + to_string(imagOutput) + "i";
    } else if (realNegative) {
        return "-" + to_string(realOutput) + " + " + to_string(imagOutput) + "i";
    } else if (imagNegative) {
        return to_string(realOutput) + " - " + to_string(imagOutput) + "i";
    } else {
        return to_string(realOutput) + " + " + to_string(imagOutput) + "i";
    }
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
    double realOutput = 0;
    double imagOutput = 0;
    try {
        if (rhs.real == 0 || rhs.imag == 0) {
            throw divZeroException;
            exit;
        } else {
            realOutput = this->real / rhs.real;
            imagOutput = this->imag / rhs.imag;
            ComplexNumber output(realOutput, imagOutput);
            return output;
        }
    } catch (const char* exception) {
        cout << "Exception: " << exception << endl;
    }
} 

double ComplexNumber::mag() {
    double realOutput = this->real;
    double imagOutput = this->imag;
    double output = std::sqrt(std::pow(realOutput, 2) + std::pow(imagOutput, 2));
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
        double imagOutput = std::sqrt(abs(this->real)) + std::sqrt(this->imag);
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