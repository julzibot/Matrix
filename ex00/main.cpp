#include "../Utils.hpp"
#include "BasicOps.tpp"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    Matrix<float> a = Matrix<float>(2, 2, 1, 2, 3, 4);
    Matrix<float> f = Matrix<float>(2, 2, 1, 1, 1, 1);
    a.printValues();
    f.printValues();

    Matrix<float> addRes = scale(a, 3.5);
    addRes.printValues();

    return (0);
}