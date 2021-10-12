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
    size_t rows, cols;
    std::vector<std::vector<Rational>> matrix;
public:
    explicit RationalMatrix(const size_t &_rows, const size_t &_cols);
    void resize(const size_t &_rows, const size_t &_cols);
    void swapRows(const size_t &row1, const size_t &row2);
    std::vector<Rational>& operator ()(const size_t &row);
    Rational& operator ()(const size_t &row, const size_t &col);

    friend std::ostream& operator <<(std::ostream &ofs, const RationalMatrix &matrix);
};

#endif