#include "Matrix.h"

Matrix::Matrix(int rows, int cols) :m_rows(rows), m_cols(cols)
{
	m_mat = new int* [m_rows];
	for (int i = 0; i < m_rows; ++i)
	{
		m_mat[i] = new int[cols];
	}
	
	for (int i = 0; i < m_rows; ++i)
	{
		for (int j = 0; j < m_cols; ++j)
		{
			m_mat[i][j] = rand() % 10;
		}
	}
}
Matrix::Matrix(const Matrix& other)
{
    m_rows = other.m_rows;
    m_cols = other.m_cols;
    m_mat = new int* [m_rows];
    for(int i = 0; i < m_rows; ++i)
    {
        m_mat[i] = new int[m_cols];
    }
    for(int i = 0; i < m_rows; ++i)
    {
        for(int j = 0; j < m_cols; ++j)
        {
            m_mat[i][j] = other.m_mat[i][j];
        }
    }
}

Matrix::~Matrix()
{
	for (int i = 0; i < m_rows; ++i)
	{
		delete[] m_mat[i];
	}
	delete[] m_mat; 
}

Matrix& Matrix::operator=(const Matrix& other)
{
    if(this == &other)
    {
        return *this;
    }
        
    for(int i = 0; i < m_rows; ++i)
    {
        delete [] m_mat[i];
    }
    delete [] m_mat;
        
    m_rows = other.m_rows;
    m_cols = other.m_cols;
        
    m_mat = new int* [m_rows];
    for(int i = 0; i < m_rows; ++i)
    {
        m_mat[i] = new int [m_cols];
    }
    for(int i = 0; i < m_rows; ++i)
    {
        for(int j = 0; j < m_cols; ++j)
        {
            m_mat[i][j] = other.m_mat[i][j];
        }    
    }
    return *this;
}

int Matrix::at(int row, int col)
{
        if(row < 0 || row >= m_rows || col < 0 || col >= m_cols)
        {
            throw std::out_of_range("index out of range");
        }
        return m_mat[row][col];
}
