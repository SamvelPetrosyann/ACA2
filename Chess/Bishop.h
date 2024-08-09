#ifndef BISHOP_H
#define BISHOP_H

#include "Figures.h"

class Bishop : public Figures
{
private:
    void ControledSquares(std::vector<std::vector<bool>>& bmat, ChessBoard& board, int a, int b) const override;
    bool IsMoveValid(ChessBoard& board, int row, int col, int newRow, int newCol) const override;
    Figures* Clone() const override;
public:
    Bishop(Color color);
    Bishop(std::string name);
    Bishop(const Bishop& other);
    Bishop& operator=(const Bishop& other);
    ~Bishop();

    friend class ChessBoard;
};

#endif // BISHOP_H
