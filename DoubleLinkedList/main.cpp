#include "DoubleLinkedList.h"

template<typename T>
bool HasCycle(const DoubleLinkedList<T>& list) {
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
    DoubleLinkedList<int> list;
    list.push_front(5);
    list.push_front(6);
    list.push_front(7);
    list.push_back(8);
    list.insert(4,0);
    list.insert(2,5);
    
    list.Print();
    
    
    
    return 0;
}