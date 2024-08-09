#ifndef PAWN_H
#define PAWN_H

#include "Figures.h"

class Pawn : public Figures
{
private:
    void ControledSquares(std::vector<std::vector<bool>>& bmat, ChessBoard& board, int a, int b)const override;
    bool IsMoveValid(ChessBoard& board, int row, int col, int newRow, int newCol)const override;
    Figures* Clone() const override;
public:
    Pawn(Color color);
    Pawn(std::string name);
    Pawn(const Pawn& other);
    Pawn& operator=(const Pawn& other);
    ~Pawn();

    friend class ChessBoard;
};

#endif // PAWN_H
