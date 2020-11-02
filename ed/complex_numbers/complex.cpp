#include <iostream>
#include "complex.hpp"

using namespace std;

Complex::Complex(const Complex& other)
{
    real = other.real;
    imaginary = other.imaginary;
}

double Complex::getReal() const
{
     return real;
}

double Complex::getImaginary() const
{
   return imaginary;
}

void Complex::setReal(double number)
{
    real = number;
}

void Complex::setImaginary(double number)
{
    imaginary = number;
}

void Complex::displayNumber()
{
    cout << "The complex number is: " << real << "+" << imaginary << "i" << endl;
}

Complex Complex::operator+(const Complex& other)
{
    return Complex(real + other.getReal(), imaginary + other.getImaginary());
}

Complex Complex::operator-(const Complex& other)
{
    return Complex(real - other.getReal(), imaginary - other.getImaginary());
}

Complex Complex::operator*(const Complex& other)
{
    Complex result;

    result.setReal(real * other.getReal() - imaginary * other.getImaginary());
    result.setImaginary(real * other.getImaginary() + imaginary * other.getReal());

    return result;
}

Complex Complex::operator/(const double divider)
{
    return Complex(real / divider, imaginary / divider);
}

Complex Complex::operator/(const Complex& other)
{
    Complex result;

    // result.setReal();
    // result.setImaginary();

    return result;
}
