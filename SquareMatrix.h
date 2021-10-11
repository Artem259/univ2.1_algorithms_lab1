//
// Created by Artem Poliakov on 11.10.2021.
//

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include "SquareMatrix.h"

template <class T>
class SquareMatrix
{
private:
    unsigned dim;
    std::vector<std::vector<T>> matrix;
public:
    explicit SquareMatrix(unsigned N);
    void resize(unsigned N);

    template <class T1>
    friend std::ostream& operator <<(std::ostream &ofs, const SquareMatrix<T1> &matrix);
};

//---------------------------------------------------------------------------------------------------------------//

template <class T>
SquareMatrix<T>::SquareMatrix(unsigned int N)
{
    matrix = {};
    dim = 0;
    this->resize(N);
}

template <class T>
void SquareMatrix<T>::resize(unsigned int N)
{
    matrix.resize(N);
    for(auto &row: matrix)
    {
        row.resize(N);
    }
    dim = N;
}

//---------------------------------------------------------------------------------------------------------------//

template <class T>
std::ostream& operator <<(std::ostream &ofs, const SquareMatrix<T> &matrix)
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


#endif
