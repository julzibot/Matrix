#include "../Vector.hpp"
#include "../Matrix.hpp"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    Matrix<double> m(3, 3, 1, 0, 4, 0, 1, 0, 0, 5, 0);
    // Matrix<double> m(3, 3, 1, 0, 0, 0, 1, 0, 0, 0, 1);
    m.printValues();

    Matrix<double> inv = m.inverse();
    inv.printValues();

    return (0);
}