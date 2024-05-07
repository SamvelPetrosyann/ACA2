#include <iostream>
#include "Animals.h"
#include "WaterAnimals.h"
#include "LandAnimals.h"
#include "Amphibians.h"

int main()
{
    Animals a(4, 6);
    WaterAnimals fish(2, 5, "lake", "gills");
    LandAnimals dog(4, 20, "land", "lungs");
    Amphibians frog(1, 0.1, "lake and land", "lungs and gills");

    std::cout << "Size of Animals: " << sizeof(a) << std::endl;
    std::cout << "Size of WaterAnimals: " << sizeof(fish) << std::endl;
    std::cout << "Size of LandAnimals: " << sizeof(dog) << std::endl;
    std::cout << "Size of Amphibians: " << sizeof(frog) << std::endl;

    return 0;
}
