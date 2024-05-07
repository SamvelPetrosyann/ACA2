#ifndef WATERANIMALS_H
#define WATERANIMALS_H

#include "Animals.h"
#include <string>

class WaterAnimals: public virtual Animals
{
private:    
    std::string m_placelive;
    std::string m_breathing;

public:    
    WaterAnimals(int age, double weight, std::string placelive, std::string breathing);
    ~WaterAnimals();
};

#endif // WATERANIMALS_H
