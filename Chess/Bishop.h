#ifndef BISHOP_H
#define BISHOP_H

#include "Figures.h"

class Bishop : public Figures
{
public:
    Bishop(Color color,std::string name);
    ~Bishop();
    void ControledSquares(bool** bmat, ChessBoard& board, int a, int b) override;
};

#endif // BISHOP_H
