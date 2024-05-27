#include <iostream>
template <unsigned int T>
class Fib
{
public: 
    static const int val = Fib<T - 1>::val + Fib<T - 2>::val;
};

template <>
class Fib< 0>
{
public:
    static const int val = 0;
};

template <>
class Fib<1>
{
public:
    static const int val = 1;
};

int main()
{
    std::cout << Fib<5>::val << std::endl;
    std::cout << Fib<6>::val << std::endl;
    std::cout << Fib<7>::val << std::endl;
    return 0;
}