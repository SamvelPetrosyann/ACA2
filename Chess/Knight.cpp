#include "Knight.h"

Knight::Knight(Color color,std::string name) : Figures(color,name ) {}

Knight::~Knight() {}

void Knight::ControledSquares(bool** bmat, ChessBoard& board, int a, int b)
{
    assert(a >= 0 && a < board.GetSize());
    assert(b >= 0 && b < board.GetSize());
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
