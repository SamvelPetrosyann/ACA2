#include "King.h"

King::King(Color color) : Figures(color) 
{
    if(color == Color::White)
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
    if(a + 1 < board.GetSize())
    {
        bmat[a + 1][b] = true;
        if( b + 1 < board.GetSize())
        {
            bmat[a + 1][b + 1] = true;
        
        }
        if(b - 1 >= 0)
        {
            bmat[a + 1][b - 1] = true;
        } 
    }

    if(a - 1 >= 0)
    {
        bmat[a - 1][b] = true;
        if( b + 1 < board.GetSize())
        {
            bmat[a - 1][b + 1] = true;
        
        }
        if(b - 1 >= 0)
        {
            bmat[a - 1][b - 1] = true;
        } 
    }

    if(b + 1 < board.GetSize())
    {
        bmat[a][b + 1] = true;
    }

    if(b - 1 >= 0)
    {
        bmat[a][b - 1] = true;
    }
}
