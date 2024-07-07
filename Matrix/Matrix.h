#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <string>
#include <exception>

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
	int at(int row, int col);

};
#endif //MATRIX_H