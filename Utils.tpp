#pragma once

#include "Utils.hpp"

template <typename N>
Vector<N>::Vector() : values(new std::vector<N>), size(0)
{ std::cout << "empty vector created" << std::endl;}

template <typename N>
Vector<N>::Vector(std::string const &values)
{
    this->values = new std::vector<N>;
    std::istringstream  input(values);
    std::string buffer = "";
    N typeNum;
    double  num;
    for (this->size = 0; input >> buffer; this->size++)
    {
        num = stod(buffer);
        typeNum = static_cast<N>(num);
        this->values.push(typeNum);
    }
}

template <typename N>
Vector<N>::Vector(Vector const &src)
{
    std::vector<N> cpy = src.getValues;
    this->values = new std::vector<N> (cpy.size);
    for (int i = 0; i < cpy.size; i++)
        this->values[i] = cpy[i];
    this->size = cpy.size;
}

template <typename N>
Vector<N>::~Vector()
{ std::cout << "vector destroyed" << std::endl;}

template <typename N>
Vector<N>  &Vector<N>::operator=(Vector const &src)
{
    delete this->values;
    std::vector<N> cpy = src.getValues;
    this->values = new std::vector<N> (cpy.size);
    for (int i = 0; i < cpy.size; i++)
        this->values[i] = cpy[i];
    this->size = cpy.size;
    return (*this);
}

template <typename N>
unsigned int Vector<N>::getSize()
{
    return (this->size);
}

template <typename N>
void    Vector<N>::printValues()
{
    std::cout << "vec: [";
    for (int i = 0; i < this->values.size(); i++)
    {
        std::cout << this->values[i];
        if (i < this->values.size() - 1)
            std::cout << " ";
        else
            std::cout << "]" << std::endl;
    }
}

// void    addValue();

template <typename N>
std::vector<N> const &Vector<N>::getValues()
{
    return (this->values);
}

// template<typename N>
// class Matrix
// {
//     private:
//         std::vector<std::vector<N>> values;
//         unsigned int    shape;
//     public:
//         // Matrix();
//         Matrix(std::string const &values);
//         ~Matrix();
//         Matrix(Matrix const &src);
//         Matrix  &operator=(Matrix const &src);

//         unsigned int    const getshape();
//         bool    const   isSquare();
//         void    printContent() const;
// };