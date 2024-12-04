#pragma once

#include "Utils.hpp"

//*****   CONSTRUCTS, CPY, ASSIGN, DESTR   *****/

/*  VEC  */

template <typename N>
Vector<N>::Vector() : values{}, size(0)
{
    this->shape[0] = 0;
    this->shape[1] = 0; 
    std::cout << "empty vector created" << std::endl;
}

template <typename N>
template <typename... Args>
Vector<N>::Vector(Args... args) : values{static_cast<N>(args)...}, size(sizeof...(args)) 
{
    this->shape[0] = this->size;
    this->shape[1] = 1;
}

template <typename N>
Vector<N>::Vector(Vector const &src) : values(src.values), size(src.size), shape(src.shape)
{}

template <typename N>
Vector<N>  &Vector<N>::operator=(Vector<N> const &src)
{
    std::vector<N> cpy = src.getValues();
    size_t size = cpy.size();
    this->values = std::vector<N> (size);
    for (size_t i = 0; i < size; i++)
        this->values[i] = cpy[i];
    this->size = size;
    return (*this);
}

template <typename N>
Vector<N>::~Vector()
{ std::cout << "vector destroyed" << std::endl;}


/*  MATRIX  */

template <typename N>
Matrix<N>::Matrix() : values{}
{ 
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

    if (this->values.size() != this->shape[0] * this->shape[1])
    {
        std::cout << "PROBLEM !" << std::endl;
        return;
    }
}

template <typename N>
Matrix<N>::Matrix(Matrix const &src) : values(src.values), shape(src.shape)
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
Matrix<N>::~Matrix()
{ std::cout << "matrix destroyed" << std::endl;}





//*****   GET/PRINT VALUES + SIZE/SHAPE   *****/

/*  VEC  */

template <typename N>
size_t Vector<N>::getSize() const
{ return (this->size); }

template <typename N>
std::array<size_t, 2> Vector<N>::getShape() const
{ return (this->shape); }

template <typename N>
std::vector<N> const &Vector<N>::getValues() const
{ return (this->values); }

template <typename N>
void    Vector<N>::setValues(std::vector<N> const &src)
{ this->values = std::vector<N>(src); }

template <typename N>
void    Vector<N>::printValues() const
{
    std::cout << "vec: [";
    for (size_t i = 0; i < this->values.size(); i++)
    {
        std::cout << this->values[i];
        if (i < this->values.size() - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

/*  MATRIX  */

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
