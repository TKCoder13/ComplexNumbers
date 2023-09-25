class ComplexNumber {

    private double real;
    private double imag;

    public ComplexNumber() {
        this.real = 0;
        this.imag = 0;
    }

    public ComplexNumber(double num1, double num2) {
        this.real = num1;
        this.imag = num2;
    }

    public ComplexNumber(ComplexNumber cn) {
        this.real = cn.real;
        this.imag = cn.imag;
    }

    public void setR(double input) {
        this.real = input;
    }

    public void setI(double input) {
        this.imag = input;
    }

    public double getR() {
        return this.real;
    }

    public double getI() {
        return this.imag;
    }

    public String toString(ComplexNumber input) {
        return "";
    }

    public ComplexNumber add(ComplexNumber input) {

    }

    public ComplexNumber sub(ComplexNumber input) {

    }

    public ComplexNumber mult(ComplexNumber input) {

    }

    public ComplexNumber div(ComplexNumber input) {

    }

    public double mag() {

    }

    public ComplexNumber conj() {

    }

    public ComplexNumber sqrt() {

    }

    public boolean equals(Object obj) {

    }

    
}