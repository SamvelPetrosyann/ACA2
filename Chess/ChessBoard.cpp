#include "ChessBoard.h"

void FillBMat(std::vector<std::vector<bool>>& bmat, int size)
{
    for (int k = 0; k < size; ++k)
    {
        for (int t = 0; t < size; ++t)
        {
            bmat[k][t] = false;
        }
    }
}



ChessBoard::ChessBoard() : mat(nullptr)
{
    // Allocate memory for the chessboard
    mat = new Figures * *[m_size];
    for (int i = 0; i < m_size; ++i)
    {
        mat[i] = new Figures * [m_size];
        for (int j = 0; j < m_size; ++j)
        {
            mat[i][j] = nullptr;
        }
    }
}

ChessBoard::ChessBoard(const ChessBoard& other)
{
    mat = new Figures * *[m_size];
    for (int i = 0; i < m_size; ++i)
    {
        mat[i] = new Figures * [m_size];
    }

    for (int i = 0; i < m_size; ++i)
    {
        for (int j = 0; j < m_size; ++j)
        {
            mat[i][j] = (other.mat[i][j] != nullptr) ? other.mat[i][j]->Clone() : nullptr;
        }
    }
}

ChessBoard::~ChessBoard()
{
    // Deallocate memory for each Figures object and the array itself
    for (int i = 0; i < m_size; ++i)
    {
        for (int j = 0; j < m_size; ++j)
        {
            delete mat[i][j];
        }
        delete[] mat[i];
    }
    delete[] mat;
}

ChessBoard& ChessBoard::operator=(const ChessBoard& other)
{
    if (this == &other)
    {
        return *this;
    }

    for (int i = 0; i < m_size; ++i)
    {
        for (int j = 0; j < m_size; ++j)
        {
            delete mat[i][j];
        }
        delete[] mat[i];
    }
    delete[] mat;

    mat = new Figures * *[m_size];
    for (int i = 0; i < m_size; ++i)
    {
        mat[i] = new Figures * [m_size];
    }

    for (int i = 0; i < m_size; ++i)
    {
        for (int j = 0; j < m_size; ++j)
        {

            if (other.mat[i][j] == nullptr)
            {
                mat[i][j] = nullptr;
            }
            else
            {
                mat[i][j] = other.mat[i][j]->Clone();
            }
        }
    }

    return *this;
}

void ChessBoard::AddFigure(Figures* fig, int row, int col)
{
    assert(row >= 0 && row < m_size);
    assert(col >= 0 && col < m_size);
    assert(mat[row][col] == nullptr);
    mat[row][col] = fig;
}

void ChessBoard::PlaceFigure(Figures* fig, int row, int col)
{
    assert(row >= 0 && row < m_size);
    assert(col >= 0 && col < m_size);
    mat[row][col] = fig;
}

void ChessBoard::InitializeControlledSquares(std::vector<std::vector<bool>>& bmat)
{
    // Initialize the bmat matrix
    FillBMat(bmat, m_size);

    // Calculate controlled squares for each non-king figure
    for (int i = 0; i < m_size; ++i)
    {
        for (int j = 0; j < m_size; ++j)
        {
            if (mat[i][j] != nullptr && mat[i][j]->GetName() != "BK")
            {
                mat[i][j]->ControledSquares(bmat, *this, i, j);
            }
        }
    }
}

bool ChessBoard::IsSquareOccupied(int a, int b)
{
    return mat[a][b] != nullptr;
}

bool ChessBoard::IsBK(int a, int b)
{
    return mat[a][b] != nullptr && mat[a][b]->GetName() == "BK";
}

int ChessBoard::GetSize() const
{
    return m_size;
}

void ChessBoard::PrintBoard() const
{
    int count = 8;
    for (int i = 0; i < m_size; ++i)
    {
        std::cout << "  " << count-- << '\t';
        for (int j = 0; j < m_size; ++j)
        {
            if (mat[i][j] != nullptr)
            {
                std::cout << mat[i][j]->GetName() << '\t';
            }
            else
            {
                std::cout << "-" << '\t';
            }
        }
        std::cout << std::endl << std::endl << std::endl;
    }
    std::cout << "  \t";
    for (char i = 'A'; i <= 'H'; ++i)
    {
        std::cout << i << '\t';
    }
    std::cout << std::endl << std::endl;
}

bool ChessBoard::AreKingsNotAdjacent(int a, int b)
{
    for (int i = a - 1; i <= a + 1; ++i)
    {
        for (int j = b - 1; j <= b + 1; ++j)
        {
            if (i == a && j == b) continue;

            if (i >= 0 && i < m_size && j >= 0 && j < m_size && mat[i][j] != nullptr && mat[i][j]->GetName() == "WK")
            {
                return false;
            }
        }
    }
    return true;
}


bool ChessBoard::Analyze(std::vector<std::vector<bool>>& bmat)
{
    int a = -1, b = -1;

    // Find the coordinates of the black king (BK)
    for (int i = 0; i < m_size; ++i)
    {
        for (int j = 0; j < m_size; ++j)
        {
            if (mat[i][j] != nullptr && mat[i][j]->GetName() == "BK")
            {
                a = i;
                b = j;
                break;
            }
        }
        if (a != -1)
        {
            break;
        }
    }

    // Assert that the black king is not neighboring a white king (WK)
    assert(AreKingsNotAdjacent(a, b));

    // Generate the controlled squares matrix
    InitializeControlledSquares(bmat);

    // Check if the black king is in check
    if (!IsKingInCheck(bmat))
    {
        return false;
    }
    else
    {
        int row;
        int col;

        for (int i = -1; i <= 1; ++i)
        {
            for (int j = -1; j <= 1; ++j)
            {

                if (i == 0 && j == 0) continue;

                row = a + i;
                col = b + j;
                if (row >= 0 && row < m_size && col >= 0 && col < m_size)
                {
                    if (!bmat[row][col])
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

bool ChessBoard::IsKingInCheck(std::vector<std::vector<bool>>& bmat)
{
    // Check if the black king (BK) is in check
    for (int i = 0; i < m_size; ++i)
    {
        for (int j = 0; j < m_size; ++j)
        {
            if (mat[i][j] != nullptr && mat[i][j]->GetName() == "BK")
            {
                return bmat[i][j]; // Return true if BK is in a controlled square
            }
        }
    }
    return false;
}

bool ChessBoard::AnalyzeInOneMove(std::vector<std::vector<bool>>& bmat)
{
    // Check if opponent's king is already in check
    if (IsKingInCheck(bmat))
    {
        return false; // No valid moves needed, opponent is in checkmate
    }

    ChessBoard board = *this;
    // Iterate over all pieces on the board
    for (int i = 0; i < m_size; ++i)
    {
        for (int j = 0; j < m_size; ++j)
        {
            // Check if there is a piece and it's not the black king
            if (mat[i][j] != nullptr)
            {
                if (mat[i][j]->GetName() != "BK" && mat[i][j]->GetName() != "WK")
                {
                    // Try all possible destination squares
                    for (int k = 0; k < m_size; ++k)
                    {
                        for (int t = 0; t < m_size; ++t)
                        {
                            // Check if the move is valid
                            if (mat[i][j]->IsMoveValid(*this, i, j, k, t))
                            {
                                // Execute the move
                                FillBMat(bmat, m_size); // Clear the controlled squares matrix
                                mat[i][j]->Move(*this, i, j, k, t); // Make the move

                                // Check if opponent's king is now in check
                                if (Analyze(bmat))
                                {
                                    return true; // Valid move found
                                }

                                *this = board;
                            }
                        }
                    }
                }
            }
        }
    }

    return false; // No valid moves found
}

bool ChessBoard::AnalyzeTwoMoves(std::vector<std::vector<bool>>& bmat)
{
    if (IsKingInCheck(bmat))
    {
        return false;
    }

    int row = -1;
    int col = -1;

    // Find the position of the black king (BK)
    for (int i = 0; i < m_size; ++i)
    {
        for (int j = 0; j < m_size; ++j)
        {
            if (mat[i][j] != nullptr && mat[i][j]->GetName() == "BK")
            {
                row = i;
                col = j;
                break;
            }
        }
        if (row != -1)
        {
            break;
        }
    }

    ChessBoard originalBoard = *this;
    ChessBoard tempBoard;

    for (int i = 0; i < m_size; ++i)
    {
        for (int j = 0; j < m_size; ++j)
        {
            if (mat[i][j] != nullptr && mat[i][j]->GetName() != "BK")
            {
                for (int k = 0; k < m_size; ++k)
                {
                    for (int t = 0; t < m_size; ++t)
                    {
                        if (mat[i][j]->IsMoveValid(*this, i, j, k, t))
                        {
                            FillBMat(bmat, m_size);
                            mat[i][j]->Move(*this, i, j, k, t);
                            tempBoard = *this;
                            InitializeControlledSquares(bmat);

                            for (int p = -1; p <= 1; ++p)
                            {
                                for (int q = -1; q <= 1; ++q)
                                {
                                    if (p == 0 && q == 0)
                                    {
                                        continue;
                                    }
                                    int newRow = row + p;
                                    int newCol = col + q;

                                    if (newRow >= 0 && newRow < m_size && newCol >= 0 && newCol < m_size)
                                    {
                                        if (mat[row][col] != nullptr &&
                                            mat[row][col]->IsMoveValid(*this, row, col, newRow, newCol) &&
                                            !bmat[newRow][newCol])
                                        {
                                            mat[row][col]->Move(*this, row, col, newRow, newCol);

                                            if (AnalyzeInOneMove(bmat))
                                            {
                                                tempBoard.PrintBoard();
                                                std::cout << "___________________________________________________________________" << std::endl << std::endl;
                                                PrintBoard(); // Print the board state
                                                *this = originalBoard;
                                                return true;
                                            }

                                            *this = tempBoard;
                                        }
                                    }
                                }
                            }

                            *this = originalBoard; // Restore original board before the next move
                        }
                    }
                }
            }
        }
    }

    return false;
}

void ChessBoard::GameAnalyze(std::vector<std::vector<bool>>& bmat)
{
    if (Analyze(bmat))
    {
        std::cout << "Checkmate!" << std::endl;
    }
    else if (AnalyzeInOneMove(bmat))
    {
        PrintBoard();
        std::cout << "Checkmate possible in one step!" << std::endl;
    }
    else if (AnalyzeTwoMoves(bmat))
    {
        std::cout << "Checkmate found after two moves!" << std::endl;
    }
    else
    {
        std::cout << "No Checkmate possible after two moves" << std::endl;
    }
}

