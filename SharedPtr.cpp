#include <iostream>

template <typename T>
class SharedPtr
{
private:
    T* ptr;
    int* refCount;
public:
    SharedPtr() : ptr(nullptr), refCount(new int (0)) {}
    SharedPtr(T* ptr) : ptr(ptr), refCount(new int(1)) {}
    ~SharedPtr()
    {
        (*refCount)--;
        if(*refCount == 0)
        {
            delete ptr;
            delete refCount;
        }
    }
    SharedPtr(const SharedPtr& other) : ptr(other.ptr), refCount(other.refCount)
    {
        (*refCount)++;
    }
    
    SharedPtr& operator=(const SharedPtr& other)
    {
        if(this != &other)
        {
            (*refCount)--;
            if(*refCount == 0)
            {
                delete refCount;
                delete ptr;
            }
            
            refCount = other.refCount;
            ptr = other.ptr;
            (*refCount)++;
        }
        return *this;
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
class SharedPtr<T[]>
{
private:
    T* ptr;
    int* refCount;
public:
    SharedPtr() : ptr(nullptr), refCount(new int (0)) {}
    SharedPtr(T* ptr) : ptr(ptr), refCount(new int(1)) {}
    ~SharedPtr()
    {
        (*refCount)--;
        if(*refCount == 0)
        {
            delete[] ptr;
            delete refCount;
        }
    }
    SharedPtr(const SharedPtr& other) : ptr(other.ptr), refCount(other.refCount)
    {
        (*refCount)++;
    }
    
    SharedPtr& operator=(const SharedPtr& other)
    {
        if(this != &other)
        {
            (*refCount)--;
            if(*refCount == 0)
            {
                delete refCount;
                delete[] ptr;
            }
            
            refCount = other.refCount;
            ptr = other.ptr;
            (*refCount)++;
        }
        return *this;
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
    SharedPtr<int> ptr(new int (5));
    SharedPtr<int> ptr2(ptr);
    SharedPtr<int> ptr3;
    ptr3 = ptr;
    std::cout << *ptr3 << std::endl;
    SharedPtr<int[]> arr(new int[5]);
    for(int i = 0; i < 5; ++i)
    {
        arr[i] = i + 1; 
    }
    for(int i = 0; i < 5; ++i)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}