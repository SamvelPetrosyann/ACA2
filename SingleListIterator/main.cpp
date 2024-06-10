#include "Singlelist.h"

template<typename T>
void Print(const SingleList<T>& list)
{
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        std::cout << *it << '\t';
    }
}

int main()
{
    SingleList<int> list;
    list.push_front(5);
    list.push_front(6);
    list.push_front(7);
    list.push_front(8);
    Print(list);
    
    return 0;
}
