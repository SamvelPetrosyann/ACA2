#include "SingleListIterator.h"

    template<typename T>
    SingleListIterator<T>::SingleListIterator(Node<T>* node) : current(node) {}
    
    template<typename T>
    SingleListIterator<T>::~SingleListIterator() {}
    
    template<typename T>
    T& SingleListIterator<T>::operator*() const
    {
        return current->data;
    }
    
    template<typename T>
    T* SingleListIterator<T>::operator->() const 
    {
        return &(current->data);
    }
    
    template<typename T>
    SingleListIterator<T>& SingleListIterator<T>::operator++() 
    {
        current = current->next;
        return *this;
    }
    
    template<typename T>
    SingleListIterator<T> SingleListIterator<T>::operator++(int) 
    {
        SingleListIterator<T> temp = *this;
        ++(*this);
        return temp;
    }
    
    template<typename T>
    bool SingleListIterator<T>::operator==(const SingleListIterator<T>& other) const 
    {
        return current == other.current;
    }

    template<typename T>
    bool SingleListIterator<T>::operator!=(const SingleListIterator<T>& other) const
    {
        return !(*this == other);
    }

template class SingleListIterator<int>;
template class SingleListIterator<float>;
template class SingleListIterator<double>;
template class SingleListIterator<char>;
