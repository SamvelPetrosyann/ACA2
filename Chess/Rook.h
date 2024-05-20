#ifndef ROOK_H
#define ROOK_H

#include "Figures.h"

class Rook : public Figures
{
public:
    Rook(Color color);
    ~Rook();
    void ControledSquares(bool** bmat, ChessBoard& board, int a, int b) override;
};

#endif // ROOK_H
