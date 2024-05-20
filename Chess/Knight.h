#ifndef KNIGHT_H
#define KNIGHT_H

#include "Figures.h"

class Knight : public Figures
{
public:
    Knight(Color color);
    ~Knight();
    void ControledSquares(bool** bmat, ChessBoard& board, int a, int b) override;
};

#endif // KNIGHT_H
