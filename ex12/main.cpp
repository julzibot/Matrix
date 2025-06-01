#include "../Vector.hpp"
#include "../Matrix.hpp"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    try
    {
        Matrix<double> m(6, 6, 1, 4, 1, 1, 5, 1, 2, 2, 1, 2, 7, 2, 3, 11, 3, 3, 3, 1, 4, 1, 4, 5, 4, 2, 5, 5, 8, 5, 1, 5, 2, 6, 6, 4, 5, 6);
        // Matrix<double> m(3, 3, 1, 0, 0, 0, 1, 0, 0, 0, 1);
        m.printValues();

        Matrix<double> inv = m.inverse();
        inv.printValues();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}