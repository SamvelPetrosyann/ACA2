#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
 
std::ostream& operator<<(std::ostream& str,std::list<int>& list)
{
    for(int elem:list)
    {
        str << elem << "  " ;
    }
    return str;
}

int main()
{
    std::vector<int> vec = {4, 3, 8, 9, 5, 4, 6};
    std::sort(vec.begin(),vec.end());
    for(int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << "  ";
    }
    std::cout << std::endl;
    
    std::list<int> list = {2, 4, 4, 9, 8, 1, 5, 3};
    list.sort();
    std::cout << list << std::endl;
}