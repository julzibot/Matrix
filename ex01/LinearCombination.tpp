#pragma once

#include "../Vector.hpp"

template <typename N>
Vector<N>   linear_combination(std::vector<Vector<N>> const &vecs, std::vector<N> const &coeffs)
{
    size_t vecSize = vecs[0].getSize();
    Vector<N> ret(std::vector<N>(vecSize, 0));
    for (size_t j = 0; j < vecs.size(); j++)
    {
        if (vecs[j].getSize() != vecSize)
            throw std::out_of_range("Error: LinearCombination: Vector sizes are not equal");
    }

    size_t j;
    for (size_t i = 0; i < vecSize; i++)
    {
        for (j = 0; j < vecs.size(); j++)
            ret[i] = std::fma(vecs[j].getValues()[i], coeffs[j], ret[i]);
    }
    return ret;
}
