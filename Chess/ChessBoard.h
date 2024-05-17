#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "Figures.h"

class Figures;

class ChessBoard
{
private:
    const int m_size = 8;
    Figures ***mat;

public:
    ChessBoard();
    ~ChessBoard();
    void FillBoard(Figures *fig, int a, int b);
    bool IsBusy(int a, int b);
    int GetSize() const;
    void PrintBoard() const;
    bool IsBK(int a, int b);
    void Test(bool**, int a, int b);

};

#endif // CHESSBOARD_H
