//
// Created by Artem Poliakov on 11.10.2021.
//

#ifndef MATRIX_H
#define MATRIX_H

#include "rational.h"
#include <vector>

class SquareMatrix
{
private:
    unsigned dim;
    std::vector<std::vector<Rational>> matrix;
public:
    explicit SquareMatrix(unsigned N);
    void resize(unsigned N);
};


#endif
