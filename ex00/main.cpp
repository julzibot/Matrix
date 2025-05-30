#include "../Vector.hpp"
#include "../Matrix.hpp"
// #include "BasicOps.tpp"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    Vector<float> u = Vector<float>(1, 2, 3.5, 4);
    Vector<float> v = Vector<float>(1.5, 0.5, 0, 0);
    u.printValues();
    v.printValues();
    u.add(v);
    u.printValues();
    v.scl(2);
    v.printValues();
    u.sub(v);
    u.printValues();

    Matrix<float> a = Matrix<float>(2, 2, 1, 2, 3, 4);
    Matrix<float> b = Matrix<float>(2, 2, 1, 1, 1, 1);
    a.printValues();
    b.printValues();

    a.add(b);
    a.printValues();
    b.scl(2);
    b.printValues();
    a.sub(b);
    a.printValues();

    return (0);
}