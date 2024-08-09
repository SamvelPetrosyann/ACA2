#ifndef QUEEN_H
#define QUEEN_H

#include "Figures.h"

class Queen : public Figures
{
private:
    void ControledSquares(std::vector<std::vector<bool>>& bmat, ChessBoard& board, int a, int b)const override;
    bool IsMoveValid(ChessBoard& board, int row, int col, int newRow, int newCol)const override;
    Figures* Clone() const override;
public:
    Queen(Color color);
    Queen(std::string name);
    Queen(const Queen& other);
    Queen& operator=(const Queen& other);
    ~Queen();

    friend class ChessBoard;
};

#endif // QUEEN_H
