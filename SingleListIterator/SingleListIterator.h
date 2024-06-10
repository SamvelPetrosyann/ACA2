#ifndef SINGLELISTITERATOR_H
#define SINGLELISTITERATOR_H

#include "Node.h"

template<typename T>
class SingleList;

template<typename T>
class SingleListIterator 
{
private:
    Node<T>* current;

public:
    SingleListIterator(Node<T>* node);
    ~SingleListIterator();

    T& operator*() const;

    T* operator->() const;

    SingleListIterator<T>& operator++();

    SingleListIterator<T> operator++(int);
     
    bool operator==(const SingleListIterator<T>& other) const; 
    bool operator!=(const SingleListIterator<T>& other) const;
    friend class SingleList<T>;
};

#endif // SINGLELISTITERATOR_H
