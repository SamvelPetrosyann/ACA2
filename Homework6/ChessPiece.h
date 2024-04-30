#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <iostream>
#include <string>

class ChessPiece 
{
protected:
    std::string m_color;

public:
    ChessPiece(std::string color);
    virtual ~ChessPiece();
    virtual void Print() = 0;
    std::string GetColor();
};

#endif // CHESSPIECE_H
