#ifndef BEAR_H
#define BEAR_H

#include "Animals.h"

class Bear : public Animals 
{
public:
    Bear();
    ~Bear();
    void voice() override;
};

#endif // BEAR_H

