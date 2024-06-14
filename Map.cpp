#include <iostream>
#include <map>
#include <string>

std::map<int, std::string> numName =
{
    {0, "Null"},
    {1, "One"},
    {2, "Two"},
    {3, "Three"},
    {4, "Four"},
    {5, "Five"},
    {6, "Six"},
    {7, "Seven"},
    {8, "Eight"},
    {9, "Nine"},
};

std::string NumberNames(int a)
{
    auto it = numName.find(a);
    if(it != numName.end())
    {
        return it->second;
    }
    else 
    {
        return "number not found";
    }
}

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(auto elem: arr)
    {
        std::cout << NumberNames(elem) << std::endl;
    }
    return 0;
}