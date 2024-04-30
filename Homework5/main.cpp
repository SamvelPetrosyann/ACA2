#include "Lion.h"
#include "Bear.h"
#include "Wolf.h"
#include "Dog.h"
#include "Fish.h"

int main()
{
    const int size = 5;
    Animals** animal = new Animals* [size];
    animal[0] = new Lion ();
    animal[1] = new Bear ();
    animal[2] = new Wolf ();
    animal[3] = new Dog ();
    animal[4] = new Fish ();
    for(int i = 0; i < size; ++i)
    {
        animal[i]->voice();    
    }
    for(int i = 0; i < size; ++i)
    {
        delete animal[i];
        animal[i] = nullptr;
    }
    delete[] animal;
    animal = nullptr;
    return 0;
}
