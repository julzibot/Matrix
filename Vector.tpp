#pragma once

#include "Vector.hpp"

//*****   CONSTR, ASSIGN, DESTR   *****/

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
{}

template <typename N>
Vector<N>::Vector(std::vector<N> values) : values(values), size(values.size())
{}

template <typename N>
Vector<N>::Vector(Vector const &src) : values(src.values), size(src.size)
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
N  &Vector<N>::operator[](size_t const i)
{
    if (!this->size)
        std::cout << "Error: empty array" << std::endl;
    else if (i > this->size - 1)
        std::cout << "Error: out of bounds" << std::endl;
    return (this->values[i]);
}

template <typename N>
Vector<N>::~Vector()
{
    // std::cout << "vector destroyed" << std::endl;
}


//*****   GET/PRINT VALUES + SIZE/SHAPE   *****/

template <typename N>
size_t Vector<N>::getSize() const
{ return (this->size); }

// template <typename N>
// std::array<size_t, 2> Vector<N>::getShape() const
// { return (this->shape); }

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


//*****   ADD, SUB, SCALE   *****/

template <typename N>
void   Vector<N>::add(Vector<N> const &obj)
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
void   Vector<N>::sub(Vector<N> const &obj)
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
void   Vector<N>::scl(N const &scalar)
{
    for (size_t i = 0; i < this->size; i++)
        this->values[i] *= scalar;
}


//*****   DOT   *****/

template <typename N>
N   Vector<N>::dot(Vector<N> const &obj)
{
    if (obj.getSize() == this->size)
    {
        N ret = 0;
        std::vector<N> objValues = obj.getValues();
        for (size_t i = 0; i < this->size; i++)
            ret = std::fma(this->values[i], objValues[i], ret);
        return ret;
    }
    else
    {
        std::cout << "PROBLEM" << std::endl;
        return static_cast<N>(0);
    }
}

//*****   NORMS   *****/

template <typename N>
N   Vector<N>::norm_1()
{
    N ret = 0;
    for (size_t i = 0; i < this->size; i++)
        ret += this->values[i];
    return ret;
}

template <typename N>
N   Vector<N>::norm()
{
    N ret = 0;
    for (size_t i = 0; i < this->size; i++)
        ret += pow(this->values[i], 2);
    return pow(ret, 0.5);
}

template <typename N>
N   Vector<N>::norm_inf()
{
    N ret = 0;
    for (size_t i = 0; i < this->size; i++)
    {
        if (this->values[i] > ret)
            ret = this->values[i];
    }
    return ret;
}
