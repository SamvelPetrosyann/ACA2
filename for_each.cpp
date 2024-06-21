#include <iostream>
#include <vector>

template <typename T>
void print(T a)
{
    std::cout << a << " ";
}

template <typename T, typename F>

F for_each(T first, T last, F func)
{
    for(;first != last; ++first)
    {
        func(*first);
    }
    return func;
}

int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    for_each(arr.begin(),arr.end(),print<int>);
    return 0;
}