#include "DoubleLinkedList.h"


template<typename T>
DoubleLinkedList<T>::DoubleLinkedList() : head(nullptr), tail(nullptr)
{
    
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList() 
{
    Node<T>* current = head;
    while (current != nullptr) 
    {
        Node<T>* temp = current;
        current = current->next;
        delete temp;
        if (current == head) 
        {
            break; 
        }
    }
    head = nullptr;  
}
template<typename T>
void DoubleLinkedList<T>::push_front(const T& val)
{
    Node<T>* newNode = new Node<T>(val);
    if (head == nullptr) 
    {
        head = newNode;
        tail = head;
    } 
    else 
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}   

template<typename T>
void DoubleLinkedList<T>::pop_front()
{
    if (head == nullptr)
    {
        return;
    }
    Node<T>* temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
    temp = nullptr;
}

template<typename T>
void DoubleLinkedList<T>::push_back(const T& val)
{
    Node<T>* newNode = new Node<T>(val);
    if (head == nullptr) 
    {
        head = newNode;
        tail = head;
    } 
    else 
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}    

template<typename T>
void DoubleLinkedList<T>::pop_back()
{
    if (head == nullptr)
    {
        return;
    }
    Node<T>* temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;
    temp = nullptr;
}

template<typename T>
void DoubleLinkedList<T>::insert(const T& val, int n) 
{
    if(n < 0)
    {
        return;
    }
    
    if(n == 0)
    {
        push_front(val);
        return;
    }
    
    Node<T>* temp = head;
    for(int i = 0; i < n - 1; ++i)
    {
        if(temp == nullptr)
        {
            return;
        }
        temp = temp->next;
    }
    if(temp == tail)
    {
        push_back(val);
        return;
    }
    
    Node<T>* newNode = new Node<T>(val);
    newNode->next = temp->next;
    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    newNode->prev = temp;
    temp->next = newNode;
}

template<typename T>
void DoubleLinkedList<T>::Print() const
{
    Node<T>* current = head;
    while (current != nullptr)
    {
        std::cout << current->data << '\t';
        current = current->next;
    }
}



template class DoubleLinkedList<int>;
template class DoubleLinkedList<float>;
template class DoubleLinkedList<double>;
template class DoubleLinkedList<char>;