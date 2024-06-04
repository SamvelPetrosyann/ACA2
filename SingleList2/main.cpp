#include "SingleList.h"

template<typename T>
bool HasCycle(const SingleList<T>& list) {
    if (list.GetHead() == nullptr || list.GetHead()->next == nullptr)
    {
        return false;
    }

    Node<T>* current = list.GetHead()->next;

    while (current != nullptr) {
        if (list.GetHead() == current) {
            return true;
        }

        current = current->next;
    }

    return false;
}


int main()
{
    SingleList<int> list;
    list.push_front(5);
    list.push_front(6);
    list.push_front(7);
    list.push_front(8);
    
    list.pop_front();
    
    list.Print();
    
    list.Reverse();
    
    std::cout << std::endl;
    list.Print();
    
    std::cout << std::endl;
    std::cout << "n-th data is " <<list.GetNthNode(2) <<std::endl;
    
    if (HasCycle(list))
    {
        std::cout << "The list have a cycle" << std::endl;
    }
    else
    {
        std::cout << "The list doesn't have a cycle" << std::endl;
    }
    return 0;
}