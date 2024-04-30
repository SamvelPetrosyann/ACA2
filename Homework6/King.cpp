#include "King.h"

King::King(std::string color) : ChessPiece(color) {}

King::~King() {}

void King::Print() 
{
    std::cout << "I am a King and my color is " << GetColor() << std::endl;
}
