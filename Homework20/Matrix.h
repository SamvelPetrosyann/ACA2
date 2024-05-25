#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
template<typename T>
class Matrix
{
private:
	int m_rows = 0;
	int m_cols = 0;
	T** m_mat = nullptr;
	T ConvertStringToType(const std::string& str);
public:
	Matrix(const std::string& filename);
	Matrix(int rows, int cols);
	Matrix(const Matrix& other);
	~Matrix();
	void PrintMatrix() const;
	Matrix operator*(const Matrix& other) const;
	Matrix& operator=(const Matrix& other);
	void CreateFile(const std::string& filename);
	Matrix operator+(const Matrix& other);
	

	
};

#endif //MATRIX_H