#include <iostream>

void Print()
{
    std::cout << std::endl;
}

template<typename T,typename... N>
void Print(T a, N... b)
{
    std::cout << a << " ";
    Print(b...);
}

int main()
{
    Print(2, 3.5, 'd', "str");
    return 0;
}