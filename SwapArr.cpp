#include <iostream>
#include <algorithm>
void FillArr(int arr[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        { 
            arr[i*n+j] = rand() % 20;
        }
    }
}
void PrintArr(int arr[],int n)
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
           std::cout << arr[i*n+j] << '\t';
        }
        std::cout << std::endl;
    }
    
}
void Swap(int arr[], int n)
{
   for(int i = 0 ;i < n; ++i)
    {
        for(int j = i;j < n; ++j)
        {
           std::swap(arr[j*n+i], arr[i*n+j]);
        }
    } 
}

int main()
{
    int n = 5;
    int arr[n * n];
    FillArr(arr, n);
    PrintArr(arr, n);
    Swap(arr, n);
    std::cout << std::endl;
    printarr(arr, n);
    return 0;
}
