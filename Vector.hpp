#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <cmath>
#include <algorithm>

template <typename N>
class Vector
{
    private:
        std::vector<N> values;
        size_t    size;
    public:
        using ValueType = N;
        Vector();
        
        template <typename... Args>
        Vector(Args... args);
        Vector(std::vector<N> values);

        Vector(Vector const &src);
        Vector  &operator=(Vector const &src);
        N  &operator[](size_t const i);

        ~Vector();

        size_t  getSize() const;
        std::array<size_t, 2>  getShape() const;
        std::vector<N> const &getValues() const;
        void    setValues(std::vector<N> const &src);
        void    printValues() const;

        void   add(Vector const &obj);
        void   sub(Vector const &obj);
        void   scl(N const &scalar);

        N   dot(Vector const &obj);
        N   norm_1();
        N   norm();
        N   norm_inf();
};

#include "Vector.tpp"
