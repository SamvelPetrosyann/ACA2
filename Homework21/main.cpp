#include <iostream>

#include "Vector.cpp"

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
    return 0;
}