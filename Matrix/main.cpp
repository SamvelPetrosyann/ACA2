#include "Matrix.h"

int main()
{
    Matrix mat(3, 4);
    try
    {
        std::cout << mat.at(5, 6) << std::endl;
    } 
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        throw;
    }
    return 0;
}
