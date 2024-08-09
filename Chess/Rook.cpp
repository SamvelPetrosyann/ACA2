#include "Rook.h"

Rook::Rook(Color color) : Figures(color)
{
    if (color == Color::White)
    {
        m_name = "WR";
    }
    else
    {
        m_name = "BR";
    }
}

Rook::Rook(std::string name) : Figures(name)
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

Rook::Rook(const Rook& other) : Figures(other)
{

}

Rook& Rook::operator=(const Rook& other)
{
    if (this != &other)
    {
        Figures::operator=(other);
    }
    return *this;
}


Rook::~Rook() {}

Figures* Rook::Clone() const
{
    return new Rook(*this);
}

void Rook::ControledSquares(std::vector<std::vector<bool>>& bmat, ChessBoard& board, int a, int b) const
{
    for (int i = 1; a + i < board.GetSize(); ++i)
    {
        bmat[a + i][b] = true;
        if (board.IsSquareOccupied(a + i, b))
        {
            if (board.IsBK(a + i, b))
            {
                if (a + i + 1 < board.GetSize())
                {
                    bmat[a + i + 1][b] = true;
                }
            }
            break;
        }
    }

    for (int i = 1; b + i < board.GetSize(); ++i)
    {
        bmat[a][b + i] = true;
        if (board.IsSquareOccupied(a, b + i))
        {
            if (board.IsBK(a, b + i))
            {
                if (b + i + 1 < board.GetSize())
                {
                    bmat[a][b + i + 1] = true;
                }
            }
            break;
        }
    }

    for (int i = 1; b - i >= 0; ++i)
    {
        bmat[a][b - i] = true;
        if (board.IsSquareOccupied(a, b - i))
        {
            if (board.IsBK(a, b - i))
            {
                if (b - i - 1 >= 0)
                {
                    bmat[a][b - i - 1] = true;
                }
            }
            break;
        }
    }
    for (int i = 1; a - i >= 0; ++i)
    {
        bmat[a - i][b] = true;

        if (board.IsSquareOccupied(a - i, b))
        {
            if (board.IsBK(a - i, b))
            {
                if (a - i - 1 >= 0)
                {
                    bmat[a - i - 1][b] = true;
                }
            }
            break;
        }
    }

}


bool Rook::IsMoveValid(ChessBoard& board, int row, int col, int newRow, int newCol)const
{
    for (int i = 1; row + i < board.GetSize(); ++i)
    {
        if (board.IsSquareOccupied(row + i, col))
        {
            break;
        }

        if (row + i == newRow && col == newCol)
        {
            return true;
        }
    }

    for (int i = 1; col + i < board.GetSize(); ++i)
    {
        if (board.IsSquareOccupied(row, col + i))
        {
            break;
        }

        if (row == newRow && col + i == newCol)
        {
            return true;
        }

    }

    for (int i = 1; col - i >= 0; ++i)
    {
        if (board.IsSquareOccupied(row, col - i))
        {
            break;
        }

        if (row == newRow && col - i == newCol)
        {
            return true;
        }

    }
    for (int i = 1; row - i >= 0; ++i)
    {
        if (board.IsSquareOccupied(row - i, col))
        {
            break;
        }

        if (row - i == newRow && col == newCol)
        {
            return true;
        }
    }
    return false;
}
