#include <iostream>
#include "SquareMatrix.h"
#include "rational.h"

int main()
{
    Rational a;
    SquareMatrix<Rational> b(3);
    std::cout<<b;
    return 0;
}
