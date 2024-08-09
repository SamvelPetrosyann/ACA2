#ifndef KNIGHT_H
#define KNIGHT_H

#include "Figures.h"

class Knight : public Figures
{
private:
    void ControledSquares(std::vector<std::vector<bool>>& bmat, ChessBoard& board, int a, int b) const override;
    bool IsMoveValid(ChessBoard& board, int row, int col, int newRow, int newCol) const;
    Figures* Clone() const override;
public:
    Knight(Color color);
    Knight(std::string name);
    Knight(const Knight& other);
    Knight& operator=(const Knight& other);
    ~Knight();

    friend class ChessBoard;
};

#endif // KNIGHT_H
