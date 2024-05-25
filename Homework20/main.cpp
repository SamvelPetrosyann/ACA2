#include "Matrix.cpp"

int main()
{
	Matrix<int> matrix1("C:\\Users\\Smart\\source\\repos\\Project6\\Project6\\mat1.txt");
	Matrix<int> matrix2("C:\\Users\\Smart\\source\\repos\\Project6\\Project6\\mat2.txt");
	matrix1.PrintMatrix();
	std::cout << "_________________________________" << std::endl;
	matrix2.PrintMatrix();
	Matrix<int> matrix3 = matrix1 * matrix2;
	std::cout << "_________________________________" << std::endl;
	matrix3.PrintMatrix();
	matrix3.CreateFile("mat3.txt");
	return 0;
}