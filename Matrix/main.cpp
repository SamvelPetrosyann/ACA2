#include "Matrix.h"

int main()
{
    Matrix mat(3, 4);
    std::cout << mat.at(5, 6) << std::endl;
    return 0;
}