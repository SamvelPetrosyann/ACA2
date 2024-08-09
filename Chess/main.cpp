
#include "Figures.h"
#include "ChessBoard.h"
#include "Queen.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"

enum
{
    A, B, C, D, E, F, G, H
};

int Pos(int n)
{
    return 8 - n;
}
void FillB(std::vector<std::vector<bool>>& bmat, int size)
{
    for (int i = 0; i < size; ++i)
    {

        for (int j = 0; j < size; ++j)
        {
            bmat[i][j] = false;
        }
    }
}


int main()
{
    int a, b;
    ChessBoard board;
    std::vector<std::vector<bool>> bmat(board.GetSize(), std::vector<bool>(board.GetSize()));
    std::cout << std::endl;
    FillB(bmat, board.GetSize());


    Figures* BK = new King(Color::Black);
    Figures* WK = new King(Color::White);
    Figures* WQ = new Queen(Color::White);
    Figures* WB = new Bishop(Color::White);
    Figures* WN = new Knight(Color::White);
    Figures* WR = new Rook(Color::White);
    board.AddFigure(WR, Pos(6), F);
    board.AddFigure(WK, Pos(6), H);
    board.AddFigure(BK, Pos(7), E);
    board.AddFigure(WQ, Pos(6), G);
    board.AddFigure(WB, Pos(1), B);
    board.AddFigure(WN, Pos(3), C);
    std::cout << std::endl;
    board.PrintBoard();
     std::cout << "___________________________________________________________________" << std::endl << std::endl;
    board.GameAnalyze(bmat);

    return 0;
}
