#include <iostream>
#include <fstream>
#include <streambuf>

int main()
{
    std::ofstream file;
    file.open("output.txt");
    std::cout.rdbuf(file.rdbuf());
    std::cout << "Hello" << std::endl;
    file.close();
}