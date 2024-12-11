#include "../Vector.hpp"
#include "../Matrix.hpp"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    Matrix<double> m(2, 3, 1, 3, 5, 2, 4, 6);
    m.printValues();

    m.transpose();
    m.printValues();

    return (0);
}