 
#include "Figures.h"
#include "ChessBoard.h"
#include "Queen.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
void FillB(bool** bmat,int size)
{
    for(int i = 0; i < size; ++i)
    {
        
        for(int j = 0; j < size; ++j)
        {
           bmat[i][j] = false;
        }
    }    
}
int main()
{
    int a, b; 
    std::cin >> a;
    std::cin >> b;
    ChessBoard board;
    bool** bmat = new bool* [board.GetSize()];
    for(int i = 0; i < board.GetSize(); ++i)
    {
        bmat[i] = new bool [board.GetSize()];
    }
    FillB(bmat,board.GetSize());
    
    
    Figures* BK = new King(Color::Black);
    Figures* WK = new King(Color::White);
    Figures* WQ = new Queen(Color::White);
    Figures* WB = new Bishop(Color::White);
    Figures* WN = new Knight(Color::White);
    Figures* WR = new Rook(Color::White);
    board.FillBoard(WR,bmat, 1, 1);
    board.FillBoard(WK,bmat, 2, 7);
    board.FillBoard(BK,bmat, a, b);
    board.FillBoard(WQ,bmat, 1, 7);
    board.FillBoard(WB,bmat, 6, 1);
    board.FillBoard(WN,bmat, 7, 3);
    std::cout << std::endl;
    board.PrintBoard();
    board.Test(bmat, a, b);
    
    for(int i = 0; i < board.GetSize(); ++i)
    {
       delete[] bmat[i];
    }
    delete[] bmat;
    return 0;
}
