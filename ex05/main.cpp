#include "../Vector.hpp"
#include "Cosine.tpp"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    Vector<double> u(0, 0, 0);
    Vector<double> v(0, 1, 0);
    u.printValues();
    v.printValues();

    double ret = angle_cos<double>(u, v);
    std::cout << "COS: " << ret << std::endl;

    return (0);
}