#pragma once

#include "../Vector.hpp"
#include "../Matrix.hpp"

template <typename N>
N   lerp(N const &u, N const &v, double const &t)
{
    return std::fma(v - u, t, u);
}

template <typename N>
Vector<N>   lerp(Vector<N> const &u, Vector<N> const &v, double const &t)
{
    std::vector<N> uValues = u.getValues();
    std::vector<N> vValues = v.getValues();

    size_t  size = uValues.size();
    Vector<N> ret(u);
    if (vValues.size() != size)
        throw std::out_of_range("Error: lerp: Vector sizes do not match");

    for (size_t i = 0; i < size; i++)
        ret[i] = std::fma(vValues[i] - uValues[i], t, uValues[i]);

    return ret;
}

template <typename N>
Matrix<N>   lerp(Matrix<N> const &u, Matrix<N> const &v, double const &t)
{
    std::vector<N> uValues = u.getValues();
    std::vector<N> vValues = v.getValues();

    size_t  size = uValues.size();
    Matrix<N> ret(u);
    if (vValues.size() != size || u.getShape() != v.getShape())
        throw std::out_of_range("Error: lerp: Matrix dimensions do not match");

    for (size_t i = 0; i < size; i++)
        ret[i] = std::fma(vValues[i] - uValues[i], t, uValues[i]);

    return ret;
}

// template <typename C>
// C   lerp(C const &u, C const &v, double const &t)
// {
//     using N = typename C::ValueType;

//     std::vector<N> uValues = u.getValues();
//     std::vector<N> vValues = v.getValues();

//     size_t  size = uValues.size();
//     C ret(u);

//     for (size_t i = 0; i < size; i++)
//         ret[i] = std::fma(vValues[i] - uValues[i], t, uValues[i]);

//     return ret;
// }
