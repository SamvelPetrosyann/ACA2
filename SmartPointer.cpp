#include <iostream>

template <typename T>
class SmartPointer
{
private:
    T* ptr;
public:
    SmartPointer(T*ptr) : ptr(ptr)
    {
        
    }
    ~SmartPointer()
    {
        delete ptr;
    }
    T& operator*()
    {
        return *ptr;
    }
    T* operator->()
    {
        return ptr;
    }
};

template <typename T>
class SmartPointer<T[]>
{
    private:
    T* ptr;
public:
    SmartPointer(T*ptr) : ptr(ptr)
    {
        
    }
    ~SmartPointer()
    {
        delete [] ptr;
    }
    T& operator*()
    {
        return *ptr;
    }
    T* operator->()
    {
        return ptr;
    }
    
    T& operator[](int index)
    {
        return ptr[index];
    }
};

int main()
{
    SmartPointer<int> ptr = new int(5);
    SmartPointer<int[]> arr = new int [5] {1, 2, 3, 4, 5};
    std::cout << *ptr <<std::endl;
    for(int i = 0; i < 5; ++i)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}