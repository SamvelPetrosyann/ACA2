
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
void PrintB(bool** bmat,int size)
{
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            std::cout << bmat[i][j] << '\t';
        }
        std::cout << std::endl;
    }    
}
int main()
{
    ChessBoard board;
    bool** bmat = new bool* [board.GetSize()];
    for(int i = 0; i < board.GetSize(); ++i)
    {
        bmat[i] = new bool [board.GetSize()];
    }
    FillB(bmat,board.GetSize());
    
    
    Figures* BK = new King(Color::Black, "BK");
    Figures* WK = new King(Color::White, "Wk");
    Figures* WQ = new Queen(Color::White, "WQ");
    Figures* WB = new Bishop(Color::White, "WB");
    Figures* WN = new Knight(Color::Black, "WN");
    Figures* WR = new Rook(Color::White, "WR");
    Figures* WP = new Pawn(Color::White,"WP");

    board.FillBoard(BK, 4, 7);
    board.FillBoard(WR, 1, 1);
    board.FillBoard(WK, 0, 7);
    board.FillBoard(WQ, 1, 7);
    //board.FillBoard(WB, 6, 1);
    //board.FillBoard(WN, 7, 3);

    WQ->ControledSquares(bmat, board, 1, 7);
    WR->ControledSquares(bmat, board, 1, 1);
    WK->ControledSquares(bmat, board, 4, 7);
    std::cout << std::endl;
    
    board.PrintBoard();
    board.Test(bmat,0, 7);

    delete BK;
    delete WR;
    delete WQ;
    delete WB;
    delete WN;
    delete WP;
    delete WK;
    for(int i = 0; i < board.GetSize(); ++i)
    {
       delete[] bmat[i];
    }
    delete[] bmat;
    return 0;
}