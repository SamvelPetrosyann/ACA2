#include "Matrix.h"

template<typename T>
Matrix<T>::Matrix(int rows, int cols) :m_rows(rows), m_cols(cols)
{
	m_mat = new T* [rows];
	for (int i = 0; i < rows; ++i)
	{
		m_mat[i] = new T[cols];
	}
	for (int i = 0; i < m_rows; ++i)
	{
		for (int j = 0; j < m_cols; ++j)
		{
			m_mat[i][j] = 0;
		}
	}
}

template<typename T>
Matrix<T>::Matrix(const std::string& filename)
{
	m_rows = 0;
	m_cols = 0;
	bool temp = false;

	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "Unable to open file" << std::endl;
		return;
	}
	std::string line;
	while (std::getline(file, line))
	{
		for (int i = 0; i < line.length(); ++i)
		{
			if (line[i] == '\t' && !temp)
			{
				++m_cols;
			}
		}
		temp = true;
		++m_rows;
	}
	
	file.clear(); 
	file.seekg(0, std::ios::beg);
	m_mat = new T* [m_rows];
	for (int i = 0; i < m_rows; ++i)
	{
		m_mat[i] = new T[m_cols];
	}
	for (int i = 0; i < m_rows; ++i)
	{
		for (int j = 0; j < m_cols; ++j)
		{
			m_mat[i][j] = 0;
		}
	}
	char str[100] = "\0";
	int k = 0;
	int m = 0;
	int n = 0;
	while (std::getline(file, line))
	{
		for (int i = 0; i < line.length(); ++i)
		{
			if (line[i] == '\t')
			{ 
				str[k] = '\0';
				m_mat[m][n++] = ConvertStringToType(str);
				k = 0;
				for (int j = 0; j < sizeof(str); ++j)
				{
					str[j] = '\0';
				}
			}
			else
			{
				str[k++] = line[i];
			}
		}
		++m;
		n = 0;
	}
	file.close();
}

template<typename T>
Matrix<T>::Matrix(const Matrix& other)
{
	m_rows = other.m_rows;
	m_cols = other.m_cols;
	m_mat = new T* [m_rows];
	for (int i = 0; i < m_rows; ++i)
	{
		m_mat[i] = new T[m_cols];
	}
	for (int i = 0; i < m_rows; ++i)
	{
		for (int j = 0; j < m_cols; ++j)
		{
			m_mat[i][j] = other.m_mat[i][j];
		}
	}
}

template<typename T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < m_rows; ++i)
	{
		delete[] m_mat[i];
	}
	delete[] m_mat;
}

template<typename T>
void Matrix<T>::PrintMatrix() const
{
	for (int i = 0; i < m_rows; ++i)
	{
		for (int j = 0; j < m_cols; ++j)
		{
			std::cout << m_mat[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix& other) const
{
	if (m_cols != other.m_rows)
	{
		std::cerr << "Error: Matrix dimensions are incompatible for multiplication\n";
		return Matrix(0, 0);
	}

	Matrix result(m_rows, other.m_cols);

	for (int i = 0; i < m_rows; ++i) {
		for (int j = 0; j < other.m_cols; ++j)
		{
			for (int k = 0; k < m_cols; ++k)
			{
				result.m_mat[i][j] += m_mat[i][k] * other.m_mat[k][j];
			}
		}
	}

	return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& other)
{
	if (this == &other)
	{
		return *this;
	}

	for (int i = 0; i < m_rows; ++i)
	{
		delete[] m_mat[i];
	}
	delete[] m_mat;

	m_rows = other.m_rows;
	m_cols = other.m_cols;

	m_mat = new T* [m_rows];
	for (int i = 0; i < m_rows; ++i)
	{
		m_mat[i] = new T[m_cols];
	}
	for (int i = 0; i < m_rows; ++i)
	{
		for (int j = 0; j < m_cols; ++j)
		{
			m_mat[i][j] = other.m_mat[i][j];
		}
	}
	return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& other) 
{
    Matrix temp(m_rows, m_cols);
    for (int i = 0; i < m_rows; ++i) 
    {
        for (int j = 0; j < m_cols; ++j) 
        {
            temp.m_mat[i][j] = m_mat[i][j] + other.m_mat[i][j];
        }
    }
    return temp;
}
    
template<typename T>
void Matrix<T>::CreateFile(const std::string& filename)
{
	std::ofstream file(filename);
	if (file.is_open())
	{
		for (int i = 0; i < m_rows; ++i)
		{
			for (int j = 0; j < m_cols; ++j)
			{
				file << m_mat[i][j] << ' ';
			}
			file << std::endl;
		}
		std::cout << "Data writen to " << filename << std::endl;
	}
	else
	{
		std::cerr << "Unable to open file " << std::endl;
	}
}

template<typename T>
T Matrix<T>::ConvertStringToType(const std::string& str)
{
    std::istringstream iss(str);
    T result;
    iss >> result;
    return result;
}