//
// Created by Artem Poliakov on 12.10.2021.
//

#include <cassert>
#include "RationalMatrix.h"

RationalMatrix::RationalMatrix(const unsigned &_rows, const unsigned &_cols)
{
    matrix = {};
    rows = 0;
    cols = 0;
    this->resize(_rows, _cols);
}
void RationalMatrix::resize(const unsigned &_rows, const unsigned &_cols)
{
    matrix.resize(_rows);
    for(auto &row: matrix)
    {
        row.resize(_cols);
    }
    rows = _rows;
    cols = _cols;
}
void RationalMatrix::swapRows(const unsigned &row1, const unsigned &row2)
{
    assert(row1<rows && row2<rows);
    swap(matrix[row1], matrix[row2]);
}
void RationalMatrix::multiplyRow(const unsigned &row, const Rational &k)
{

}
Rational& RationalMatrix::operator ()(const unsigned &row, const unsigned &col)
{
    assert(row<rows && col<cols);
    return matrix[row][col];
}

std::ostream& operator <<(std::ostream &ofs, const RationalMatrix &matrix)
{
    for(auto &row: matrix.matrix)
    {
        for(auto &col: row)
        {
            ofs << col << " ";
        }
        ofs << std::endl;
    }
    return ofs;
}