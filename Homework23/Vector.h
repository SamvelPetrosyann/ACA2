#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template <typename T>
class Vector
{
private:
    int m_size;
    int m_cap;
    T* m_arr;
public:
    Vector();
    ~Vector();
    Vector(const Vector& other);
    Vector(Vector&& other);
    void push_back(const T& elem);
    void push_front(const T& elem);
    void pop_back();
    void pop_front();
    void insert(const T& elem, int position);
    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other);
    void PrintVector() const;
};

#endif // VECTOR_H