#include "../Vector.hpp"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    Vector<int> a = Vector<int>(1, 2, 3);
    a.printValues();
    
    int   norm1 = a.norm_1();
    int   norm = a.norm();
    int   normInf = a.norm_inf();

    std::cout << " NORMS: " << norm1 << ", " << norm << ", " << normInf << std::endl;

    return (0);
}