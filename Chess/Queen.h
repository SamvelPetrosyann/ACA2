#ifndef QUEEN_H
#define QUEEN_H

#include "Figures.h"

class Queen : public Figures
{
public:
    Queen(Color color);
    ~Queen();
    void ControledSquares(bool** bmat, ChessBoard& board, int a, int b) override;
};

#endif // QUEEN_H
