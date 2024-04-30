#ifndef BISHOP_H
#define BISHOP_H

#include "ChessPiece.h"

class Bishop : public ChessPiece 
{
public:
    Bishop(std::string color);
    ~Bishop();
    void Print() override;
};

#endif // BISHOP_H
