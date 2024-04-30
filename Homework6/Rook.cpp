#include "Rook.h"

Rook::Rook(std::string color) : ChessPiece(color) {}

Rook::~Rook() {}

void Rook::Print() 
{
    std::cout << "I am a Rook and my color is " << GetColor() << std::endl;
}
