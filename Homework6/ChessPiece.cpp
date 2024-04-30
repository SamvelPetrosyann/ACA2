#include "ChessPiece.h"

ChessPiece::ChessPiece(std::string color) : m_color(color) {}

ChessPiece::~ChessPiece() {}

std::string ChessPiece::GetColor() 
{
    return m_color;
}
