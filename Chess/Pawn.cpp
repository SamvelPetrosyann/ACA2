#include "Pawn.h"

Pawn::Pawn(Color color) : Figures(color) 
{
    if(color == Color::White)
    {
        m_name = "WP";
    }
    else
    {
        m_name = "BP";
    }
}

Pawn::~Pawn() {}

void Pawn::ControledSquares(bool** bmat, ChessBoard& board, int a, int b)
{
    if(a - 1 >= 0 && b - 1 >= 0)
    {
        bmat[a - 1][b - 1] = true;
    }
    if(a - 1 >= 0 && b + 1 < board.GetSize())
    {
        bmat[a - 1][b + 1] = true;
    }
}
