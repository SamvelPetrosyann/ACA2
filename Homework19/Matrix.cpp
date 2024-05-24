#include "Matrix.h"

Matrix::Matrix(int rows, int cols) :m_rows(rows), m_cols(cols)
{
	m_mat = new int* [rows];
	for (int i = 0; i < rows; ++i)
	{
		m_mat[i] = new int[cols];
	}
	for (int i = 0; i < m_rows; ++i)
	{
		for (int j = 0; j < m_cols; ++j)
		{
			m_mat[i][j] = 0;
		}
	}
}

Matrix::Matrix(const std::string& filename)
{
	m_rows = 0;
	m_cols = 0;
	int count1 = 0;
	int count2 = 0;
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
				count1++;
			}
		}
		temp = true;
		++count2;
	}
	file.clear(); 
	file.seekg(0, std::ios::beg);
	m_rows = count2;
	m_cols = count1;
	m_mat = new int* [m_rows];
	for (int i = 0; i < m_rows; ++i)
	{
		m_mat[i] = new int[m_cols];
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
				m_mat[m][n++] = std::stoi(str);
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

Matrix::Matrix(const Matrix& other)
{
	m_rows = other.m_rows;
	m_cols = other.m_cols;
	m_mat = new int* [m_rows];
	for (int i = 0; i < m_rows; ++i)
	{
		m_mat[i] = new int[m_cols];
	}
	for (int i = 0; i < m_rows; ++i)
	{
		for (int j = 0; j < m_cols; ++j)
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

void Matrix::PrintMatrix() const
{
	for (int i = 0; i < m_rows; ++i)
	{
		for (int j = 0; j < m_cols; ++j)
		{
			std::cout << m_mat[i][j] << '\t';
		}
		std::cout << std::endl;
	}
}

Matrix Matrix::operator*(const Matrix& other) const
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

Matrix& Matrix::operator=(const Matrix& other)
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

	m_mat = new int* [m_rows];
	for (int i = 0; i < m_rows; ++i)
	{
		m_mat[i] = new int[m_cols];
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

void Matrix::CreateFile(const std::string& filename)
{
	std::ofstream file(filename);
	if (file.is_open())
	{
		for (int i = 0; i < m_rows; ++i)
		{
			for (int j = 0; j < m_cols; ++j)
			{
				file << m_mat[i][j] << '\t';
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