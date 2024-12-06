#pragma once

#include "../Vector.hpp"
#include "../Matrix.hpp"

template <typename C>
C   lerp(C const &u, C const &v, double const &t)
{
    using N = typename C::ValueType;

    std::vector<N> uValues = u.getValues();
    std::vector<N> vValues = v.getValues();

    size_t  size = uValues.size();
    C ret(u);

    for (size_t i = 0; i < size; i++)
        ret[i] = std::fma(vValues[i] - uValues[i], t, uValues[i]);

    return ret;
}
