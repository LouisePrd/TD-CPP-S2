#include "fraction.hpp"
#include "utils.hpp"
#include <iostream>

void Fraction::display()
{
    std::cout << numerator << "/" << denominator;
}

Fraction add(Fraction const &f1, Fraction const &f2)
{
    return simplify({f1.numerator * f2.denominator + f2.numerator * f1.denominator,
                     f1.denominator * f2.denominator});
}

Fraction sub(Fraction const &f1, Fraction const &f2)
{
    return simplify({f1.numerator * f2.denominator - f2.numerator * f1.denominator,
                     f1.denominator * f2.denominator});
}

Fraction mul(Fraction const &f1, Fraction const &f2)
{
    return simplify({f1.numerator * f2.numerator,
                     f1.denominator * f2.denominator});
}

Fraction div(Fraction const &f1, Fraction const &f2)
{
    return simplify({f1.numerator * f2.denominator,
                     f1.denominator * f2.numerator});
}

// Operateur partie 1
/*
Fraction operator+(Fraction const& f1, Fraction const& f2)
{
    return simplify({f1.numerator * f2.denominator + f2.numerator * f1.denominator,
                     f1.denominator * f2.denominator});
}

Fraction operator-(Fraction const &f1, Fraction const &f2)
{
    return sub(f1, f2);
}

Fraction operator*(Fraction const &f1, Fraction const &f2)
{
    return mul(f1, f2);
}

Fraction operator/(Fraction const &f1, Fraction const &f2)
{
    return div(f1, f2);
}
*/

std::ostream &operator<<(std::ostream &os, Fraction const &f1)
{
    return os << f1.numerator << "/" << f1.denominator;
}

bool operator==(Fraction const &f1, Fraction const &f2)
{
    if (f1.numerator * f2.denominator == f2.numerator * f1.denominator)
    {
        return true;
    }
}

bool operator!=(Fraction const &f1, Fraction const &f2)
{
    return !(f1.numerator * f2.denominator == f2.numerator * f1.denominator);
}

bool operator<(Fraction const &f1, Fraction const &f2)
{
    if (f1.numerator * f2.denominator < f2.numerator * f1.denominator)
    {
        return true;
    }
}

bool operator<=(Fraction const &f1, Fraction const &f2)
{
    if (f1.numerator * f2.denominator <= f2.numerator * f1.denominator)
    {
        return true;
    }
}

bool operator>(Fraction const &f1, Fraction const &f2)
{
    if (f1.numerator * f2.denominator > f2.numerator * f1.denominator)
    {
        return true;
    }
}

bool operator>=(Fraction const &f1, Fraction const &f2)
{
    if (f1.numerator * f2.denominator >= f2.numerator * f1.denominator)
    {
        return true;
    }
}

Fraction operator+=(Fraction &f1, Fraction const &f2)
{
    f1 = f1 + f2;
    return f1;
}

Fraction operator-=(Fraction &f1, Fraction const &f2)
{
    f1 = f1 - f2;
    return f1;
}

Fraction operator*=(Fraction &f1, Fraction const &f2)
{
    f1 = f1 * f2;
    return f1;
}

Fraction operator/=(Fraction &f1, Fraction const &f2)
{
    f1 = f1 / f2;
    return f1;
}

// Operateur partie 2 : deux-en-un
Fraction operator+(Fraction &f1, Fraction &f2)
{
    f1 += f2;
    return f1;
}

Fraction operator-(Fraction &f1, Fraction &f2)
{
    f1 -= f2;
    return f1;
}

Fraction operator*(Fraction &f1, Fraction &f2)
{
    f1 *= f2;
    return f1;
}

Fraction operator/(Fraction &f1, Fraction &f2)
{
    f1 /= f2;
    return f1;
}

// Conversions
float Fraction::to_float()
{
    return static_cast<float>(numerator) / denominator;
}

Fraction::operator float() const
{
    return static_cast<float>(numerator) / denominator;
}