#include "ChessBoard.h"

ChessBoard::ChessBoard()
{
    mat = new Figures **[m_size];
    for (int i = 0; i < m_size; ++i)
    {
        mat[i] = new Figures *[m_size];
    }
    
    for(int i = 0; i < m_size; ++i)
    {
        for(int j = 0; j < m_size; ++j)
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

void ChessBoard::FillBoard(Figures *fig, int a, int b)
{
    assert(a >= 0 && a < m_size);
    assert(b >= 0 && b < m_size);
    mat[a][b] = fig;
}
bool ChessBoard::IsBusy(int a, int b)
{
    assert(a >= 0 && a < m_size);
    assert(b >= 0 && b < m_size);
    if(mat[a][b] == nullptr)
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
    assert(a >= 0 && a < m_size);
    assert(b >= 0 && b < m_size);
    if(mat[a][b]->GetName() == "BK")  
    {
        return true;
    } 
    return false;
 }

void ChessBoard::PrintBoard() const
 {
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            if (mat[i][j] != nullptr) {
                std::cout << mat[i][j]->GetName() << '\t'; 
            } else {
                std::cout <<  "-" <<'\t';
            }
        }
        std::cout << std::endl << std::endl << std::endl ;
    }
 }
 
 void ChessBoard::Test(bool** bmat, int a, int b)
 {
    assert(a >= 0 && a < m_size);
    assert(b >= 0 && b < m_size);
     bool temp = true;
     
    if(!bmat[a][b])
    {
        temp = false;
    }
    else
    { 
        if(a + 1 < m_size && b + 1 < m_size)
        {
            if(!bmat[a + 1][b + 1]) 
            {
                std::cout << "("<<a + 1 << ", " << b + 1 
                          << ") square is not controlled by any figures" << std::endl;
                temp = false;
            }
        }
        if(a + 1 < m_size )
        {
            if(!bmat[a + 1][b]) 
            {
                std::cout << "("<<a + 1 << ", " << b 
                          << ") square is not controlled by any figures" << std::endl;
                temp = false;
            }
        }
        if(a + 1 < m_size && b - 1 >= 0)
        {
            if(!bmat[a + 1][b - 1]) 
            {
                std::cout << "(" << a + 1 << ", " << b - 1 
                          << ") square is not controlled by any figures" << std::endl;
                temp = false;
            }
        }
        if(b + 1 < m_size)
        {
            if(!bmat[a][b + 1]) 
            {
                std::cout << "("<< a << ", " << b + 1 
                          << ") square is not controlled by any figures" << std::endl;
                temp = false;
            }
        }
        if(a < m_size && b - 1 >= 0)
        {
            if(!bmat[a + 1][b - 1]) 
            {
                std::cout << "(" <<a + 1 << ", " << b - 1 
                          << ") square is not controlled by any figures" << std::endl;
                temp = false;
            }
        }
        if(a - 1 >= 0 && b + 1 < m_size)
        {
            if(!bmat[a - 1][b + 1]) 
            {
                std::cout <<"("<<a - 1 << ", " << b + 1 
                          << ") square is not controlled by any figures" << std::endl;
                temp = false;
            }
        }
        if(a - 1 >= 0)
        {
            if(!bmat[a - 1][b]) 
            {
                std::cout << "("<<a - 1 << ", " << b 
                          << ") square is not controlled by any figures" << std::endl;
                temp = false;
            }
        }
        if(a - 1 >= 0 && b - 1 < m_size)
        {
            if(!bmat[a - 1][b - 1]) 
            {
                std::cout << "(" << a - 1 << ", " << b - 1 
                          <<") square is not controlled by any figures" << std::endl;
                temp = false;
            }
        }
    }
    if(temp)
    {
        std::cout << "Is a mat" << std::endl;
    }
    else
    {
        std::cout << "Is not a mat" << std::endl;
    }
    
    
 }
 
