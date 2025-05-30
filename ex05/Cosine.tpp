#pragma once

#include "../Vector.hpp"

template <typename N>
N   angle_cos(Vector<N> u, Vector<N> v)
{
    if (!u.norm() || !v.norm())
    {
        std::cerr << "Error: cosine: null vector as input" << std::endl;
        return std::nan("");
    }
    return u.dot(v) / (u.norm() * v.norm());
}
