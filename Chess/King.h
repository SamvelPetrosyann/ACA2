#ifndef KING_H
#define KING_H

#include "Figures.h"

class King : public Figures
{
private:
    void ControledSquares(std::vector<std::vector<bool>>& bmat, ChessBoard& board, int a, int b) const override;
    bool IsMoveValid(ChessBoard& board, int row, int col, int newRow, int newCol) const;
    Figures* Clone() const override;
    bool BKMove(ChessBoard& board, bool** bmat, int row, int col, int newRow, int newCol);
    bool BKMoveIsValid(ChessBoard& board, bool** bmat, int row, int col, int newRow, int newCol);
public:
    King(Color color);
    King(std::string name);
    King(const King& other);
    King& operator=(const King& other);
    ~King();

    friend class ChessBoard;
};

#endif // KING_H
