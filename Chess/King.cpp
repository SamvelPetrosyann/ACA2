#include "King.h"

King::King(Color color) : Figures(color)
{
    if (color == Color::White)
    {
        m_name = "WK";
    }
    else
    {
        m_name = "BK";
    }
}

King::King(std::string name) : Figures(name)
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

King::King(const King& other) : Figures(other)
{

}

King& King::operator=(const King& other)
{
    if (this != &other)
    {
        Figures::operator=(other);
    }
    return *this;
}

King::~King() {}

Figures* King::Clone() const
{
    return new King(*this);
}

void King::ControledSquares(std::vector<std::vector<bool>>& bmat, ChessBoard& board, int a, int b) const
{
    int row;
    int col;

    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {

            if (i == 0 && j == 0) continue;

            row = a + i;
            col = b + j;
            if (row >= 0 && row < board.GetSize() && col >= 0 && col < board.GetSize())
            {
                bmat[row][col] = true;
            }
        }
    }
}

bool King::IsMoveValid(ChessBoard& board, int row, int col, int newRow, int newCol) const
{
    int a;
    int b;

    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            if (i == 0 && j == 0) continue;

            a = row + i;
            b = col + j;
            if (newRow == a && newCol == b && board.AreKingsNotAdjacent(a, b))
            {
                return true;
            }
        }
    }
    return false;
}


