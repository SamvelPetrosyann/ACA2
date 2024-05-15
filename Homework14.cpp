#include <iostream>
class Matrix1
{
private: 
    int m_rows;
    int m_cols;
    int** m_mat;
public:
    Matrix1(int rows, int cols): m_cols(cols), m_rows(rows)
    {
        m_mat = new int* [m_rows];
        for(int i = 0; i < m_rows; ++i)
        {
            m_mat[i] = new int[m_cols];
        }
        for(int i = 0; i < m_rows; ++i)
        {
            for(int j = 0; j < m_cols; ++j)
            {
                m_mat[i][j] = 0;
            }
        }
    }
    ~Matrix1()
    {
        for (int i = 0; i < m_rows; ++i) 
        {
            delete[] m_mat[i];
        }
    
        delete[] m_mat;
    }
     Matrix1(const Matrix1& other) : m_rows(other.m_rows), m_cols(other.m_cols) 
     {
        m_mat = new int*[m_rows];
        for (int i = 0; i < m_rows; ++i)
        {
            m_mat[i] = new int[m_cols];
            for (int j = 0; j < m_cols; ++j)
            {
                m_mat[i][j] = other.m_mat[i][j];
            }
        }
    }
    Matrix1& operator=(const Matrix1& obj) 
    {
        if (this == &obj) 
        {
            return *this;
        }    
            for (int i = 0; i < m_rows; ++i) 
            {
                delete[] m_mat[i];
            }
            delete[] m_mat;

            m_rows = obj.m_rows;
            m_cols = obj.m_cols;

            m_mat = new int*[m_rows];
            for (int i = 0; i < m_rows; ++i)
            {
                m_mat[i] = new int[m_cols];
                for (int j = 0; j < m_cols; ++j) 
                {
                    m_mat[i][j] = obj.m_mat[i][j];
                }
            }
        
        return *this;
    }

    Matrix1& operator++()
    {
        for(int i = 0; i < m_rows; ++i)
        {
            for(int j = 0; j < m_cols; ++j)
            {
                m_mat[i][j]++;
            }
        }
        return *this;
    }
    Matrix1 operator++(int)
    {
        Matrix1 temp = *this;
        
        for(int i = 0; i < m_rows; ++i)
        {
            for(int j = 0; j < m_cols; ++j)
            {
                m_mat[i][j]++;
            }
        }
        return temp;
    }
    void Print()
    {
       for(int i = 0; i < m_rows; ++i)
        {
            for(int j = 0; j < m_cols; ++j)
            {
                std::cout << m_mat[i][j] << '\t';
            }
            std::cout << std::endl;
        } 
    }
}; 


class Matrix2
{
private: 
    int m_rows;
    int m_cols;
    int** m_mat;
public:
    Matrix2(int rows, int cols): m_cols(cols), m_rows(rows)
    {
        m_mat = new int* [m_rows];
        for(int i = 0; i < m_rows; ++i)
        {
            m_mat[i] = new int[m_cols];
        }
        for(int i = 0; i < m_rows; ++i)
        {
            for(int j = 0; j < m_cols; ++j)
            {
                m_mat[i][j] = 0;
            }
        }
    }
    ~Matrix2()
    {
        for (int i = 0; i < m_rows; ++i) 
        {
            delete[] m_mat[i];
        }
    
        delete[] m_mat;
    }
     Matrix2(const Matrix2& other) : m_rows(other.m_rows), m_cols(other.m_cols) 
     {
        m_mat = new int*[m_rows];
        for (int i = 0; i < m_rows; ++i)
        {
            m_mat[i] = new int[m_cols];
            for (int j = 0; j < m_cols; ++j)
            {
                m_mat[i][j] = other.m_mat[i][j];
            }
        }
    }
    Matrix2& operator=(const Matrix2& obj) 
    {
        if (this == &obj) 
        {
            return *this;
        }    
            for (int i = 0; i < m_rows; ++i) 
            {
                delete[] m_mat[i];
            }
            delete[] m_mat;

            m_rows = obj.m_rows;
            m_cols = obj.m_cols;

            m_mat = new int*[m_rows];
            for (int i = 0; i < m_rows; ++i)
            {
                m_mat[i] = new int[m_cols];
                for (int j = 0; j < m_cols; ++j) 
                {
                    m_mat[i][j] = obj.m_mat[i][j];
                }
            }
        
        return *this;
    }

    Matrix2& operator++()
    {
        for(int i = 0; i < m_rows; ++i)
        {
            for(int j = 0; j < m_cols; ++j)
            {
                m_mat[i][j] += 3;
            }
        }
        return *this;
    }
    Matrix2 operator++(int)
    {
        Matrix2 temp = *this;
        
        for(int i = 0; i < m_rows; ++i)
        {
            for(int j = 0; j < m_cols; ++j)
            {
                m_mat[i][j] += 3;
            }
        }
        return temp;
    }
    void Print()
    {
       for(int i = 0; i < m_rows; ++i)
        {
            for(int j = 0; j < m_cols; ++j)
            {
                std::cout << m_mat[i][j] << '\t';
            }
            std::cout << std::endl;
        } 
    }
}; 

int main()
{
    Matrix1 a(2,3);
    Matrix1 b(4,5);
    a.Print();
    b = ++a;
    
    std::cout << "=================" << std::endl;
    
    b.Print();
    b = a++;
    
    std::cout << "=================" << std::endl;
    b.Print();
    
    Matrix2 d(2,3);
    Matrix2 e = d;
    std::cout << "=================" << std::endl;
    d.Print();
    
    std::cout << "=================" << std::endl;
    
    e = d++;
    e.Print();
    e = ++d;
    
    std::cout << "=================" << std::endl;
    
    e.Print();
    
    return 0;
    
}        