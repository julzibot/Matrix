#include "../Vector.hpp"
#include "../Matrix.hpp"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    Matrix<double> m(4, 5, 1, 2, 0, 8, 0, 0, 0, 0, 3, 0, 9, 0, 1, 3, 1, -2, 4, 0, 12, 1);
    // Matrix<double> m(3, 5, 8, 5, -2, 4, 28, 4, 2.5, 20, 4, -4, 8, 5, 1, 4, 17);
    // Matrix<double> m(2, 2, 1, 2, 2, 4);
    m.printValues();

    Matrix<double> n = m.row_echelon();
    n.printValues();

    return (0);
}