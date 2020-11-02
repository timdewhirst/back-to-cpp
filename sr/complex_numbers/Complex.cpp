/*Complex Numbers*/
/*Stephen Ripley*/
#include <iostream>

class Complex {

    public:

        double real;
        double imaginary;

        Complex() {
            real = 0;
            imaginary = 0;
        }
        
        Complex(double r, double i) {
            real = r;
            imaginary = i;
        }

        double getReal();
        double getImaginary();
        void setReal(double number);
        void setImaginary(double number);
        void displayNumber();
};

double Complex::getReal() {
     return real;
}

double Complex::getImaginary() {
   return imaginary;
}

void Complex::setReal(double number) {
    real = number;
}

void Complex::setImaginary(double number) {
    imaginary = number;
}

void Complex::displayNumber() {
    if(imaginary==0 || real==0) {
        std::cout << "The complex number is: " << real << "+" << imaginary << "i" << std::endl;
    } else if(imaginary>0) {
    std::cout << "The complex number is: " << real << "+" << imaginary << "i" << std::endl;
    } else {
        std::cout << "The complex number is: " << real << imaginary << "i" << std::endl;
    }
}

Complex operator+(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;
    return result;
}

Complex operator-(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real - c2.real;
    result.imaginary = c1.imaginary - c2.imaginary;
    return result;
}

Complex operator*(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real * c2.real;
    result.imaginary = c1.imaginary * c2.imaginary;
    return result;
}

Complex operator/(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real / c2.real;
    result.imaginary = c1.imaginary / c2.imaginary;
    return result;
}

int main(int argc, char* argv[]) {
    {
        std::cout << "Get Test" << std::endl;
        Complex a(1,2);
        std::cout << "The real number is: " << a.getReal() << std::endl;
        std::cout << "The imaginary number is: " << a.getImaginary() << std::endl;
        a.displayNumber();
    }
    {

        std::cout << "Set Test" << std::endl;
        Complex a;
        a.setReal(5);
        a.setImaginary(4);
        a.displayNumber();
    }
    {
        std::cout << "Addition Test" << std::endl;
        Complex a(4,5), b(9,10), c;
        c = a+b;
        c.displayNumber();
    }
    {
        std::cout << "Subtraction Test" << std::endl;
        Complex a(10,8), b(12,8), c;
        c = a-b;
        c.displayNumber();
    }
    {
        std::cout << "Multiplication Test" << std::endl;
        Complex a(5,10), b(3,-2), c;
        c = a*b;
        c.displayNumber();
    }
    {
        std::cout << "Division Test" << std::endl;
        Complex a(100,8), b(50,4), c;
        c = a/b;
        c.displayNumber();
    }

}