#ifndef ANIMALS_H
#define ANIMALS_H

class Animals 
{
private:
    double m_weight;
    int m_age;    
public:
    Animals();
    virtual ~Animals();
    virtual void voice() = 0;
};

#endif // ANIMALS_H
