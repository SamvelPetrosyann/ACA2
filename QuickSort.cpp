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

template <typename T>
int PivotInd(T*arr,int left, int right)
{
    T pivot = arr[left];
    int count = 0;
    for(int i = left + 1; i <= right; ++i)
    {
        if(arr[i] <= pivot)
        {
            ++count;
        }
    }
    
    int pivotInd = left + count;
    std::swap(arr[left], arr[pivotInd]);
    
    int i = left, j = right;
    
    while(i < pivotInd && j > pivotInd)
    {
        while(arr[i] <= pivot)
        {
            ++i;
        }
        while(arr[j] > pivot)
        {
            --j;
        }
        if(i < pivotInd && j > pivotInd)
        {
            std::swap(arr[i++],arr[j--]);
        }
    }
    return pivotInd;
}

template<typename T>
void QuickSort(T* arr,int left, int right)
{
    if(left >= right)
    {
        return;
    }
    int pivotInd = PivotInd(arr, left, right);
    QuickSort(arr, left, pivotInd - 1);
    QuickSort(arr, pivotInd + 1, right);
}

int main()
{
    int size = 7;
    int* arr = new int[size];
    
    FillArr(arr, size);
    PrintArr(arr, size);
    
    QuickSort(arr, 0, size - 1);
    
    PrintArr(arr, size);
    
    delete[] arr;
    return 0;
}