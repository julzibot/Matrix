#include "../Vector.hpp"
#include "../Matrix.hpp"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    try
    {
        Matrix<double> m(2, 3, 1, 3, 5, 2, 4, 6);
        m.printValues();

        m.transpose();
        m.printValues();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}