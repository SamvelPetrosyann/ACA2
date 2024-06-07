
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "Node.h"

template<typename T>
class DoubleLinkedList
{
    Node<T>* head;
    Node<T>* tail;
public:
    DoubleLinkedList();
      
    ~DoubleLinkedList();
   
    void push_front(const T& val);
    
    void push_back(const T& val);

    void pop_front();

    void pop_back();
    
    void insert(const T& val, int n);
    
    void Print() const;
    
};

#endif // DOUBLELINKEDLIST_H