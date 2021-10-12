//
// Created by Artem Poliakov on 12.10.2021.
//

#include <cassert>
#include "RationalMatrix.h"

RationalMatrix::RationalMatrix(const size_t &_rows, const size_t &_cols)
{
    matrix = {};
    rows = 0;
    cols = 0;
    this->resize(_rows, _cols);
}
void RationalMatrix::resize(const size_t &_rows, const size_t &_cols)
{
    matrix.resize(_rows);
    for(auto &row: matrix)
    {
        row.resize(_cols);
    }
    rows = _rows;
    cols = _cols;
}
void RationalMatrix::swapRows(const size_t &row1, const size_t &row2)
{
    assert(row1<rows && row2<rows);
    swap(matrix[row1], matrix[row2]);
}
std::vector<Rational>& RationalMatrix::operator ()(const size_t &row)
{
    assert(row<rows);
    return matrix[row];
}
Rational& RationalMatrix::operator ()(const size_t &row, const size_t &col)
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

std::vector<Rational> operator +(const std::vector<Rational> &row1, const Rational &k)
{
    size_t len = row1.size();
    std::vector<Rational> res(len);
    for(size_t i=0; i<len; i++)
    {
        res[i] = row1[i]+k;
    }
    return res;
}
std::vector<Rational> operator -(const std::vector<Rational> &row1, const Rational &k)
{
    return row1+(k*Rational{-1,1});
}
std::vector<Rational> operator *(const std::vector<Rational> &row1, const Rational &k)
{
    size_t len = row1.size();
    std::vector<Rational> res(len);
    for(size_t i=0; i<len; i++)
    {
        res[i] = row1[i]*k;
    }
    return res;
}
std::vector<Rational> operator /(const std::vector<Rational> &row1, const Rational &k)
{
    size_t len = row1.size();
    std::vector<Rational> res(len);
    for(size_t i=0; i<len; i++)
    {
        res[i] = row1[i]/k;
    }
    return res;
}
std::vector<Rational> operator +(const std::vector<Rational> &row1, const std::vector<Rational> &row2)
{
    size_t len = row1.size();
    assert(row2.size()==len);
    std::vector<Rational> res(len);
    for(size_t i=0; i<len; i++)
    {
        res[i] = row1[i]+row2[i];
    }
    return res;
}
std::vector<Rational> operator -(const std::vector<Rational> &row1, const std::vector<Rational> &row2)
{
    return row1+(row2*Rational{-1,1});
}
std::vector<Rational> operator *(const std::vector<Rational> &row1, const std::vector<Rational> &row2)
{
    size_t len = row1.size();
    assert(row2.size()==len);
    std::vector<Rational> res(len);
    for(size_t i=0; i<len; i++)
    {
        res[i] = row1[i]*row2[i];
    }
    return res;
}
std::vector<Rational> operator /(const std::vector<Rational> &row1, const std::vector<Rational> &row2)
{
    size_t len = row1.size();
    assert(row2.size()==len);
    std::vector<Rational> res(len);
    for(size_t i=0; i<len; i++)
    {
        res[i] = row1[i]/row2[i];
    }
    return res;
}