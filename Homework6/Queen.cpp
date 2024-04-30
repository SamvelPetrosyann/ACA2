#include "Queen.h"

Queen::Queen(std::string color) : ChessPiece(color) {}

Queen::~Queen() {}

void Queen::Print() 
{
    std::cout << "I am a Queen and my color is " << GetColor() << std::endl;
}
