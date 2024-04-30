#ifndef PAWN_H
#define PAWN_H

#include "ChessPiece.h"

class Pawn : public ChessPiece 
{
public:
    Pawn(std::string color);
    ~Pawn();
    void Print() override;
};

#endif // PAWN_H
