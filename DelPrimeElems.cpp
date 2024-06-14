#include <iostream>
#include <vector>
#include <cmath>

bool IsPrime(int a)
{
    if(a < 2)
    {
        return false;
    }
    for(int i = 2;i <= sqrt(a);++i)
    {
        if(a % i == 0){
            return false;
        }
    }
    return true;
}

int main()
{
    std::vector<int> vec = {3, 7, 6, 9, 8, 12, 25, 5};
   for (auto it = vec.begin(); it != vec.end();) 
   {
        if (IsPrime(*it))
        {
            it = vec.erase(it); 
        } 
        else
        {
            ++it; 
        }
    }
    for(auto it: vec)
    {
        std::cout << it << " ";
    }
    return 0;
}