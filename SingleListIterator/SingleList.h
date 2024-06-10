
#ifndef SINGLELIST_H
#define SINGLELIST_H

#include "Node.h"
#include "SingleListIterator.h"

template<typename T>
class SingleList
{
    Node<T>* head;
public:
    SingleList();
      
    ~SingleList();
   
    void push_front(const T& val);

    void pop_front();

    void Print() const;
    
    void Reverse();
    
    SingleListIterator<T> begin() const;
    
    SingleListIterator<T> end() const;
    
    
    
};

#endif // SINGLELIST_H