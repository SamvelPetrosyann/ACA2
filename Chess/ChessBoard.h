#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "Figures.h"
#include <vector>

class Figures;

class ChessBoard
{
private:
    const int m_size = 8;
    Figures*** mat;
    void InitializeControlledSquares(std::vector<std::vector<bool>>& bmat);
    bool IsKingInCheck(std::vector<std::vector<bool>>& bmat);
    bool IsSquareOccupied(int a, int b);
    bool IsBK(int a, int b);
    bool AreKingsNotAdjacent(int a, int b);
    void PlaceFigure(Figures* fig, int row, int col);

public:
    ChessBoard();
    ~ChessBoard();
    ChessBoard(const ChessBoard& other);
    ChessBoard& operator=(const ChessBoard& other);

    void AddFigure(Figures* fig, int a, int b);
    int GetSize() const;
    void PrintBoard() const;
    bool Analyze(std::vector<std::vector<bool>>& bmat);
    bool AnalyzeInOneMove(std::vector<std::vector<bool>>& bmat);
    bool AnalyzeTwoMoves(std::vector<std::vector<bool>>& bmat);
    void GameAnalyze(std::vector<std::vector<bool>>& bamt);


    friend class Figures;
    friend class Bishop;
    friend class Queen;
    friend class King;
    friend class Knight;
    friend class Pawn;
    friend class Rook;
};

#endif // CHESSBOARD_H
