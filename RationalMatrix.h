//
// Created by Artem Poliakov on 11.10.2021.
//

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include "Rational.h"

class RationalMatrix
{
private:
    unsigned rows, cols;
    std::vector<std::vector<Rational>> matrix;
public:
    explicit RationalMatrix(const unsigned &_rows, const unsigned &_cols);
    void resize(const unsigned &_rows, const unsigned &_cols);
    void swapRows(const unsigned &row1, const unsigned &row2);
    void multiplyRow(const unsigned &row, const Rational &k);
    Rational& operator ()(const unsigned &row, const unsigned &col);

    friend std::ostream& operator <<(std::ostream &ofs, const RationalMatrix &matrix);
};

#endif