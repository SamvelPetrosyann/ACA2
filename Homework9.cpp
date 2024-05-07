#include <iostream>
class Matrix
{
private:
    int** m_matrix;
    int m_rows;
    int m_cols;
public:
    Matrix(int rows, int cols):m_cols(cols), m_rows(rows)
    {
        m_matrix = new int* [rows];
        for(int i = 0; i < rows;++i)
        {
            m_matrix[i] = new int [cols]; 
        }
        for(int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < cols; ++j)
            {
                m_matrix[i][j] = rand() % 20;
            }
        }
    }
    
     ~Matrix()
    {
        for (int i = 0; i < m_rows; ++i) 
        {
            delete[] m_matrix[i];
        }
        delete[] m_matrix;
    }
    
    void Print()
    {
        for (int i = 0; i < m_rows; ++i) 
        {
            for(int j = 0; j < m_cols; ++j)
            {
                std::cout << m_matrix[i][j] << '\t';
            }
            std::cout << std::endl; 
        }
        
    }
    
    int operator()(int row, int col)
    {
        return m_matrix[row][col];
    }
};
int main()
{
    Matrix mat(4, 5);
    mat.Print();
    std::cout << std::endl;
    std::cout << mat(2, 3) << std::endl;
    return 0;
}
