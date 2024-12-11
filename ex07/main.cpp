#include "../Vector.hpp"
#include "../Matrix.hpp"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    Matrix<double> m(3, 2, 1, 2, 3, 4, 5, 6);
    Matrix<double> k(2, 3, 1, 1, 2, 2, 3, 3);
    m.printValues();
    k.printValues();

    Vector<double> u(1, 1, 1);
    Vector<double> v = m.getCol(1);
    u.printValues();
    v.printValues();

    std::cout << std::endl << " -- VEC -- " << std::endl;

    Vector<double> vres = k.mul_vec(u);
    vres.printValues();

    std::cout << std::endl << " -- MAT -- " << std::endl;
    Matrix<double> mres = m.mul_mat(k);
    mres.printValues();

    return (0);
}