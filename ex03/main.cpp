#include "../Vector.hpp"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    Vector<float> a = Vector<float>(2, -2, 0, 1, 0, -1);
    Vector<float> b = Vector<float>(2, 1, 1, 1, 1, 1);
    a.printValues();
    b.printValues();

    float res = a.dot(b);
    std::cout << "result: " << res << std::endl;

    return (0);
}