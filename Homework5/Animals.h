#ifndef ANIMALS_H
#define ANIMALS_H

class Animals 
{
private:
    double weight;
    int age;    
public:
    Animals();
    virtual ~Animals();
    virtual void voice() = 0;
};

#endif // ANIMALS_H
