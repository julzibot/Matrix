#include "../Vector.hpp"
#include "../Matrix.hpp"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    try
    {
        Matrix<double> m(3, 3, 1, 2, 3, 4, 5, 6, 7, 8, -9);
        m.printValues();

        double trace = m.trace();
        std::cout << "TRACE: " << trace << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}