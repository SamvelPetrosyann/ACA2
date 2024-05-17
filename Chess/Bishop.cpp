#include "Bishop.h"

Bishop::Bishop(Color color,std::string name) : Figures(color,name ){}

Bishop::~Bishop() {}

void Bishop::ControledSquares(bool** bmat, ChessBoard& board, int a, int b)
{
    assert(a >= 0 && a < board.GetSize());
    assert(b >= 0 && b < board.GetSize());
    for(int i = 1; a + i < board.GetSize() && b + i < board.GetSize(); ++i)
    {
        bmat[a + i][b + i] = true;
        if(board.IsBusy( a + i, b + i))
        {
            if(board.IsBK(a + i, b + i))
            {
                if(a + i + 1 < board.GetSize() && b + i + 1 < board.GetSize())
                {
                    bmat[a + i + 1][b + i + 1] = true;
                }
            }
            break;
        }        
    }
    for(int i = 1; a + i < board.GetSize() && b - i >= 0; ++i)
    {
        bmat[a + i][b - i] = true;
        if(board.IsBusy( a + i, b - i))
        {
            if(board.IsBK(a + i, b - i))
            {
                if(a + i + 1 < board.GetSize() && b - i - 1 >= 0)
                {
                    bmat[a + i + 1][b - i - 1] = true;
                }
            }
            break;
        }        
    }
    for(int i = 1; a - i >= 0 && b + i < board.GetSize(); ++i)
    {
        bmat[a - i][b + i] = true;
        if(board.IsBusy( a - i, b + i))
        {
            if(board.IsBK(a - i, b + i))
            {
                if(a - i - 1 >= 0 && b + i + 1 < board.GetSize())
                {
                    bmat[a - i - 1][b + i + 1] = true;
                }
            }
            break;
        }        
    }
    for(int i = 1; a - i >= 0 && b - i >= 0; ++i)
    {
        bmat[a - i][b - i] = true;
        if(board.IsBusy( a - i ,b - i))
        {
            if(board.IsBK(a - i, b - i))
            {
                if(a - i - 1 >=0 && b - i - 1 >= 0)
                {
                    bmat[a - i - 1][b - i - 1] = true;
                }
            }
            break;
        }        
    }
}
