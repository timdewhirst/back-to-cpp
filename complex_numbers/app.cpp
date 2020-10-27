#include <iostream>
#include "Complex.hpp"

using namespace std;

int main()
{
    Complex a, b, c;

    cout << "Get Test" << endl;
    a = Complex(1,2);
    cout << "The real number is: " << a.getReal() << endl;
    cout << "The imaginary number is: " << a.getImaginary() << endl;
    a.displayNumber();

    cout << endl << "Set Test" << endl;
    a.setReal(5);
    a.setImaginary(4);
    a.displayNumber();

    cout << endl << "Addition Test" << endl;
    a = Complex(4, 5);
    b = Complex(9, 10);
    c = a + b;
    c.displayNumber();

    cout << endl << "Subtraction Test" << endl;
    a = Complex(10, 8);
    b = Complex(12, 8);
    c = a - b;
    c.displayNumber();

    cout << "Multiplication Test" << endl;
    a = Complex(3, 2);
    b = Complex(1, 7);
    c = a * b;
    c.displayNumber();

    c = Complex(4, 4) / 2;
    c.displayNumber();
    
    (Complex(4, 4) / 2).displayNumber();

    // cout << "Division Test" << endl;
    // Complex a(100,8), b(50,4), c;
    // c = a/b;
    // c.displayNumber();
}
