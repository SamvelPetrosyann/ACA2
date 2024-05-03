#include "Car.h"

int main() 
{
    MoveCar* ptr = new Car(true, false, true);
    ptr->Move();
    ptr->Direction();
    delete ptr;
    return 0;
}
