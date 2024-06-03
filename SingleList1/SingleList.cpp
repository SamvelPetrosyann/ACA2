#include "SingleList.h"


template<typename T>
SingleList<T>::SingleList() :head(nullptr)
    {

    }

    template<typename T>
    SingleList<T>::~SingleList()
    {
        while (head != nullptr)
        {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
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

    
    template class SingleList<int>;
    template class SingleList<float>;
    template class SingleList<double>;
    template class SingleList<char>;