#include "../Vector.hpp"
#include "CrossProduct.tpp"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    try
    {
        Vector<double> u(1, 2, 0);
        Vector<double> v(-1, 1, 3);
        u.printValues();
        v.printValues();

        Vector<double> ret = cross_product<double>(u, v);
        ret.printValues();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}