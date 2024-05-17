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
        std::cout << "call param constructor" << std::endl;
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
        std::cout << "call destructor" << std::endl;
        for (int i = 0; i < rows; ++i) 
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    
    Matrix(Matrix&& other): rows(other.rows), cols(other.cols), matrix(other.matrix) 
    {
        std::cout << "call move constructor" << std::endl;
        matrix = other.matrix;
        other.rows = 0;
        other.cols = 0;
        other.matrix = nullptr;
    }
    
    Matrix& operator=(Matrix&& other)  
    {
        std::cout << "call move operator=" << std::endl;
        if (this != &other) 
        {
            for (int i = 0; i < rows; ++i) 
            {
                delete[] matrix[i];
            }
            delete[] matrix;

            rows = other.rows;
            cols = other.cols;
            matrix = other.matrix;

            other.rows = 0;
            other.cols = 0;
            other.matrix = nullptr;
        }
        return *this;
    }
    
    Matrix operator+(const Matrix& other) 
    {
        Matrix temp(rows, cols);
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) 
            {
                temp.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
    }
    return temp;
    }
    Matrix(const Matrix& other) 
    {
        std::cout << "call copy constructor" << std::endl;
        rows = other.rows;
        cols = other.cols;
        matrix = new int*[rows];
        for (int i = 0; i < rows; ++i) 
        {
            matrix[i] = new int[cols];
        }
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) 
            {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }
    
    Matrix& operator=(const Matrix& other) 
    {
        std::cout << "call copy operator=" << std::endl;
        for (int i = 0; i < rows; ++i) 
        {
            delete[] matrix[i];
        }
        delete[] matrix;

        rows = other.rows;
        cols = other.cols;

        matrix = new int*[rows];
        for (int i = 0; i < rows; ++i) 
        {
            matrix[i] = new int[cols];
        }
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) 
            {
                matrix[i][j] = other.matrix[i][j];
            }
        }
        return *this;
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
    Matrix mat1(3,3);
    Matrix mat2(3,3);
    Matrix mat3 = std::move(mat1 + mat2);
    Matrix mat4(4,4);
    mat4 = std::move(mat1 + mat2);
    return 0;
}