//
// Created by Pavel Kilko on 9/20/2021.
//

#include "rational.h"

#include <iostream>

int gcd(int x, int y) // Euclidean algorithm
{
    if (y == 0) return x;
    return gcd(y, x % y);
}

void reduction(int &x, int &y)
{
    int nod = gcd(x, y);
    if(!nod)
    {
        y = 1;
        return;
    }
    x /= nod;
    y /= nod;
    if(y < 0)
    {
        x *= -1;
        y *= -1;
    }
}

Rational::Rational()
{
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int n, int d)
{
    numerator = n;
    denominator = d;
    if(!d)
        denominator = 1;
    reduction(numerator, denominator);
}

void Rational::print() const
{
    std::cout << numerator << "/" << denominator;
}

Rational operator + (const Rational &r1,const Rational &r2)
{
    Rational r3;
    r3.denominator = r1.denominator * r2.denominator;
    r3.numerator = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
    reduction(r3.numerator, r3.denominator);
    return r3;
}

Rational operator - (const Rational &r1,const Rational &r2)
{
    Rational r3;
    r3.denominator = r1.denominator * r2.denominator;
    r3.numerator = r1.numerator * r2.denominator - r2.numerator * r1.denominator;
    reduction(r3.numerator, r3.denominator);
    return r3;
}

Rational operator * (const Rational &r1,const Rational &r2)
{
    Rational r3;
    r3.denominator = r1.denominator * r2.denominator;
    r3.numerator = r1.numerator * r2.numerator;
    reduction(r3.numerator, r3.denominator);
    return r3;
}

Rational operator / (const Rational &r1, const Rational &r2)
{
    Rational r3;
    r3.denominator = r1.denominator * r2.numerator;
    r3.numerator = r1.numerator * r2.denominator;
    reduction(r3.numerator, r3.denominator);
    return r3;
}