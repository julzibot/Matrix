#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <cmath>
#include "Vector.hpp"

// class Vector;

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
        Matrix(size_t rows, size_t columns, Args... args);
        Matrix(size_t rows, size_t columns, std::vector<N> values);

        Matrix(Matrix const &src);
        Matrix  &operator=(Matrix const &src);
        N  &operator[](size_t const i);

        ~Matrix();

        size_t  getSize() const;
        std::array<size_t, 2>  getShape() const;
        void    reshape(size_t rows, size_t columns);
        std::vector<N> const &getValues() const;
        Vector<N>   getRow(size_t j);
        Vector<N>   getCol(size_t k);

        void    setValues(std::vector<N> const &src);
        bool    isSquare() const;
        void    printValues() const;

        void   add(Matrix const &obj);
        void   sub(Matrix const &obj);
        void   scl(N const &scalar);

        Vector<N>   mul_vec(Vector<N> vec);
        Matrix<N>   mul_mat(Matrix<N> mat);
        N   trace();
        
        void    transpose();
        bool    order_ref();
        Matrix<N>    row_echelon();
        N determinant();
        Matrix<N>    inverse();
};

#include "Matrix.tpp"
