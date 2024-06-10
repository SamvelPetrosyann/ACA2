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

King::~King() {}

void King::ControledSquares(bool** bmat, ChessBoard& board, int a, int b)
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

