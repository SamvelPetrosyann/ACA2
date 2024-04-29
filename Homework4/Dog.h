#ifndef DOG_H
#define DOG_H

#include "Animals.h"

class Dog : public Animals 
{
public:
    Dog();
    ~Dog();
    void voice() override;
};

#endif // DOG_H
