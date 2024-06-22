#include <iostream>

auto multiply(int a)
{
    return [a](int b){
        return a * b;
    };
}
int main()
{
    int x;
    x = multiply(5)(6);
    std::cout << x <<std::endl;
    return 0;
}