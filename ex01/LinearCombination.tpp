#pragma once

#include "../Vector.hpp"

template <typename N>
N recursive_fma(std::vector<Vector<N>> const &vecs, std::vector<N> const &coeffs, size_t index, size_t const &coord)
{
    if (index == vecs.size() - 1)
        return vecs[index].getValues()[coord] * coeffs[index];
    else
        return std::fma(vecs[index].getValues()[coord], coeffs[index], recursive_fma(vecs, coeffs, index + 1, coord));
}

template <typename N>
Vector<N>   linear_combination(std::vector<Vector<N>> const &vecs, std::vector<N> const &coeffs)
{
    size_t vecSize = vecs[0].getSize();
    Vector<N> ret(vecs[0]);
    for (size_t i = 0; i < vecSize; i++)
        ret[i] = recursive_fma(vecs, coeffs, 0, i);
    
    return ret;
}
