#include "Knight.h"

Knight::Knight(Color color) : Figures(color ) 
{
    if(color == Color::White)
    {
        m_name = "WN";
    }
    else
    {
        m_name = "BN";
    }
}

Knight::~Knight() {}

void Knight::ControledSquares(bool** bmat, ChessBoard& board, int a, int b)
{
    if(a + 2 < board.GetSize())
    {
        if(b + 1 < board.GetSize())
        {
            bmat[a + 2][b + 1] = true;
        }
        if(b - 1 >= 0)
        {
            bmat[a + 2][b - 1] = true;
        }
    }

    if(a - 2 >= 0)
    {
        if(b + 1 < board.GetSize())
        {
            bmat[a - 2][b + 1] = true;
        }
        if(b - 1 >= 0)
        {
            bmat[a - 2][b - 1] = true;
        }
    }

    if(a + 1 < board.GetSize())
    {
        if(b + 2 < board.GetSize())
        {
            bmat[a + 1][b + 2] = true;
        }
        if(b - 1 >= 0)
        {
            bmat[a + 1][b - 2] = true;
        }
    }
    if(a - 1 >= 0)
    {
        if(b + 2 < board.GetSize())
        {
            bmat[a - 1][b + 2] = true;
        }
        if(b - 2 >= 0)
        {
            bmat[a - 1][b - 2] = true;
        }
    }
}    
