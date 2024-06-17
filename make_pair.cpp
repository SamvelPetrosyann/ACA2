#include <iostream>

template <typename T1, typename T2>
std::pair<T1, T2> make_pair(T1&& first, T2&& second)
{
    return std::pair<T1, T2>(std::forward<T1>(first), std::forward<T2>(second));
}

int main()
{
    const char* str = "Hello";
    int a = 8;
    auto pair = make_pair(a, str);
    
    std::cout << pair.first << "   " << pair.second <<std::endl;
    return 0;
}
