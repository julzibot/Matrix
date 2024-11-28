#include "Utils.hpp"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;
    
    Vector<int> a = Vector<int>();
    Vector<float> f = Vector<float>(" 1. 2. 6.7 12.8");

    a.printValues();
    f.printValues();

    return (0);
}