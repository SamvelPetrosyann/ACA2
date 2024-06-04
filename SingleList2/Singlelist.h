
#ifndef SINGLELIST_H
#define SINGLELIST_H

#include "Node.h"

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

    const Node<T>* GetHead() const;
    
    void Reverse();
    
    T GetNthNode(int n);
    
    
    
};

#endif // SINGLELIST_H