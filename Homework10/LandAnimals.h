#ifndef LANDANIMALS_H
#define LANDANIMALS_H

#include "Animals.h"
#include <string>

class LandAnimals: public virtual Animals
{
private:    
    std::string m_placelive;
    std::string m_breathing;

public:    
    LandAnimals(int age, double weight, std::string placelive, std::string breathing);
    ~LandAnimals();
};

#endif // LANDANIMALS_H
