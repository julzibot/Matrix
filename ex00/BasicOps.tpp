#pragma once

#include "../Utils.hpp"

template <typename C>
C   add(C const &objA, C const &objB)
{
    using N = typename C::ValueType;

    std::vector<N> valuesA = objA.getValues();
    std::vector<N> valuesB = objB.getValues();
    C ret(objA);

    std::array<size_t, 2>  shape = objA.getShape();
    if (shape == objB.getShape())
    {
        size_t size = shape[0] * shape[1];
        std::vector<N>  buff(size);
        for (size_t i = 0; i < size; i++)
            buff[i] = valuesA[i] + valuesB[i];
        ret.setValues(buff);
    }
    else
        std::cout << "PROBLEM" << std::endl;
    return ret;
}

template <typename C>
C   sub(C const &objA, C const &objB)
{
    using N = typename C::ValueType;

    std::vector<N> valuesA = objA.getValues();
    std::vector<N> valuesB = objB.getValues();
    C ret(objA);

    std::array<size_t, 2>  shape = objA.getShape();
    if (shape == objB.getShape())
    {
        size_t size = shape[0] * shape[1];
        std::vector<N>  buff(size);
        for (size_t i = 0; i < size; i++)
            buff[i] = valuesA[i] - valuesB[i];
        ret.setValues(buff);
    }
    else
        std::cout << "PROBLEM" << std::endl;
    return ret;
}

template <typename C, typename S>
C   scale(C const &obj, S const scalar)
{
    using N = typename C::ValueType;

    N nscalar = static_cast<N>(scalar);
    std::vector<N> values = obj.getValues();
    C ret(obj);

    size_t size = obj.getSize();
    std::vector<N>  buff(size);
    for (size_t i = 0; i < size; i++)
        buff[i] = values[i] * nscalar;
    ret.setValues(buff);
    
    return ret;
}
