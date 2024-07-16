#include <iostream>
#include <memory>

class Matrix
{
    int m_rows;
    int m_cols;
    std::unique_ptr<std::unique_ptr<int[]>[]> matrix;
public:    
    Matrix(int rows, int cols): m_rows(rows), m_cols(cols)
    {
        matrix = std::make_unique<std::unique_ptr<int[]>[]>(rows);
        for(int i = 0; i < rows; ++i)
        {
            matrix[i] = std::make_unique<int[]>(cols);
        }
        for(int i = 0; i < m_rows; ++i)
        {
            for(int j = 0; j < m_cols; ++j)
            {
                matrix[i][j] = rand() % 20;
            }
        }
    }
    ~Matrix() = default;
    Matrix(const Matrix& other)
    {
        m_rows = other.m_rows;
        m_cols = other.m_cols;
        matrix = std::make_unique<std::unique_ptr<int[]>[]>(m_rows);
        for(int i = 0; i < m_rows; ++i)
        {
            matrix[i] = std::make_unique<int[]>(m_cols);
        }
        for(int i = 0; i < m_rows; ++i)
        {
            for(int j = 0; j < m_cols; ++j)
            {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }
    
    
    
    Matrix& operator=(const Matrix& other) 
    {
        if (this != &other) 
        {
            Matrix temp(other);
            std::swap(m_rows, temp.m_rows);
            std::swap(m_cols, temp.m_cols);
            std::swap(matrix, temp.matrix);
        }
        return *this;
    }
    
    
    void Print() const
    {
        for (int i = 0; i < m_rows; ++i)
        {
            for (int j = 0; j < m_cols; ++j)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

};

int main()
{
    Matrix mat(5,4);
    mat.Print();
    return 0;
}