#pragma once
#include <iostream>

struct Fraction {
    unsigned int numerator;
    unsigned int denominator;

    void display();
    float to_float();
    operator float() const;
};

Fraction add(Fraction const& f1, Fraction const& f2);
Fraction sub(Fraction const& f1, Fraction const& f2);
Fraction mul(Fraction const& f1, Fraction const& f2);
Fraction div(Fraction const& f1, Fraction const& f2);

Fraction operator+(Fraction const& f1, Fraction const& f2);
Fraction operator-(Fraction const& f1, Fraction const& f2);
Fraction operator*(Fraction const& f1, Fraction const& f2);
Fraction operator/(Fraction const& f1, Fraction const& f2);

std::ostream& operator<<(std::ostream& os, Fraction const& f1);

bool operator==(Fraction const& f1, Fraction const& f2);
bool operator!=(Fraction const& f1, Fraction const& f2);
bool operator<(Fraction const& f1, Fraction const& f2);
bool operator>(Fraction const& f1, Fraction const& f2);
bool operator<=(Fraction const& f1, Fraction const& f2);    
bool operator>=(Fraction const& f1, Fraction const& f2);

Fraction operator+=(Fraction &f1, Fraction const &f2);
Fraction operator-=(Fraction &f1, Fraction const &f2);
Fraction operator*=(Fraction &f1, Fraction const &f2);
Fraction operator/=(Fraction &f1, Fraction const &f2);

// Bonus
Fraction operator+(Fraction const& f, int const i);
Fraction operator+(int const i, Fraction const& f);
Fraction operator-(Fraction const& f, int const i);
Fraction operator*(Fraction const& f, int const i);
Fraction operator/(Fraction const& f, int const i);
Fraction abs(Fraction const& f);
float ceil(Fraction const& f);
float floor(Fraction const& f);
float round(Fraction const& f);