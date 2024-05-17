#include "King.h"

King::King(Color color,std::string name) : Figures(color,name) {}

King::~King() {}

void King::ControledSquares(bool** bmat, ChessBoard& board, int a, int b)
{
    assert(a >= 0 && a < board.GetSize());
    assert(b >= 0 && b < board.GetSize());
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
