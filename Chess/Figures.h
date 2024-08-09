#ifndef FIGURES_H
#define FIGURES_H
#include <iostream>
#include <string>
#include <cassert> 
#include "ChessBoard.h"
#include <vector>

class ChessBoard;

enum class Color
{
    Black,
    White
};


class Figures
{
private:
    virtual void ControledSquares(std::vector<std::vector<bool>>& bmat, ChessBoard& board, int a, int b) const = 0;
    virtual void Move(ChessBoard& board, int row, int col, int newRow, int newCol);
    virtual bool IsMoveValid(ChessBoard& board, int row, int col, int newRow, int newCol) const = 0;
    virtual Figures* Clone() const = 0;
protected:
    Color m_color;
    std::string m_name;


public:
    Figures(Color color);
    Figures(std::string name);
    Figures(const Figures& other);
    Figures& operator=(const Figures& other);
    virtual ~Figures();
    std::string GetName() const;

    friend class ChessBoard;

};


#endif // FIGURES_H
