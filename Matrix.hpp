#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <cmath>

template <typename N>
class Matrix
{
    private:
        std::vector<N> values;
        std::array<size_t, 2> shape;
        size_t  size;
    public:
        using ValueType = N;
        Matrix();

        template <typename... Args>
        Matrix(size_t columns, size_t rows, Args... args);

        Matrix(Matrix const &src);
        Matrix  &operator=(Matrix const &src);
        N  &operator[](size_t const i);

        ~Matrix();

        size_t  getSize() const;
        std::array<size_t, 2>  getShape() const;
        void    reshape(size_t columns, size_t rows);
        std::vector<N> const &getValues() const;
        void    setValues(std::vector<N> const &src);
        bool    isSquare() const;
        void    printValues() const;

        void   add(Matrix const &obj);
        void   sub(Matrix const &obj);
        void   scl(N const &scalar);
};

#include "Matrix.tpp"
