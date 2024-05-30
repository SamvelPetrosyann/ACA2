#include <iostream>

#include "Vector.h"

int main()
{
    Vector<int> v = {1, 2, 3, 4, 5};
    v.push_front(7);
    v.PrintVector();
    v.pop_back();
    std::cout << std::endl;
    v.PrintVector();
    v.pop_front();
    std::cout << std::endl;
    v.PrintVector();
    v.insert(5,2);
    std::cout << std::endl;
    v.PrintVector();
    
    return 0;
}