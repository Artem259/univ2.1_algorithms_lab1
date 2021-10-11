#include <iostream>
#include "SquareMatrix.h"
#include "rational.h"

int main()
{
    SquareMatrix<Rational> b(3);
    b(2,2).denominator = 2;
    b(0,0).numerator = 4;
    std::cout<<b;
    return 0;
}
