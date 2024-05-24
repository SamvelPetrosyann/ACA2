#include "Matrix.h"

int main()
{
	Matrix matrix1(3, 2);
	Matrix matrix2(2, 4);
	matrix1.CreateFile("mat1.txt");
	matrix2.CreateFile("mat2.txt");
	return 0;
}