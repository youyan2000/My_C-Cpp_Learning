#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <cmath>

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0);
    
    // Copy constructor
    Complex(const Complex& other);
    
    // Destructor
    ~Complex();

    // Basic accessor functions
    double getReal() const;
    double getImag() const;
    void setReal(double r);
    void setImag(double i);
    
    // Arithmetic operators
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;
    
    // Compound assignment operators
    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);
    
    // Unary operators
    Complex operator-() const;
    Complex operator+() const;
    Complex& operator++();      // Prefix increment
    Complex operator++(int);    // Postfix increment
    Complex& operator--();      // Prefix decrement
    Complex operator--(int);    // Postfix decrement
    
    // Comparison operators
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
    bool operator<(const Complex& other) const;
    bool operator>(const Complex& other) const;
    bool operator<=(const Complex& other) const;
    bool operator>=(const Complex& other) const;
    
    // Assignment operator
    Complex& operator=(const Complex& other);
    
    // Type conversion
    explicit operator double() const;
    explicit operator bool() const;
    
    // Mathematical functions
    double norm() const;        // Magnitude
    double normSquared() const; // Magnitude squared
    double arg() const;         // Argument (phase angle)
    Complex conj() const;       // Conjugate
    Complex inv() const;        // Reciprocal
    
    // Static factory method
    static Complex fromPolar(double r, double theta);
    
    // Friend functions
    friend Complex operator+(const Complex& c, double d);
    friend Complex operator+(double d, const Complex& c);
    friend Complex operator*(const Complex& c, double d);
    friend Complex operator*(double d, const Complex& c);
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
};

// Non-member functions
Complex pow(const Complex& c, int n);
Complex exp(const Complex& c);
Complex sin(const Complex& c);
Complex cos(const Complex& c);

#endif // COMPLEX_H
