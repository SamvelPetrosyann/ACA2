#include "Figures.h"

Figures::Figures(Color color) : m_color(color) {}

Figures::~Figures() {}

std::string Figures::GetName() const
{
    return m_name;
}

