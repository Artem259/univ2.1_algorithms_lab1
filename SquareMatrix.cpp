//
// Created by Artem Poliakov on 11.10.2021.
//

#include "SquareMatrix.h"

SquareMatrix::SquareMatrix(unsigned int N)
{
    matrix = {};
    dim = 0;
    this->resize(N);
}

void SquareMatrix::resize(unsigned int N)
{
    matrix.resize(N);
    for(auto &row: matrix)
    {
        row.resize(N);
    }
    dim = N;
}