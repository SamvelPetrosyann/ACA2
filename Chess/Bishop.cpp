#include "Bishop.h"

Bishop::Bishop(Color color) : Figures(color)
{
    if (color == Color::White)
    {
        m_name = "WB";
    }
    else
    {
        m_name = "BB";
    }
}

Bishop::Bishop(std::string name) : Figures(name)
{
    if (m_name == "WB")
    {
        m_color = Color::White;
    }
    else
    {
        m_color = Color::Black;
    }
}

Bishop::Bishop(const Bishop& other) : Figures(other)
{

}

Bishop& Bishop::operator=(const Bishop& other)
{
    if (this != &other)
    {
        Figures::operator=(other);
    }
    return *this;
}

Bishop::~Bishop() {}

Figures* Bishop::Clone() const
{
    return new Bishop(*this);
}

void Bishop::ControledSquares(std::vector<std::vector<bool>>& bmat, ChessBoard& board, int a, int b) const
{
    for (int i = 1; a + i < board.GetSize() && b + i < board.GetSize(); ++i)
    {
        bmat[a + i][b + i] = true;
        if (board.IsSquareOccupied(a + i, b + i))
        {
            if (board.IsBK(a + i, b + i))
            {
                if (a + i + 1 < board.GetSize() && b + i + 1 < board.GetSize())
                {
                    bmat[a + i + 1][b + i + 1] = true;
                }
            }
            break;
        }
    }
    for (int i = 1; a + i < board.GetSize() && b - i >= 0; ++i)
    {
        bmat[a + i][b - i] = true;
        if (board.IsSquareOccupied(a + i, b - i))
        {
            if (board.IsBK(a + i, b - i))
            {
                if (a + i + 1 < board.GetSize() && b - i - 1 >= 0)
                {
                    bmat[a + i + 1][b - i - 1] = true;
                }
            }
            break;
        }
    }
    for (int i = 1; a - i >= 0 && b + i < board.GetSize(); ++i)
    {
        bmat[a - i][b + i] = true;
        if (board.IsSquareOccupied(a - i, b + i))
        {
            if (board.IsBK(a - i, b + i))
            {
                if (a - i - 1 >= 0 && b + i + 1 < board.GetSize())
                {
                    bmat[a - i - 1][b + i + 1] = true;
                }
            }
            break;
        }
    }
    for (int i = 1; a - i >= 0 && b - i >= 0; ++i)
    {
        bmat[a - i][b - i] = true;
        if (board.IsSquareOccupied(a - i, b - i))
        {
            if (board.IsBK(a - i, b - i))
            {
                if (a - i - 1 >= 0 && b - i - 1 >= 0)
                {
                    bmat[a - i - 1][b - i - 1] = true;
                }
            }
            break;
        }
    }
}


bool Bishop::IsMoveValid(ChessBoard& board, int row, int col, int newRow, int newCol) const
{
    // Check diagonal down-right
    for (int i = 1; row + i < board.GetSize() && col + i < board.GetSize(); ++i)
    {
        if (row + i == newRow && col + i == newCol)
        {
            return true;
        }
        if (board.IsSquareOccupied(row + i, col + i))
        {
            break;
        }
    }

    // Check diagonal down-left
    for (int i = 1; row + i < board.GetSize() && col - i >= 0; ++i)
    {
        if (row + i == newRow && col - i == newCol)
        {
            return true;
        }
        if (board.IsSquareOccupied(row + i, col - i))
        {
            break;
        }
    }

    // Check diagonal up-right
    for (int i = 1; row - i >= 0 && col + i < board.GetSize(); ++i)
    {
        if (row - i == newRow && col + i == newCol)
        {
            return true;
        }
        if (board.IsSquareOccupied(row - i, col + i))
        {
            break;
        }
    }

    // Check diagonal up-left
    for (int i = 1; row - i >= 0 && col - i >= 0; ++i)
    {
        if (row - i == newRow && col - i == newCol)
        {
            return true;
        }
        if (board.IsSquareOccupied(row - i, col - i))
        {
            break;
        }
    }

    return false;
}

