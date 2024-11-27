#pragma once

#include <iostream>
#include <vector>
#include <deque>


template<typename N>
class Vector
{
    private:
        std::vector<N> values;
        unsigned int    size;
    public:
        Vector();
        ~Vector();
        Vector(Vector const &src);
        Vector  &operator=(Vector const &src);

        unsigned int    const getsize();
        void    printContent();
        void    addValue();
}

template<typename N>
class Matrix
{
    private:
        std::vector<std::vector<N>> values;
        unsigned int    shape;
    public:
        Matrix();
        ~Matrix();
        Matrix(Matrix const &src);
        Matrix  &operator=(Matrix const &src);

        unsigned int    const getshape();
        bool    const   isSquare();
        void    printContent() const;
        void    addValue();
}
