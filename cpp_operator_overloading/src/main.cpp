#include "complex.hpp"
#include <iostream>

int main() {
    try {
        // Create complex numbers
        Complex c1(3, 4);
        Complex c2(1, -2);
        
        std::cout << "c1 = " << c1 << std::endl;
        std::cout << "c2 = " << c2 << std::endl;
        
        // Arithmetic operations
        std::cout << "\n=== Arithmetic Operations ===" << std::endl;
        std::cout << "c1 + c2 = " << c1 + c2 << std::endl;
        std::cout << "c1 - c2 = " << c1 - c2 << std::endl;
        std::cout << "c1 * c2 = " << c1 * c2 << std::endl;
        std::cout << "c1 / c2 = " << c1 / c2 << std::endl;
        
        // Scalar operations
        std::cout << "\n=== Scalar Operations ===" << std::endl;
        std::cout << "c1 + 5 = " << c1 + 5 << std::endl;
        std::cout << "3 * c1 = " << 3 * c1 << std::endl;
        
        // Compound assignment
        std::cout << "\n=== Compound Assignment ===" << std::endl;
        Complex c3 = c1;
        c3 += c2;
        std::cout << "c1 += c2 -> " << c3 << std::endl;
        
        // Unary operations
        std::cout << "\n=== Unary Operations ===" << std::endl;
        std::cout << "-c1 = " << -c1 << std::endl;
        
        Complex c4(2, 0);
        std::cout << "++c4 = " << ++c4 << std::endl;
        std::cout << "c4++ = " << c4++ << std::endl;
        std::cout << "c4 after postfix = " << c4 << std::endl;
        
        // Mathematical functions
        std::cout << "\n=== Mathematical Functions ===" << std::endl;
        std::cout << "|c1| = " << c1.norm() << std::endl;
        std::cout << "arg(c1) = " << c1.arg() << " rad" << std::endl;
        std::cout << "conj(c1) = " << c1.conj() << std::endl;
        std::cout << "inv(c1) = " << c1.inv() << std::endl;
        
        // Polar coordinates
        Complex c5 = Complex::fromPolar(5, M_PI / 4);
        std::cout << "\nFrom polar (r=5, theta=π/4): " << c5 << std::endl;
        
        // Advanced functions
        std::cout << "\n=== Advanced Functions ===" << std::endl;
        std::cout << "c1^3 = " << pow(c1, 3) << std::endl;
        std::cout << "exp(c1) = " << exp(c1) << std::endl;
        std::cout << "sin(c1) = " << sin(c1) << std::endl;
        std::cout << "cos(c1) = " << cos(c1) << std::endl;
        
        // Comparison operations
        std::cout << "\n=== Comparison Operations ===" << std::endl;
        std::cout << "c1 == c2? " << (c1 == c2 ? "true" : "false") << std::endl;
        std::cout << "c1 != c2? " << (c1 != c2 ? "true" : "false") << std::endl;
        std::cout << "|c1| > |c2|? " << (c1 > c2 ? "true" : "false") << std::endl;
        
        // Type conversion
        std::cout << "\n=== Type Conversion ===" << std::endl;
        std::cout << "double(c1) = " << static_cast<double>(c1) << std::endl;
        std::cout << "bool(c1) = " << (static_cast<bool>(c1) ? "true" : "false") << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
