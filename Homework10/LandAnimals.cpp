#include "LandAnimals.h"

LandAnimals::LandAnimals(int age, double weight, std::string placelive, std::string breathing):
                    Animals(age, weight), m_placelive(placelive), m_breathing(breathing)
{
                        
}

LandAnimals::~LandAnimals()
{
    
}
