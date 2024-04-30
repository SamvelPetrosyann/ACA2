#include <iostream>

#include "Queen.h"
#include "King.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"

int main()
{
    int size = 6;
    ChessPiece** ptr = new ChessPiece* [size];
    ptr[0] = new Queen("black");
    ptr[1] = new King("white");
    ptr[2] = new Bishop("black");
    ptr[3] = new Pawn("white");
    ptr[4] = new Knight("black");
    ptr[5] = new Rook("white");
    for(int i = 0; i < size; ++i)
    {
        ptr[i]->Print();    
    }
    for(int i = 0; i < size; ++i)
    {
        delete ptr[i];
    }
    delete[] ptr;
    return 0;
}