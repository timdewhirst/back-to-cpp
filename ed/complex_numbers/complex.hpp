class Complex
{
private:
    double real;
    double imaginary;

public:
    Complex() : real{0}, imaginary{0} {};    
    Complex(double r, double i) : real{r}, imaginary{i} {};
    Complex(const Complex& other);
    // Complex& operator=(const Complex& other);
    ~Complex() {}

    double getReal() const;
    double getImaginary() const;
    void setReal(double number);
    void setImaginary(double number);
    void displayNumber();

    Complex operator+(const Complex& other);
    Complex operator-(const Complex& other);
    Complex operator*(const Complex& other);
    Complex operator/(const Complex& other);
    Complex operator/(const double divider);
};
