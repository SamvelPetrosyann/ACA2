#include <iostream>

#include "Vector.h"

int main()
{
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
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