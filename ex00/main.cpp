#include "Utils.hpp"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;
    
    // Vector<int> a = Vector<int>(3.6, 1, 8.3, 9, 11);
    // Vector<double> f = Vector<double>(1., 2., 6.7, 12.8);
    // Vector<double> k = Vector<double>(1.);

    // k = f;
    // Vector<double> cpy = Vector<double>(f);

    // a.printValues();
    // f.printValues();
    // k.printValues();
    // cpy.printValues();

    Matrix<int> a = Matrix<int>(2, 3, 3.6, 1, 8.3, 9, 4, 4);
    Matrix<double> f = Matrix<double>(3, 2, 1., 2., 6.7, 12.8, 33.6, 545);
    // Matrix<double> k = Matrix<double>(1, 1, 1.);

    // k.printValues();
    // k = f;
    // Matrix<double> cpy = Matrix<double>(f);

    a.printValues();
    f.printValues();
    // k.printValues();
    // cpy.printValues();
    a.reshape(1, 6);
    a.printValues();

    return (0);
}