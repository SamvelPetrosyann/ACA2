#ifndef ANIMALS_H
#define ANIMALS_H

#include <iostream>

class Animals
{
private:
    int m_age;
    double m_weight;

public:
    Animals(int age, double weight);
    ~Animals();
};

#endif // ANIMALS_H
