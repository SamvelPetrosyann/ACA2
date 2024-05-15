#ifndef AMPHIBIANS_H
#define AMPHIBIANS_H

#include "WaterAnimals.h"
#include "LandAnimals.h"

class Amphibians: public virtual WaterAnimals, public virtual LandAnimals
{
public:
    Amphibians(int age, double weight, std::string placelive, std::string breathing);
    ~Amphibians();
};

#endif // AMPHIBIANS_H