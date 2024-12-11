#include "../Vector.hpp"
#include "../Matrix.hpp"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    Matrix<double> m(3, 4, 1, 2, 0, 0, 2, 4, 0, 0, -1, 2, 1, 1);
    m.printValues();
    std::cout << "RANK: " << m.rank() << std::endl << "---------";

    Matrix<double> n(4, 3, 8, 5, -2, 4, 7, 20, 7, 6, 1, 21, 18, 7);
    n.printValues();
    std::cout << "RANK: " << n.rank();

    return (0);
}