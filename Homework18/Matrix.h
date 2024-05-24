#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <string>
#include <fstream>

class Matrix
{
private:
	int m_rows;
	int m_cols;
	int** m_mat;
public:
	Matrix(int rows, int cols);
	~Matrix();
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);
	void CreateFile(const std::string& filename);

};
#endif //MATRIX_H