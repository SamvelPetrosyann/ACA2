#include <iostream>
#include <algorithm>

template<typename T>
void FillArr(T* arr, int size)
{
    for(int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 20;
    }
}

template<typename T>
void PrintArr(T* arr, int size)
{
    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;
}

template<typename T>
void BubbleSort(T* arr, int size)
{
    bool isswaped = false;
    for(int i = 0; i < size - 1; ++i)
    {
        for(int j = 0; j < size - i - 1; ++j)
        {
            if(arr[j] > arr[j + 1])
            {
                std::swap(arr[j],arr[j + 1]);
                isswaped = true;
            }
        }
        if(!isswaped)
        {
            break;
        }
    }
}

int main()
{
    int size = 7;
    int* arr = new int[size];
    
    FillArr(arr, size);
    PrintArr(arr, size);
    
    BubbleSort(arr, size);
    
    PrintArr(arr, size);
    
    delete[] arr;
    return 0;
}