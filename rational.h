//
// Created by Pavel on Kilko 9/20/2021.
//

#ifndef LAB1_RATIONAL_H
#define LAB1_RATIONAL_H

int gcd(int x, int y);
void reduction(int &x, int &y);

class Rational
{
public:
    int numerator;
    int denominator;

    Rational();

    explicit Rational(int n, int d = 1);

    void print() const;
};

Rational operator + (const Rational &r1,const Rational &r2);
Rational operator - (const Rational &r1,const Rational &r2);
Rational operator * (const Rational &r1,const Rational &r2);
Rational operator / (const Rational &r1, const Rational &r2);

#endif //LAB1_RATIONAL_H
