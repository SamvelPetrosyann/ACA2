#include "Singlelist.h"


template<typename T>
SingleList<T>::SingleList() : head(nullptr)
{
    
}

template<typename T>
SingleList<T>::~SingleList() 
{
    Node<T>* current = head;
    while (current != nullptr) 
    {
        Node<T>* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

template<typename T>
void SingleList<T>::push_front(const T& val)
{
    Node<T>* newNode = new Node<T>(val);
    newNode->next = head;
    head = newNode;
}

template<typename T>
void SingleList<T>::pop_front()
{
    if (head == nullptr)
    {
        return;
    }
    Node<T>* temp = head;
    head = head->next;
    delete temp;
}
template<typename T>
void SingleList<T>::Print() const
{
    Node<T>* current = head;
    while (current != nullptr)
    {
        std::cout << current->data << '\t';
        current = current->next;
    }
}


template<typename T>
void SingleList<T>::Reverse() 
{
    if (head == nullptr || head->next == nullptr) 
    {
        return;
    }
    Node<T>* prev = nullptr;
    Node<T>* curr = head;
    Node<T>* foll = nullptr;
    
    while(curr != nullptr)
    {
        foll = curr->next;
        curr->next = prev;
        prev = curr;
        curr = foll;
    }
    head = prev;

}


template<typename T>
SingleListIterator<T> SingleList<T>::begin() const
{
    return SingleListIterator<T>(head);
}

template<typename T>
SingleListIterator<T> SingleList<T>::end() const 
{
    return SingleListIterator<T>(nullptr);
}

template class SingleList<int>;
template class SingleList<float>;
template class SingleList<double>;
template class SingleList<char>;