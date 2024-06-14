#include <iostream>
#include <list>

template <typename T>
double Average(std::list<T> list)
{
    T sum = 0;
    int count = 0;
    for(auto it: list)
    {
        sum += it;
        ++count;
    }
    return (double)sum / count;
}

int main()
{
    std::list<int> list = {3, 7, 6, 9, 8, 12, 25, 5};
    double aver = Average(list);
    for(auto it = list.begin(); it != list.end();)
    {
        if (*it < aver)
        {
            it = list.erase(it); 
        } 
        else
        {
            ++it; 
        }
    }
    std::cout << aver << std::endl;
    for(auto it: list)
    {
        std::cout << it << " ";
    }
    return 0;
}