#include <iostream>
class Matrix
{
    private:
    int rows;
    int cols;
    int** matrix;
    
    public:
    
    Matrix(int rows,int cols)
    {
        this->rows = rows;
        this->cols = cols;
        matrix = new int* [rows];
        for(int i = 0; i < rows;++i)
        {
            matrix[i] = new int [cols]; 
        }
        for(int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < cols; ++j)
            {
                matrix[i][j] = rand() % 20;
            }
        }
    }
    
    ~Matrix()
    {
        for (int i = 0; i < rows; ++i) 
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    Matrix(const Matrix& other)
    {
        rows = other.rows;
        cols = other.cols;
        matrix = new int* [rows];
        for(int i = 0; i < rows; ++i)
        {
            matrix[i] = new int [cols];
        }
        for(int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < cols; ++j)
            {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }
    
    Matrix& operator=(const Matrix& other)
    {
        for(int i = 0; i < rows; ++i)
        {
            delete [] matrix[i];
        }
        delete [] matrix;
        
        rows = other.rows;
        cols = other.cols;
        
        matrix = new int* [rows];
        for(int i = 0; i < rows; ++i)
        {
            matrix[i] = new int [cols];
        }
        for(int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < cols; ++j)
            {
                matrix[i][j] = other.matrix[i][j];
            }    
        }
        return *this;
    }

    Matrix operator+(const Matrix &other)
    {
        Matrix temp(rows,cols);
        for(int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < cols; ++j)
            {
                temp.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return temp;
        
    }
    
    void print()
    {
        for (int i = 0; i < rows; ++i) 
        {
            for(int j = 0; j < cols; ++j)
            {
                std::cout << matrix[i][j] << '\t';
            }
            std::cout << std::endl; 
        }
        
    }
};

int main()
{
    Matrix a(4,5);
    a.print();
    Matrix  b = a;
    
    std::cout <<"======================="<< std::endl;
    b.print();
    
    Matrix c(3,4);
    a = c;
    
    std::cout <<"======================="<< std::endl;
    a.print();
    
    Matrix d(3,4);
    d = c + c;
    
    std::cout <<"======================="<< std::endl;
    d.print();
    return 0;
    
}