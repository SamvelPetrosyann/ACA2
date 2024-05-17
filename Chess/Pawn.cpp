#include "Pawn.h"

Pawn::Pawn(Color color,std::string name) : Figures(color,name ) {}

Pawn::~Pawn() {}

void Pawn::ControledSquares(bool** bmat, ChessBoard& board, int a, int b)
{
    assert(a >= 0 && a < board.GetSize());
    assert(b >= 0 && b < board.GetSize());
    if(a - 1 >= 0 && b - 1 >= 0)
    {
        bmat[a - 1][b - 1] = true;
    }
    if(a - 1 >= 0 && b + 1 < board.GetSize())
    {
        bmat[a - 1][b + 1] = true;
    }
}
