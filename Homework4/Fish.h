#ifndef FISH_H
#define FISH_H

#include "Animals.h"

class Fish : public Animals 
{
public:
    Fish();
    ~Fish();
    void voice() override;
};

#endif // FISH_H
