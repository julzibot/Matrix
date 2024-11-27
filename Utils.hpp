#pragma once

#include <iostream>
#include <vector>
#include <deque>


template<typename N>
class Vector
{
    private:
        std::vector<N> values;
        unsigned int    size;
    public:
        Vector();
        Vector(N )
        ~Vector();
        Vector(Vector const &src);
        Vector  &operator=(Vector const &src);

        unsigned int    const getsize();
        void    printContent();

}

class Matrix
{
    private:

    public:

}
