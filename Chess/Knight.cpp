#include "Knight.h"

Knight::Knight(Color color) : Figures(color)
{
    if (color == Color::White)
    {
        m_name = "WN";
    }
    else
    {
        m_name = "BN";
    }
}
Knight::Knight(const Knight& other) : Figures(other)
{

}

Knight::Knight(std::string name) : Figures(name)
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

Knight& Knight::operator=(const Knight& other)
{
    if (this != &other)
    {

        Figures::operator=(other);
    }
    return *this;
}

Knight::~Knight() {}

Figures* Knight::Clone() const
{
    return new Knight(*this);
}

void Knight::ControledSquares(std::vector<std::vector<bool>>& bmat, ChessBoard& board, int a, int b) const
{
    if (a + 2 < board.GetSize())
    {
        if (b + 1 < board.GetSize())
        {
            bmat[a + 2][b + 1] = true;
        }
        if (b - 1 >= 0)
        {
            bmat[a + 2][b - 1] = true;
        }
    }

    if (a - 2 >= 0)
    {
        if (b + 1 < board.GetSize())
        {
            bmat[a - 2][b + 1] = true;
        }
        if (b - 1 >= 0)
        {
            bmat[a - 2][b - 1] = true;
        }
    }

    if (a + 1 < board.GetSize())
    {
        if (b + 2 < board.GetSize())
        {
            bmat[a + 1][b + 2] = true;
        }
        if (b - 2 >= 0)
        {
            bmat[a + 1][b - 2] = true;
        }
    }
    if (a - 1 >= 0)
    {
        if (b + 2 < board.GetSize())
        {
            bmat[a - 1][b + 2] = true;
        }
        if (b - 2 >= 0)
        {
            bmat[a - 1][b - 2] = true;
        }
    }
}

bool Knight::IsMoveValid(ChessBoard& board, int row, int col, int newcol, int newrow) const
{
    if (newrow == row + 2)
    {
        if (newcol == col + 1)
        {
            return true;
        }
        else if (newcol == col - 1)
        {
            return true;
        }
    }
    if (newrow == row - 2)
    {
        if (newcol == col + 1)
        {
            return true;
        }
        else if (newcol == col - 1)
        {
            return true;
        }
    }
    if (newrow == row + 1)
    {
        if (newcol == col + 2)
        {
            return true;
        }
        else if (newcol == col - 2)
        {
            return true;
        }
    }
    if (newrow == row - 1)
    {
        if (newcol == col + 2)
        {
            return true;
        }
        else if (newcol == col - 2)
        {
            return true;
        }
    }
    return false;
}



