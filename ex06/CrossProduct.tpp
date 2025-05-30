#pragma once

#include "../Vector.hpp"

template <typename N>
Vector<N>   cross_product(Vector<N> const &u, Vector<N> const &v)
{
    Vector<N>   ret(u);
    if (u.getSize() != 3 || v.getSize() != 3)
    {
        std::cerr << "Error: cross product: wrong Vector dimensions" << std::endl;
        return ret;
    }
    std::vector<N> uValues = u.getValues();
    std::vector<N> vValues = v.getValues();
    ret[0] = std::fma(uValues[1], vValues[2], -uValues[2] * vValues[1]);
    ret[1] = std::fma(uValues[0], vValues[2], -uValues[2] * vValues[0]);
    ret[2] = std::fma(uValues[0], vValues[1], -uValues[1] * vValues[0]);

    return ret;
}
