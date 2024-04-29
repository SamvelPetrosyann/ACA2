#ifndef LION_H
#define LION_H

#include "Animals.h"

class Lion : public Animals 
{
public:
    Lion();
    ~Lion();
    void voice() override;
};

#endif // LION_H
