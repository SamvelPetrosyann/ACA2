#ifndef KNIGHT_H
#define KNIGHT_H

#include "ChessPiece.h"

class Knight : public ChessPiece 
{
public:
    Knight(std::string color);
    ~Knight();
    void Print() override;
};

#endif // KNIGHT_H
