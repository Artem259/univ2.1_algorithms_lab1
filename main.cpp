#include <iostream>
#include <ctime>
#include <cmath>
#include "RationalMatrix.h"

bool Test()
{
    std::vector<RationalMatrix> input;
    std::vector<RationalMatrix> output;


    input.push_back(RationalMatrix{{
                    {{1,2},{3,4},{0,1}},
                    {{7,8},{-7,13},{1,3}},
                    {{0,1},{-7,9},{-4,5}}}});
    output.push_back(RationalMatrix{{
                    {{1384,1745},{8424,12215},{702,2443}},
                    {{1404,1745},{-5616,12215},{-468,2443}},
                    {{-273,349},{156,349},{-1485,1396}}}});


    clock_t start, stop;
    double time;
    RationalMatrix res(1,1);
    size_t len = input.size();
    for(size_t i=0; i<len; i++)
    {
        std::cout<<"Test "<<i<<": ";

        start = clock();
        res = input[i].inverse();
        stop = clock();
        time = (double)(stop-start)/CLOCKS_PER_SEC;
        if(time<0.01) time = 0.01;
        else time = std::round(time*100)/100;

        if(res != output[i])
        {
            std::cout<<"Failed ("<<time<<" ms)\n";
            return false;
        }
        else
        {
            std::cout<<"Passed ("<<time<<" ms)\n";
        }
    }
    std::cout<<"Testing passed\n";
    return true;
}

int main()
{
    Test();
    return 0;
}
