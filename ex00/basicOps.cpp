#include "../Utils.hpp"

template <typename C, typename N>
C<N>   add(C<N> objA, C<N> objB)
{
    valuesA = objA.getValues();
    valuesB = objB.getValues();
    
    size_t  size = objA.getSize();
    if (size == objB.getSize())
    {
        std::vector<N>  buff = std::vector<N>(size);
        for (size_t i = 0; i < size; i++)
            buff[i] = valuesA[i] + valuesB[i];
    }
    else
        std::cout << "PROBLEM" << std::endl;


}