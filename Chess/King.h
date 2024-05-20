#ifndef KING_H
#define KING_H

#include "Figures.h"

class King : public Figures
{
public:
    King(Color color);
    ~King();
    void ControledSquares(bool** bmat, ChessBoard& board, int a, int b) override;
};

#endif // KING_H
