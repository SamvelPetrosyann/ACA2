
#include "Knight.h"

Knight::Knight(std::string color) : ChessPiece(color) {}

Knight::~Knight() {}

void Knight::Print() 
{
    std::cout << "I am a Knight and my color is " << GetColor() << std::endl;
}
