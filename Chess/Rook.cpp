#include "Rook.h"

Rook::Rook(Color color,std::string name) : Figures(color,name ) {}

Rook::~Rook() {}

void Rook::ControledSquares(bool** bmat, ChessBoard& board, int a, int b)
{
    assert(a >= 0 && a < board.GetSize());
    assert(b >= 0 && b < board.GetSize());
    for(int i = 1; a + i < board.GetSize(); ++i)
    {
        bmat[a + i][b] = true;
        if(board.IsBusy( a + i, b ))
        {
            if(board.IsBK(a + i, b))
            {
                if(a + i + 1 < board.GetSize())
                {
                    bmat[a + i + 1][b] = true;
                }
            }
            break;
        }        
    }

    for(int i = 1; b + i < board.GetSize(); ++i)
    {
        bmat[a][b + i] = true;
        if(board.IsBusy( a , b + i))
        {
            if(board.IsBK(a , b + i))
            {
                if(b + i + 1 < board.GetSize())
                {
                    bmat[a][b + i + 1] = true;
                }
            }
            break;
        }        
    }

    for(int i = 1; b - i >= 0; ++i)
    {
        bmat[a][b - i] = true;
        if(board.IsBusy( a, b - i))
        {
            if(board.IsBK(a , b - i))
            {
                if(b - i - 1 >= 0)
                {
                    bmat[a][b - i - 1] = true;
                }
            }
            break;
        }        
    }
    for(int i = 1; a - i >= 0; ++i)
    {
        bmat[a - i][b] = true;

        if(board.IsBusy( a + i, b ))
        { 
            if(board.IsBK(a - i, b))
            {
                if(a - i - 1 >= 0 )
                {
                    bmat[a - i - 1][b] = true;
                }
            }
            break;
        }        
    }

}