#include<iostream>

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
void Merge(T* arr,int left,int middle,int right)
{
    int leftSize = middle - left + 1;
    int rightSize = right - middle;
    T* Left = new int [leftSize];
    T* Right = new int [rightSize];
    
    for(int i = 0; i < leftSize; ++i)
    {
        Left[i] = arr[left + i];
    }
    
    for(int j = 0; j < rightSize; ++j)
    {
        Right[j] = arr[middle + j + 1];
    }
    int i = 0;
    int j = 0;
    
    for(int k = left; k <= right; ++k)
    {
        if(i < leftSize && j  < rightSize)
        {
            if(Left[i] <= Right[j])
            {
                arr[k] = Left[i++];
            }
            else
            {
                arr[k] = Right[j++];
            }
        }
        else if(i == leftSize && j < rightSize)
        {
            arr[k] = Right[j++];
        }
        else
        {
            arr[k] = Left[i++];
        }
    }
    delete[] Left;
    delete[] Right;
}

template <typename T>
void MergeSort(T* arr, int left, int right)
{
    if(left < right)
    {
        int middle = left + (right - left)/2;
        MergeSort(arr, left, middle);
        MergeSort(arr, middle + 1, right);
        Merge(arr, left, middle, right);
    }
}

int main()
{
    int size = 7;
    int* arr = new int[size];
    
    FillArr(arr, size);
    PrintArr(arr, size);
    
    MergeSort(arr, 0 , size - 1);
    
    PrintArr(arr, size);
    
    delete[] arr;
    return 0;
}