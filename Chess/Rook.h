#ifndef ROOK_H
#define ROOK_H

#include "Figures.h"

class Rook : public Figures
{
private:
    bool IsMoveValid(ChessBoard& board, int row, int col, int newRow, int newCol) const override;
    void ControledSquares(std::vector<std::vector<bool>>& bmat, ChessBoard& board, int a, int b) const override;
    Figures* Clone() const override;
public:
    Rook(Color color);
    Rook(std::string name);
    Rook(const Rook& other);
    Rook& operator=(const Rook& other);
    ~Rook();

    friend class ChessBoard;
};

#endif // ROOK_H
