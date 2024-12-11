#include "../Vector.hpp"
#include "CrossProduct.tpp"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    Vector<double> u(1, 2, 0);
    Vector<double> v(-1, 1, 3);
    u.printValues();
    v.printValues();

    Vector<double> ret = cross_product<double>(u, v);
    ret.printValues();

    return (0);
}