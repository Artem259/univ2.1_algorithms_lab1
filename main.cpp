#include <iostream>
#include "RationalMatrix.h"


int main()
{
    RationalMatrix b(2,3);
    b(0,0).denominator = 2;
    b(1,2).numerator = 4;
    std::cout<<b<<std::endl;
    b.swapRows(0,1);
    std::cout<<b<<std::endl;
    return 0;
}
