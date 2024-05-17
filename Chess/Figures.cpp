#include "Figures.h"

Figures::Figures(Color color,std::string name) : m_color(color), m_name(name) {}

Figures::~Figures() {}

std::string Figures::GetName() const
{
    return m_name;
}

