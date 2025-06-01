#include "../Vector.hpp"
#include "../Matrix.hpp"
#include "LinearInterpolation.tpp"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    try
    {
        Vector<float> a = Vector<float>(5, 6, 0, 0, 0, 0);
        Vector<float> b = Vector<float>(2, 2, 1, 1, 1, 1);
        a.printValues();
        b.printValues();

        Vector<float> vres = lerp(a, b, 0.5);
        vres.printValues();

        Matrix<float> c = Matrix<float>(2, 2, 0, 0, 0, 0);
        Matrix<float> d = Matrix<float>(2, 2, 1, 1, 1, 1);
        c.printValues();
        d.printValues();

        Matrix<float> mres = lerp(c, d, 0.5);
        mres.printValues();

        float x = 1;
        float y = 42;
        float z = lerp(x, y, 0.6);
        std::cout << "float lerp: " << z << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}