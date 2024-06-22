#include <iostream>
#include <vector>
#include <cmath>
#include <functional>

bool IsPrime(int a)
{
    if(a < 2)
    {
        return false;
    }
    for(int i = 2; i <= sqrt(a); ++i)
    {
        if(a % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    std::vector<int> vec = {3, 5, 8, 9, 11, 13, 12, 14, 17}; 
    vec.erase(std::remove_if(vec.begin(),vec.end(),[](int a){return IsPrime(a);}), vec.end());
    std::for_each(vec.begin(),vec.end(),[](int a){std::cout << a << " ";});
    std::cout << std::endl;
}