#ifndef MOVECAR_H
#define MOVECAR_H

class MoveCar 
{
public:
    MoveCar();
    virtual ~MoveCar();
    virtual void Direction() = 0;
    virtual void Move() = 0;
};

#endif // MOVECAR_H
