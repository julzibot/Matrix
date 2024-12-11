#include "../Vector.hpp"
#include "../Matrix.hpp"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    Matrix<double> m(3, 3, 8, 5, -2, 4, 7, 20, 7, 6, 1);
    // Matrix<double> m(3, 3, 1, 0, 0, 0, 1, 0, 0, 0, 1);
    m.printValues();

    Matrix<double> inv = m.inverse();
    inv.printValues();

    return (0);
}