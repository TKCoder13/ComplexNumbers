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

    public void setReal(double input) {
        this.real = input;
    }

    public void setImag(double input) {
        this.imag = input;
    }

    public double getReal() {
        return this.real;
    }

    public double getImag() {
        return this.imag;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof ComplexNumber) {
			ComplexNumber rnObj = (ComplexNumber) obj;
			if (rnObj.real == this.real &&
            rnObj.imag == this.imag) {
                return true;
            } else {
                return false;
            } 
		} else {
			return false;
		}
    }

    @Override
    public String toString() {
        boolean real_isNegative = false;
        boolean imag_isNegative = false;
        boolean real_isZero = false;
        boolean imag_isZero = false;
        String output = "";

        if (this.real < 0) {
           real_isNegative = true; 
        } else if (this.real == 0) {
            real_isZero = true;
        }

        if (this.imag < 0) {
            imag_isNegative = true;
        } else if (this.imag == 0) {
            imag_isZero = true;
        }

        double tempReal = Math.abs(this.real);
        double tempImag = Math.abs(this.imag);
        
        if (real_isZero && imag_isZero) {
            output = "0";
        } else if (!real_isZero && imag_isZero) {
            if (real_isNegative) {
                output = "-" + tempReal;
            } else {
                output = "" + tempReal;
            }
        } else if (real_isZero && !imag_isZero) {
            if (imag_isNegative) {
                output = "-" + tempImag + "i";
            } else {
                output = "" + tempImag + "i";
            }
        } else {
            if (real_isNegative && imag_isNegative) {
                output = "-" + tempReal + " - " + tempImag + "i";
            } else if (!real_isNegative && imag_isNegative) {
                output = "" + tempReal + " - " + tempImag + "i";
            } else if (real_isNegative && !imag_isNegative) {
                output = "-" + tempReal + " + " + tempImag + "i";
            } else {
                output = "" + tempReal + " + " + tempImag + "i";
            }
        }

        return output;
    }

    public ComplexNumber add(ComplexNumber input) {
        double tempReal = this.real + input.real;
        double tempImag = this.imag + input.imag;
        ComplexNumber output = new ComplexNumber(tempReal, tempImag);
        return output;
    }

    public ComplexNumber sub(ComplexNumber input) {
        double tempReal = this.real - input.real;
        double tempImag = this.imag - input.imag;
        ComplexNumber output = new ComplexNumber(tempReal, tempImag);
        return output;
    }

    public ComplexNumber mult(ComplexNumber input) {
        double tempReal = this.real * input.real;
        double tempImag = this.imag * input.imag;
        ComplexNumber output = new ComplexNumber(tempReal, tempImag);
        return output;
    }

    public ComplexNumber div(ComplexNumber input) throws ArithmeticException {
        
        try {
            double tempReal = this.real / input.real;
            double tempImag = this.imag / input.imag;
            ComplexNumber output = new ComplexNumber(tempReal, tempImag);
            return output;
        } catch(ArithmeticException e) {
            throw new ArithmeticException("Cannot divide by 0");
        }
    }

    public double mag() {
        double magnitude = Math.sqrt(this.real*this.real + this.imag*this.imag);
        return magnitude;
    }

    public ComplexNumber conj() {
        double tempImag = this.imag * -1;
        ComplexNumber output = new ComplexNumber(this.real, tempImag);
        return output;
    }

    public ComplexNumber sqrt() {
        boolean real_isNegative = false;
        boolean imag_isNegative = false;
        double tempReal = 0;
        double tempImag = 0;
        if (this.real < 0) real_isNegative = true;
        if (this.imag < 0) real_isNegative = true;
        
        // -- Check for logic of sqrt(imag)
        if (!real_isNegative && !imag_isNegative) {
            tempReal = Math.sqrt(Math.abs(this.real));
            tempImag = Math.sqrt(Math.abs(this.imag));
        } else if (!real_isNegative && imag_isNegative) {
            tempReal = Math.sqrt(Math.abs(this.real))
                - Math.sqrt(Math.abs(this.imag));
            tempImag = 0;
        } else if (real_isNegative && !imag_isNegative) {
            tempReal = 0;
            tempImag = Math.sqrt(Math.abs(this.imag)) 
                + Math.sqrt(Math.abs(this.real));
        } else {
            tempReal = -1 * Math.sqrt(Math.abs(this.imag));
            tempImag = Math.sqrt(Math.abs(this.real));
        }
        
        ComplexNumber output = new ComplexNumber(tempReal, tempImag);
        return output;
    }
}