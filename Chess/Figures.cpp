#include "Figures.h"
#include <cassert>

Figures::Figures(Color color) : m_color(color) {}

Figures::Figures(std::string name) : m_name(name) {}

Figures::Figures(const Figures& other)
{
    m_name = other.m_name;
    m_color = other.m_color;
}

Figures& Figures::operator=(const Figures& other)
{
    if (this != &other)
    {
        m_color = other.m_color;
        m_name = other.m_name;
    }
    return *this;
}

Figures::~Figures() {}

std::string Figures::GetName() const
{
    return m_name;
}

void Figures::Move(ChessBoard& board, int row, int col, int newRow, int newCol)
{
    if (IsMoveValid(board, row, col, newRow, newCol))
    {
        if (board.mat[row][col]->GetName() == "BK" && board.mat[newRow][newCol] != nullptr)
        {
            delete board.mat[newRow][newCol];
            board.mat[newRow][newCol] = nullptr;
        }
        board.PlaceFigure(this, newRow, newCol);
        board.PlaceFigure(nullptr, row, col);

    }
}

