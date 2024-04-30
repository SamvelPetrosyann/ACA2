#ifndef KING_H
#define KING_H

#include "ChessPiece.h"

class King : public ChessPiece 
{
public:
    King(std::string color);
    ~King();
    void Print() override;
};

#endif // KING_H
