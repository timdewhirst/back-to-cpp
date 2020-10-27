//Create a class Complex that would describe a complex number, e.g. 5 + 3i. Remember, complex number has two parts, real and imaginary. 
#include <iostream>
#include <string>

class Complex{
    private:
        double real;
        double imag;

     public:
        Complex(){
            double real=0;
            double imag=0;
            char* operatr;
            }
         

    Complex(double new_real, double new_imag){
        real=new_real;
        imag=new_imag;
        }

//The class should implement the following set of functions and operators:
//getReal to get real part
    double getReal(){
        return real;
        }

//getImaginary to get imaginary part
    double getImaginary(){
        return imag;
    }
//setReal to set real part
    double setReal(double new_real){
        real=new_real;
        return real;
    }
//setImaginary to set imaginary part
    double setImaginary(double new_imag){
        imag=new_imag;
        return imag;

    }
};

//operator+ to add two complex numbers
    Complex operator+(Complex a, Complex b){
        Complex c;
        c.setReal(a.getReal() + b.getReal());
        c.setImaginary(a.getImaginary() + b.getImaginary());
        return c;
    }

//operator- to subtract a complex number from a complex number
    Complex operator-(Complex a, Complex b){
        Complex c;
        c.setReal(a.getReal() - b.getReal());
        c.setImaginary(a.getImaginary() - b.getImaginary());
        return c;
    }

//operator* to multiply tow complex numbers
    Complex operator*(Complex a, Complex b){
        Complex c;
        c.setReal((a.getReal()*b.getReal())-(a.getImaginary()*b.getImaginary()));
        c.setImaginary((a.getReal()*b.getImaginary())+(a.getImaginary()*b.getReal()));
        return c;

    }

//operator/ to divide a complex number form a complex number
    Complex operator/(Complex a, Complex b){
        Complex c;
        double div=((b.getReal()*b.getReal())+((b.getImaginary()*b.getImaginary())));
        c.setReal(((a.getReal() * b.getReal())-(a.getImaginary()*b.getImaginary()))/div);
        c.setImaginary(((a.getReal() * b.getImaginary())+(a.getImaginary()*b.getReal()))/div);
        return c;
    }


int main(){
    //Overloaded operators should allow to do the following operations:    
    Complex a(2,3), b(4,5), c;
    
    std::cout<<"Addition \n";
    c = a + b;
    std::cout<<c.getReal()<<"+"<<c.getImaginary()<<"i is the added complex number \n";
    
    std::cout<<"Subtraction \n";
    c = a - b;
    std::cout<<c.getReal()<<"+"<<c.getImaginary()<<"i is the subtracted complex number \n";

    std::cout<<"Multiplication \n";
    c = a * b;
    std::cout<<c.getReal()<<"+"<<c.getImaginary()<<"i is the multipied complex number \n";

    std::cout<<"Division \n";
    c = a / b;
    std::cout<<c.getReal()<<"+"<<c.getImaginary()<<"i is the divided complex number \n";

    return 0;
    
}
