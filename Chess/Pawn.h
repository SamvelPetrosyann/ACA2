#ifndef PAWN_H
#define PAWN_H

#include "Figures.h"

class Pawn : public Figures
{
public:
    Pawn(Color color,std::string name);
    ~Pawn();
    void ControledSquares(bool** bmat, ChessBoard& board, int a, int b) override;
};

#endif // PAWN_H
