#pragma once

#include "../Vector.hpp"

template <typename N>
N   angle_cos(Vector<N> u, Vector<N> v)
{
    return u.dot(v) / (u.norm() * v.norm());
}
