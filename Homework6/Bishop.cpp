#include "Bishop.h"

Bishop::Bishop(std::string color) : ChessPiece(color) {}

Bishop::~Bishop() {}

void Bishop::Print()
{
    std::cout << "I am a Bishop and my color is " << GetColor() << std::endl;
}
