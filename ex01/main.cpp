#include "../Vector.hpp"
#include "LinearCombination.tpp"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    try
    {
        Vector<float> a = Vector<float>(1, 2, 3, 4, 5, 6);
        Vector<float> b = Vector<float>(1, 1, 1, 1, 1, 1);
        Vector<float> c = Vector<float>(2, 2, 2, 2, 2, 2);
        a.printValues();
        b.printValues();
        c.printValues();

        std::vector<Vector<float>> vecs{a, b, c};
        std::vector<float> coeffs{1, 1, -1};

        Vector<float> res = linear_combination(vecs, coeffs);
        res.printValues();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}