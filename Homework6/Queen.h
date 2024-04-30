#ifndef QUEEN_H
#define QUEEN_H

#include "ChessPiece.h"

class Queen : public ChessPiece 
{
public:
    Queen(std::string color);
    ~Queen();
    void Print() override;
};

#endif // QUEEN_H
