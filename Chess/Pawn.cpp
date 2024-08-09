#include "Pawn.h"

Pawn::Pawn(Color color) : Figures(color)
{
    if (color == Color::White)
    {
        m_name = "WP";
    }
    else
    {
        m_name = "BP";
    }
}

Pawn::Pawn(std::string name) : Figures(name)
{
    if (m_name == "WN")
    {
        m_color = Color::White;
    }
    else
    {
        m_color = Color::Black;
    }
}

Pawn::Pawn(const Pawn& other) : Figures(other)
{

}

Pawn& Pawn::operator=(const Pawn& other)
{
    if (this != &other)
    {
        Figures::operator=(other);
    }
    return *this;
}


Pawn::~Pawn() {}

Figures* Pawn::Clone() const
{
    return new Pawn(*this);
}

void Pawn::ControledSquares(std::vector<std::vector<bool>>& bmat, ChessBoard& board, int a, int b) const
{
    if (a - 1 >= 0 && b - 1 >= 0)
    {
        bmat[a - 1][b - 1] = true;
    }
    if (a - 1 >= 0 && b + 1 < board.GetSize())
    {
        bmat[a - 1][b + 1] = true;
    }
}

bool Pawn::IsMoveValid(ChessBoard& board, int row, int col, int newRow, int newCol) const
{
    if (newRow == row - 1 && newCol == col)
    {
        return true;
    }
    return false;
}
