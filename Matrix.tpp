#pragma once

#include "Matrix.hpp"


//*****   CONSTR, ASSIGN, DESTR   *****/

template <typename N>
Matrix<N>::Matrix() : values{}
{ 
    this->size = 0;
    this->shape[0] = 0;
    this->shape[1] = 0;
    std::cout << "empty matrix created" << std::endl;
}

template <typename N>
template <typename... Args>
Matrix<N>::Matrix(size_t columns, size_t rows, Args... args) : values{static_cast<N>(args)...}
{
    this->shape[0] = static_cast<size_t>(columns);
    this->shape[1] = static_cast<size_t>(rows);
    this->size = this->values.size();

    if (this->size != this->shape[0] * this->shape[1])
    {
        std::cout << "PROBLEM !" << std::endl;
        return;
    }
}

template <typename N>
Matrix<N>::Matrix(Matrix const &src) : values(src.values), shape(src.shape), size(src.size)
{}

template <typename N>
Matrix<N>  &Matrix<N>::operator=(Matrix<N> const &src)
{
    std::vector<N> cpy = src.getValues();
    size_t size = cpy.size();
    this->values = std::vector<N> (size);
    for (size_t i = 0; i < size; i++)
        this->values[i] = cpy[i];
    this->shape = src.getShape();
    return (*this);
}

template <typename N>
N  &Matrix<N>::operator[](size_t const i)
{
    if (!this->size)
        std::cout << "Error: empty array" << std::endl;
    else if (i > this->size - 1)
        std::cout << "Error: out of bounds" << std::endl;
    return (this->values[i]);
}

template <typename N>
Matrix<N>::~Matrix()
{ std::cout << "matrix destroyed" << std::endl;}


//*****   GET/PRINT VALUES + SIZE/SHAPE   *****/

template <typename N>
size_t Matrix<N>::getSize() const
{ return (this->values.size()); }

template <typename N>
std::array<size_t, 2> Matrix<N>::getShape() const
{ return (this->shape); }

template <typename N>
void    Matrix<N>::reshape(size_t columns, size_t rows)
{
    if (columns * rows == this->values.size())
    {
        this->shape[0] = columns;
        this->shape[1] = rows;
    }
    else
        std::cout << "BAD SHAPE !" << std::endl;
}

template <typename N>
bool Matrix<N>::isSquare() const
{
    if (this->shape[0] == this->shape[1])
        return true;
    return false;
}

template <typename N>
std::vector<N> const &Matrix<N>::getValues() const
{ return (this->values); }

template <typename N>
void    Matrix<N>::setValues(std::vector<N> const &src)
{ this->values = std::vector<N>(src); }

template <typename N>
void    Matrix<N>::printValues() const
{
    std::cout << "mat: |";
    size_t j = 0;
    for (size_t i = 0; i < this->shape[1]; i++)
    {
        if (i > 0) std::cout << "     |";
        for (j = 0; j < this->shape[0]; j++)
        {
            std::cout << this->values[i * this->shape[0] + j];
            if (j < this->shape[0] - 1)
                std::cout << " ";
        }
        std::cout << "|" << std::endl;
    }
}


//*****   ADD, SUB, SCALE   *****/

template <typename N>
void   Matrix<N>::add(Matrix<N> const &obj)
{
    size_t  size = obj.getSize();
    std::vector<N> values = obj.getValues();
    if (size == this->size)
    {
        for (size_t i = 0; i < size; i++)
            this->values[i] += values[i];
    }
    else
        std::cout << "PROBLEM" << std::endl;
}

template <typename N>
void   Matrix<N>::sub(Matrix<N> const &obj)
{
    size_t  size = obj.getSize();
    std::vector<N> values = obj.getValues();
    if (size == this->size)
    {
        for (size_t i = 0; i < size; i++)
            this->values[i] -= values[i];
    }
    else
        std::cout << "PROBLEM" << std::endl;
}

template <typename N>
void   Matrix<N>::scl(N const &scalar)
{
    for (size_t i = 0; i < this->size; i++)
        this->values[i] *= scalar;
}
