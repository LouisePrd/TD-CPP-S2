#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1{3, 4};
    Fraction f2{1, 2};
    Fraction f3{1, 2};

    // Affichage
    std::cout << "f1 = ";
    f1.display();
    std::cout << " f2 = ";
    f2.display();
    std::cout << std::endl;

    // Opérateurs de base
    // Addition
    std::cout << "add(f1, f2) = ";
    add(f1, f2).display();
    std::cout << " et avec opérateur : " << f1 + f2 << std::endl;

    // Soustraction
    std::cout
        << "sub(f1, f2) = ";
    (sub(f1, f2)).display();
    std::cout << " et avec opérateur : " << f1 - f2 << std::endl;

    // Multiplication
    std::cout
        << "mul(f1, f2) = ";
    (mul(f1, f2)).display();
    std::cout << " et avec opérateur : " << f1 * f2 << std::endl;

    // Division
    std::cout
        << "div(f1, f2) = ";
    (div(f1, f2)).display();
    std::cout << " et avec opérateur : " << f1 / f2 << std::endl;

    // Conversions
    float d1{static_cast<float>(f3)};
    std::cout << "float(f3) = " << d1 << std::endl;

    return 0;
}