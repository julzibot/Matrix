#pragma once

#include "Matrix.hpp"


//*****   CONSTR, ASSIGN, DESTR   *****/

template <typename N>
Matrix<N>::Matrix() : values{}
{ 
    this->size = 0;
    this->shape[0] = 0;
    this->shape[0] = 0;
    std::cout << "empty matrix created" << std::endl;
}

template <typename N>
template <typename... Args>
Matrix<N>::Matrix(size_t rows, size_t columns, Args... args) : values{static_cast<N>(args)...}
{
    this->shape[0] = rows;
    this->shape[1] = columns;
    this->size = this->values.size();

    if (this->size != this->shape[0] * this->shape[1])
    {
        std::cout << "PROBLEM !" << std::endl;
        return;
    }
}

template <typename N>
Matrix<N>::Matrix(size_t rows, size_t columns, std::vector<N> values) : values{values}
{
    this->shape[0] = rows;
    this->shape[1] = columns;
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
{
    // std::cout << "matrix destroyed" << std::endl;
}


//*****   GET/PRINT VALUES + SIZE/SHAPE   *****/

template <typename N>
size_t Matrix<N>::getSize() const
{ return (this->values.size()); }

template <typename N>
std::array<size_t, 2> Matrix<N>::getShape() const
{ return (this->shape); }

template <typename N>
void    Matrix<N>::reshape(size_t rows, size_t columns)
{
    if (columns * rows == this->values.size())
    {
        this->shape[0] = rows;
        this->shape[1] = columns;
    }
    else
        std::cout << "BAD SHAPE !" << std::endl;
}

template <typename N>
bool Matrix<N>::isSquare() const
{
    if (this->shape[0] == this->shape[0])
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
    for (size_t i = 0; i < this->shape[0]; i++)
    {
        if (i > 0) std::cout << "     |";
        for (j = 0; j < this->shape[1]; j++)
        {
            std::cout << this->values[i * this->shape[1] + j];
            if (j < this->shape[1] - 1)
                std::cout << " ";
        }
        std::cout << "|" << std::endl;
    }
}

template <typename N>
Vector<N>   Matrix<N>::getCol(size_t j)
{
    size_t size = this->shape[0];
    std::vector<N>  values(size);
    for (size_t i = 0; i < size; i++)
        values[i] = this->values[j * size + i];
    return Vector<N>(values);
}

template <typename N>
Vector<N>   Matrix<N>::getRow(size_t k)
{
    size_t size = this->shape[1];
    std::vector<N>  values(size);
    for (size_t i = 0; i < size; i++)
        values[i] = this->values[i * this->shape[0] + k];
    return Vector<N>(values);
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

//*****   MATRIX MULT   *****/

template <typename N>
Vector<N>   Matrix<N>::mul_vec(Vector<N> vec)
{
    if (vec.getSize() != this->shape[1])
    {
        std::cout << "PROBLEM !" << std::endl;
        return Vector<N>(values);
    }
    size_t vecSize = this->shape[0];
    std::vector<N> values(vecSize, 0);
    for (size_t i = 0; i < vecSize; i++)
        for (size_t j = 0; j < this->shape[1]; j++)
            values[i] = std::fma(vec[j], this->values[std::fma(i, this->shape[1], j)], values[i]);
    return Vector<N>(values);
}

template <typename N>
Matrix<N>   Matrix<N>::mul_mat(Matrix<N> mat)
{
    if (mat.getShape()[0] != this->shape[1])
    {
        std::cout << "PROBLEM !" << std::endl;
        return Matrix<N>(*this);
    }
    size_t size = this->shape[0] * mat.getShape()[1];
    std::vector<N> values(size);
    for (size_t i = 0; i < this->shape[0]; i++)
    {
        for (size_t j = 0; j < mat.getShape()[1]; j++)
        {
            size_t index = std::fma(i, mat.getShape()[1], j);
            for (size_t k = 0; k < this->shape[1]; k++)
                values[index] = std::fma(this->values[std::fma(this->shape[1], i, k)], mat[std::fma(mat.getShape()[1], k, j)], values[index]);
        }
    }
    return Matrix<N>(mat.getShape()[1], this->shape[0], values);
}

//*****   TRACE   *****/

template <typename N>
N   Matrix<N>::trace()
{
    if (this->shape[0] == this->shape[1])
    {
        size_t  size = this->shape[0] * this->shape[1];
        N res = 0;
        for (size_t i = 0; i < size; i += this->shape[1] + 1)
            res += this->values[i];
        return res;
    }
    else
    {
        std::cout << "PROBLEM !" << std::endl;
        return 0;
    }
}

//*****   TRANSPOSE   *****/

template<typename N>
void    Matrix<N>::transpose()
{
    std::vector<N> tValues(this->size, 0);

    size_t ColNum = this->shape[1];
    size_t RowNum = this->shape[0];
    for (size_t i = 0; i < RowNum; i++)
        for (size_t j = 0; j < ColNum; j++)
            tValues[j * RowNum + i] = this->values[i * ColNum + j];
    
    this->values = tValues;
    this->shape[1] = RowNum;
    this->shape[0] = ColNum;
}

//*****   ROW-ECHELON   *****/

template <typename N>
bool    Matrix<N>::order_ref()
{
    bool ret = false;
    size_t  toSortRowIndex = 0;
    N temp;
    for (size_t i = 0; i < this->shape[1]; i++)
    {
        for (size_t j = toSortRowIndex; j < this->shape[0]; j++)
        {
            if (this->values[j * this->shape[1] + i] != 0)
            {
                if (j > toSortRowIndex)
                {
                    for (size_t k = 0; k < this->shape[1]; k++)
                    {
                        ret = true;
                        temp = this->values[j * this->shape[1] + k];
                        this->values[j * this->shape[1] + k] = this->values[toSortRowIndex * this->shape[1] + k];
                        this->values[toSortRowIndex * this->shape[1] + k] = temp;
                    }
                }
                toSortRowIndex += 1;
                if (toSortRowIndex == this->shape[0])
                    return ret;
            }
        }
    }
    return ret;
}

template <typename N>
Matrix<N>    Matrix<N>::row_echelon()
{
    Matrix<N>   ret(*this);
    ret.order_ref();
    
    N rowPivot;
    N rowCombinationFactor;
    bool    reordered_mat = true;
    size_t pivotIndex = 0;
    std::vector<N> values(ret.getSize());
    for (size_t i = 0; i < this->shape[0]; i++)
    {
        if (reordered_mat)
            values = ret.getValues();
        rowPivot = 0;
        for (size_t j = pivotIndex; j < this->shape[1]; j++)
        {
            if (rowPivot == 0 && values[i * this->shape[1] + j] != 0)
            {
                rowPivot = values[i * this->shape[1] + j];
                pivotIndex = j;
            }
            if (rowPivot != 0)
                values[i * this->shape[1] + j] /= rowPivot;
        }
        for (size_t k = 0; k < this->shape[0]; k++)
        {
            if (k != i && values[k * this->shape[1] + pivotIndex] != 0 && rowPivot != 0)
            {
                rowCombinationFactor = values[k * this->shape[1] + pivotIndex];
                for (size_t l = pivotIndex; l < this->shape[1]; l++)
                    values[k * this->shape[1] + l] -= rowCombinationFactor * values[i * this->shape[1] + l];
            }
        }
        ret.setValues(values);
        reordered_mat = ret.order_ref();
        // std::cout << "------" << std::endl;
        // ret.printValues();

    }
    return ret;
}


//*****   TRANSPOSE   *****/

template <typename N>
N Matrix<N>::determinant()
{
    if (this->shape[0] != this->shape[1])
    {
        std::cout << "PROBLEM !" << std::endl;
        return 0;
    }
    size_t dim = this->shape[0];

    
}
