#include "SingleList.h"


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
        
        if (current == head) 
        {
            break; 
        }
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
const Node<T>* SingleList<T>::GetHead() const
{
    return head;
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
T SingleList<T>::GetNthNode(int n)
{
    if(head == nullptr)
    {
        std::cout <<"haed is nullptr" << std::endl;
        return 0;
    }
    if(n < 0)
    {
        std::cout <<"n must be greater than 0" << std::endl;
        return 0;
    }
    Node<T>* current = head;
    int count = 0;
    for(int i = 0; i < n; ++i)
    {
        if(current == nullptr)
        {
            break;
        }
        current = current->next;
        count++;
    }
    if(current == nullptr || count < n)
    {
        std::cout <<"n is greather than size" << std::endl;
        return 0;
    }
    return current->data;
}


template class SingleList<int>;
template class SingleList<float>;
template class SingleList<double>;
template class SingleList<char>;