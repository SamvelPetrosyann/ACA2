#include "Car.h"
#include <iostream>

Car::Car(bool gotoright, bool gotoleft, bool ismove)
    : m_gotoright(gotoright), m_gotoleft(gotoleft), m_ismove(ismove) {}

Car::~Car() {}

void Car::Direction() 
{
    if (m_gotoright) 
    {
        std::cout << "the car moves to the right" << std::endl;
    } 
    else if (m_gotoleft) 
    {
        std::cout << "the car moves to the left" << std::endl;
    } 
    else 
    {
        std::cout << "the car moves straight" << std::endl;
    }
}

void Car::Move() 
{
    if (m_ismove) 
    {
        std::cout << "the car is moving" << std::endl;
    } 
    else 
    {
        std::cout << "the car is standing still" << std::endl;
    }
}

