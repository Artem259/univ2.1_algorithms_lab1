#include <iostream>
#include <ctime>
#include <chrono>
#include <random>
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

    srand(time(nullptr));
    input.emplace_back(1000,1000);
    output.emplace_back(10,10);
    for(auto u=0;u<1000; u++)
    {
        for(auto y=0;y<1000; y++)
        {
            input.back()(u,y)={rand(), rand()};
        }
    }


    RationalMatrix res(1,1);
    size_t len = input.size();
    for(size_t i=0; i<len; i++)
    {
/*
        auto start = std::chrono::high_resolution_clock::now();
        for(auto h=0; h<10000; h++)
        {
            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            std::cout<<time.count()<<std::endl;
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
*/
        std::cout<<"Test "<<i<<": ";

        auto start = std::chrono::high_resolution_clock::now();
        res = input[i].inverse();
        auto end = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);


        if(res != output[i])
        {
            std::cout<<"Failed ("<<time.count()<<" ms)\n";
            return false;
        }
        else
        {
            std::cout<<"Passed ("<<time.count()<<" ms)\n";
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
