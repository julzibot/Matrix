#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

template <typename N>
class Vector
{
    private:
        std::vector<N> values;
        unsigned int    size;
    public:
        Vector();
        Vector(std::string const &values);
        ~Vector();
        Vector(Vector const &src);
        Vector  &operator=(Vector const &src);

        unsigned int  getSize();
        void    printValues();
        // void    addValue();

        std::vector<N> const &getValues();
};

// template <typename N>
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
//         void    printValues() const;
// };

#include "Utils.tpp"
