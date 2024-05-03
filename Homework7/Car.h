#ifndef CAR_H
#define CAR_H

#include "MoveCar.h"

class Car : public MoveCar 
{
    bool m_gotoright;
    bool m_gotoleft;
    bool m_ismove;

public:
    Car(bool gotoright, bool gotoleft, bool ismove);
    ~Car();
    void Direction() override;
    void Move() override;
};

#endif // CAR_H
