#include "Amphibians.h"

Amphibians::Amphibians(int age, double weight, std::string placelive, std::string breathing):
                    Animals(age, weight), 
                    WaterAnimals(age, weight, placelive, breathing),
                    LandAnimals(age, weight, placelive, breathing)
{ 
        
}

Amphibians::~Amphibians()
{
    
}
