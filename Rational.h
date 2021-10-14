//
// Created by Pavel on Kilko 9/20/2021.
//

#ifndef LAB1_RATIONAL_H
#define LAB1_RATIONAL_H
#include <iostream>

int gcd(int x, int y);
void reduction(int &x, int &y);

class Rational
{
public:
    int numerator;
    int denominator;

    Rational();
    Rational(int n, int d);
    explicit Rational(int n);
    Rational(const Rational &r);

    friend std::ostream& operator << (std::ostream &ofs, const Rational &r);
};

Rational operator + (const Rational &r1,const Rational &r2);
Rational operator - (const Rational &r1,const Rational &r2);
Rational operator * (const Rational &r1,const Rational &r2);
Rational operator / (const Rational &r1, const Rational &r2);
bool operator ==(const Rational &r1, const Rational &r2);
bool operator !=(const Rational &r1, const Rational &r2);

#endif //LAB1_RATIONAL_H
