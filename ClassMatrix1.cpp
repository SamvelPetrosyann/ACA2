#include <iostream>
#include <algorithm>
class Matrix
{
    int** mat;
    int size = 4;
    public:
    void CreateMatrix()
    {
        mat = new int* [size];
        for(int i = 0; i < size; ++i)
        {
            mat[i] = new int [size];
        }
    }
    void FillMatrix()
    {
        for(int i = 0; i < size; ++i)
        {
            for(int j = 0; j < size; ++j)
            {
                mat[i][j] = rand() % 20;
            }
        }
    }
    void Transpose()
    {
        for(int i = 0; i < size; ++i)
        {
            for(int j = i; j < size; ++j)
            {
               std::swap(mat[j][i], mat[i][j]);
            }
        }
    }
    void PrintMatrix()
    {
        for(int i = 0; i < size; ++i)
        {
            for(int j = 0; j < size; ++j)
            {
                std::cout << mat[i][j]<<'\t';
            }
            std::cout << std::endl;
        }    
    }
    void Release()
    {
        for(int i = 0; i < size; ++i)
        {
            delete [] mat[i];
        }
        delete [] mat;
    }
};
int main()
{
    Matrix p;
    p.CreateMatrix();
    p.FillMatrix();
    p.PrintMatrix();
    std::cout << std::endl;
    p.Transpose();
    p.PrintMatrix();
    p.Release();
    return 0;
}