#include "Vector.h"

template <typename T>
Vector<T>::Vector() :m_size(0), m_cap(2), m_arr(new T[m_cap])
{

}

template <typename T>
Vector<T>::~Vector()
{
    delete[] m_arr;
}

template<typename T>
Vector<T>::Vector(const Vector& other):m_size(other.m_size),m_cap(other.m_cap),m_arr(new T[m_cap])
{
    for (int i = 0; i < m_size; ++i)
    {
        m_arr[i] = other.m_arr[i];
    }
}
template<typename T>
Vector<T>::Vector(Vector&& other) :m_size(other.m_size), m_cap(other, m_cap), m_arr(other.m_arr)
{
    other.m_arr = nullptr;
    other.m_cap = 0;
    other.m_size = 0;
}

template<typename T>
void Vector<T>::push_back(const T& elem)
{
    if (m_size < m_cap)
    {
        m_arr[m_size++] = elem;
    }
    else
    {
        T* new_arr = new T[m_cap * 2];
        for (int i = 0; i < m_size; ++i)
        {
            new_arr[i] = m_arr[i];
        }
        delete[] m_arr;
        m_arr = new_arr;
        new_arr = nullptr;
        m_cap *= 2;
        m_arr[m_size++] = elem;
    }
}

template<typename T>
void Vector<T>::push_front(const T& elem)
{
    if (m_size == 0)
    {
        m_arr[m_size] = elem;
    }
    else if (m_size < m_cap)
    {
        m_arr[m_size++] = 0;
        for (int i = m_size; i > 0; --i)
        {
            std::swap(m_arr[i], m_arr[i - 1]);
        }
        m_arr[0] = elem;
    }
    else
    {
        T* new_arr = new T[m_cap * 2];
        for (int i = 0; i < m_size; ++i)
        {
            new_arr[i] = m_arr[i];
        }
        delete[] m_arr;
        m_arr = new_arr;
        new_arr = nullptr;
        m_cap *= 2;
        m_arr[m_size++] = 0;
        for (int i = m_size; i > 0; --i)
        {
            std::swap(m_arr[i], m_arr[i - 1]);
        }
        m_arr[0] = elem;
    }
}
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) 
{
    if (this != &other) 
    {
        delete[] m_arr;
        m_size = other.m_size;
        m_cap = other.m_cap;
        m_arr = new T[m_cap];
        for (int i = 0; i < m_size; ++i) 
        {
            m_arr[i] = other.m_arr[i];
        }
    }
    return *this;
}
template<typename T>
Vector<T>& Vector<T>::operator=(Vector&& other)
{
    if (this != &other)
    {
        
        delete[] m_arr;

        m_size = other.m_size;
        m_cap = other.m_cap;
        m_arr = other.m_arr;

        other.m_cap = 0;
        other.m_size = 0;
        other.m_arr = nullptr;
    }
    return *this;
}
template <typename T>
void Vector<T>::PrintVector() const
{
    for (int i = 0; i < m_size; ++i)
    {
        std::cout << m_arr[i] << '\t';
    }
}