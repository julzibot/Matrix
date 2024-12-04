#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <array>

template <typename N>
class Vector
{
    private:
        std::vector<N> values;
        size_t    size;
    public:
        Vector();
        template <typename... Args>
        Vector(Args... args);

        Vector(Vector const &src);
        Vector  &operator=(Vector const &src);

        ~Vector();

        size_t  getSize() const;
        std::vector<N> const &getValues() const;
        void    printValues() const;
};


template <typename N>
class Matrix
{
    private:
        std::vector<N> values;
        std::array<size_t, 2> shape;
    public:
        Matrix();
        template <typename... Args>
        Matrix(size_t columns, size_t rows, Args... args);

        Matrix(Matrix const &src);
        Matrix  &operator=(Matrix const &src);

        ~Matrix();

        size_t  getSize() const;
        std::array<size_t, 2>  getShape() const;
        void    reshape(size_t columns, size_t rows);
        std::vector<N> const &getValues() const;
        bool    isSquare() const;
        void    printValues() const;
};

#include "Utils.tpp"
