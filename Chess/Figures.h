#ifndef FIGURES_H
#define FIGURES_H
#include <iostream>
#include <string>
#include <cassert> 
#include "ChessBoard.h"

class ChessBoard;

enum class Color
{
    Black,
    White
};


class Figures
{
protected:
    Color m_color;
    std::string m_name;


public:
    Figures(Color color);
    virtual ~Figures();
    virtual void ControledSquares(bool** bmat, ChessBoard& board, int a, int b) = 0;
    std::string GetName() const;

};


#endif // FIGURES_H
