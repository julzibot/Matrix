#include "../Matrix.hpp"

template <typename N>
Matrix<N> projection(N fov, N ratio, N near, N far)
{
    std::vector<N> values(16, 0);

    N f = tan(fov / 2);
    N rangeInv = near - far;
    N max = 0;

    values[0] = 1 / (f * ratio);
    values[5] = 1 / f;
    values[10] = (near + far) / rangeInv;
    values[11] = 2 * near * far / rangeInv;
    values[14] = -1;

    for (size_t i = 0; i < values.size(); i++)
    {
        if (std::abs(values[i]) > max)
            max = std::abs(values[i]);
    }
    for (size_t j = 0; j < values.size(); j++)
    {
        values[j] /= max;
        if (values[j] < 0 && j < 8)
            values[j] *= -1;
    }

    return Matrix<N>(4, 4, values);
}

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    double fov = 20;
    double ratio = 1.;
    double near = 10;
    double far = 1000;

    Matrix<double> p = projection(fov, ratio, near, far);
    std::ofstream f("proj");
    if (f.is_open())
    {
        std::vector<double> values = p.getValues();
        for (size_t i = 0; i < 15; i++)
        {
            f << values[i] << ", ";
            if (i % 4 == 3)
                f << std::endl;
        }
        f << values[15];
        f.close();
    }
    else
        std::cerr << "error encountered while opening file" << std::endl;

    return (0);
}