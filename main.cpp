#include <iostream>
#include "RationalMatrix.h"

bool Test()
{
    std::vector<RationalMatrix> input;
    std::vector<RationalMatrix> output;

    size_t len = input.size();
    for(size_t i=0; i<len; i++)
    {
        if()
    }
}

int main()
{
    RationalMatrix b({
                             {Rational{1,2},Rational{3,4},Rational{0}},
                             {Rational{7,8},Rational{-7,13},Rational{1,3}},
                             {Rational{0},Rational{-7,9},Rational{-4,5}}
    });
    RationalMatrix c = b.inverse();
    std::cout<<c<<std::endl;
    return 0;
}
