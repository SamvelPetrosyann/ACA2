#ifndef ROOK_H
#define ROOK_H

#include "ChessPiece.h"

class Rook : public ChessPiece 
{
public:
    Rook(std::string color);
    ~Rook();
    void Print() override;
};

#endif // ROOK_H
