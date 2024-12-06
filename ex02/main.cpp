#include "../Vector.hpp"
#include "../Matrix.hpp"
#include "LinearInterpolation.tpp"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    Matrix<float> a = Matrix<float>(2, 2, 0, 0, 0, 0);
    Matrix<float> b = Matrix<float>(2, 2, 1, 1, 1, 1);
    a.printValues();
    b.printValues();

    Matrix<float> res = lerp<Matrix<float>>(a, b, 0.5);
    res.printValues();

    return (0);
}