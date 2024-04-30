#ifndef WOLF_H
#define WOLF_H

#include "Animals.h"

class Wolf : public Animals 
{
public:
    Wolf();
    ~Wolf();
    void voice() override;
};

#endif // WOLF_H
