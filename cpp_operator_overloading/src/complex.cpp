#include "complex.hpp"
#include <stdexcept>

// ========== Constructors and Destructors ==========
Complex::Complex(double r, double i) : real(r), imag(i) {}

Complex::Complex(const Complex& other) : real(other.real), imag(other.imag) {}

Complex::~Complex() {}

// ========== Basic Accessor Functions ==========
double Complex::getReal() const { return real; }
double Complex::getImag() const { return imag; }
void Complex::setReal(double r) { real = r; }
void Complex::setImag(double i) { imag = i; }

// ========== Arithmetic Operators ==========
Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(
        real * other.real - imag * other.imag,
        real * other.imag + imag * other.real
    );
}

Complex Complex::operator/(const Complex& other) const {
    double denominator = other.real * other.real + other.imag * other.imag;
    if (denominator == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return Complex(
        (real * other.real + imag * other.imag) / denominator,
        (imag * other.real - real * other.imag) / denominator
    );
}

// ========== Compound Assignment Operators ==========
Complex& Complex::operator+=(const Complex& other) {
    real += other.real;
    imag += other.imag;
    return *this;
}

Complex& Complex::operator-=(const Complex& other) {
    real -= other.real;
    imag -= other.imag;
    return *this;
}

Complex& Complex::operator*=(const Complex& other) {
    double newReal = real * other.real - imag * other.imag;
    double newImag = real * other.imag + imag * other.real;
    real = newReal;
    imag = newImag;
    return *this;
}

Complex& Complex::operator/=(const Complex& other) {
    double denominator = other.real * other.real + other.imag * other.imag;
    if (denominator == 0) {
        throw std::invalid_argument("Division by zero");
    }
    double newReal = (real * other.real + imag * other.imag) / denominator;
    double newImag = (imag * other.real - real * other.imag) / denominator;
    real = newReal;
    imag = newImag;
    return *this;
}

// ========== Unary Operators ==========
Complex Complex::operator-() const {
    return Complex(-real, -imag);
}

Complex Complex::operator+() const {
    return *this;
}

Complex& Complex::operator++() {
    ++real;
    return *this;
}

Complex Complex::operator++(int) {
    Complex temp(*this);
    ++real;
    return temp;
}

Complex& Complex::operator--() {
    --real;
    return *this;
}

Complex Complex::operator--(int) {
    Complex temp(*this);
    --real;
    return temp;
}

// ========== Comparison Operators ==========
bool Complex::operator==(const Complex& other) const {
    return (real == other.real) && (imag == other.imag);
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

bool Complex::operator<(const Complex& other) const {
    return norm() < other.norm();
}

bool Complex::operator>(const Complex& other) const {
    return norm() > other.norm();
}

bool Complex::operator<=(const Complex& other) const {
    return norm() <= other.norm();
}

bool Complex::operator>=(const Complex& other) const {
    return norm() >= other.norm();
}

// ========== Assignment Operator ==========
Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {
        real = other.real;
        imag = other.imag;
    }
    return *this;
}

// ========== Type Conversion ==========
Complex::operator double() const {
    return norm();
}

Complex::operator bool() const {
    return (real != 0) || (imag != 0);
}

// ========== Mathematical Functions ==========
double Complex::norm() const {
    return std::sqrt(real * real + imag * imag);
}

double Complex::normSquared() const {
    return real * real + imag * imag;
}

double Complex::arg() const {
    return std::atan2(imag, real);
}

Complex Complex::conj() const {
    return Complex(real, -imag);
}

Complex Complex::inv() const {
    double denominator = normSquared();
    if (denominator == 0) {
        throw std::invalid_argument("Inverse of zero");
    }
    return Complex(real / denominator, -imag / denominator);
}

// ========== Static Factory Method ==========
Complex Complex::fromPolar(double r, double theta) {
    return Complex(r * std::cos(theta), r * std::sin(theta));
}

// ========== Friend Functions Implementation ==========
Complex operator+(const Complex& c, double d) {
    return Complex(c.real + d, c.imag);
}

Complex operator+(double d, const Complex& c) {
    return Complex(d + c.real, c.imag);
}

Complex operator*(const Complex& c, double d) {
    return Complex(c.real * d, c.imag * d);
}

Complex operator*(double d, const Complex& c) {
    return Complex(c.real * d, c.imag * d);
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << "(" << c.real;
    if (c.imag >= 0) {
        os << "+" << c.imag << "i)";
    } else {
        os << c.imag << "i)";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Complex& c) {
    std::cout << "Enter real and imaginary parts: ";
    is >> c.real >> c.imag;
    return is;
}

// ========== Non-member Functions Implementation ==========
Complex pow(const Complex& c, int n) {
    if (n == 0) return Complex(1, 0);
    if (n < 0) return pow(c.inv(), -n);
    
    Complex result(1, 0);
    Complex base = c;
    while (n > 0) {
        if (n & 1) result *= base;
        base *= base;
        n >>= 1;
    }
    return result;
}

Complex exp(const Complex& c) {
    double e_real = std::exp(c.getReal());
    return Complex(
        e_real * std::cos(c.getImag()),
        e_real * std::sin(c.getImag())
    );
}

Complex sin(const Complex& c) {
    return Complex(
        std::sin(c.getReal()) * std::cosh(c.getImag()),
        std::cos(c.getReal()) * std::sinh(c.getImag())
    );
}

Complex cos(const Complex& c) {
    return Complex(
        std::cos(c.getReal()) * std::cosh(c.getImag()),
        -std::sin(c.getReal()) * std::sinh(c.getImag())
    );
}
