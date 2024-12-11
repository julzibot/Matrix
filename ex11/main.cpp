#include "../Vector.hpp"
#include "../Matrix.hpp"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    Matrix<double> m(4, 4, 2, 1, 3, 4, 0, -1, 2, 1, 3, 2, 0, 5, -1, 3, 2, 1);
    // Matrix<double> m(3, 5, 8, 5, -2, 4, 28, 4, 2.5, 20, 4, -4, 8, 5, 1, 4, 17);
    // Matrix<double> m(2, 2, 1, 2, 2, 4);
    m.printValues();

    std::cout << m.determinant() << std::endl;

    return (0);
}