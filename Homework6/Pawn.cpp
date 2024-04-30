#include "Pawn.h"

Pawn::Pawn(std::string color) : ChessPiece(color) {}

Pawn::~Pawn() {}

void Pawn::Print() 
{
    std::cout << "I am a Pawn and my color is " << GetColor() << std::endl;
}
