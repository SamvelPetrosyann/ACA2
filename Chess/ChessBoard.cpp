#include "ChessBoard.h"
 
ChessBoard::ChessBoard()
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
            mat[i][j] = nullptr;
        }
    }
}

ChessBoard::~ChessBoard()
{
    for (int i = 0; i < m_size; ++i)
    {
        for (int j = 0; j < m_size; ++j)
        {
            delete mat[i][j];
        }
    }
    for (int i = 0; i < m_size; ++i)
    {
        delete[] mat[i];
    }
    delete[] mat;
}

void ChessBoard::FillBoard(Figures* fig, bool** bmat, int row, int col)
{
    assert(row >= 0 && row < m_size);
    assert(col >= 0 && col < m_size);
    assert(mat[row][col] == nullptr);
    mat[row][col] = fig;
}


void ChessBoard::TestBMat(bool** bmat)
{
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

bool ChessBoard::IsBusy(int a, int b)
{
    if (mat[a][b] == nullptr)
    {
        return false;
    }
    return true;
}
int ChessBoard::GetSize() const
{
    return m_size;
}

bool ChessBoard::IsBK(int a, int b)
{
    if (mat[a][b]->GetName() == "BK")
    {
        return true;
    }
    return false;
}

void ChessBoard::PrintBoard() const
{
    int count = 0;
    for (int i = 0; i < m_size; ++i)
    {
        std::cout << "  " << ++count << '\t';
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

bool ChessBoard::KingAreNotNeighbor(int a, int b)
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


void ChessBoard::Test(bool** bmat, int a, int b)
{

    assert(a >= 0 && a < m_size);
    assert(b >= 0 && b < m_size);
    assert(KingAreNotNeighbor(a, b) == true);
    Test(bmat);
    
    bool temp = true;

    if (!bmat[a][b])
    {
        temp = false;
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
                        std::cout << "(" << row << ", " << col
                            << ") square is not controlled by any figures" << std::endl;
                        temp = false;
                    }
                }
            }
        }
    }
    if (temp)
    {
        std::cout << "Is a mat" << std::endl;
    }
    else
    {
        std::cout << "Is not a mat" << std::endl;
    }

}
