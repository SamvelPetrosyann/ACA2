
#include <iostream>

class Animals
{
    double m_weight;
    int m_age;
public:
    Animals()
    {
 
    }
    virtual ~Animals() 
    {

    }
    
};

class Lion: public Animals
{
public:
    Lion()
    {

    }
    ~Lion()
    {
       
    }
 
};

class Bear: public Animals
{
public:
    Bear()
    {
        
    }
    ~Bear()
    {
        
    }
};

class Wolf: public Animals
{
public:
    Wolf()
    {
        
    }
    ~Wolf()
    {
        
    }
    
};

class Zoo
{
private:
    static Zoo* s_obj;
    Animals** animals;
    const int m_size = 3;
    Zoo()
    {
        animals = new Animals*[m_size];
        for(int i = 0; i < m_size; ++i)
        {
            animals[i] = nullptr;
        }
    }
     ~Zoo() 
     {
        for (int i = 0; i < 3; ++i) 
        {
            delete animals[i];
        }
        delete[] animals;
    }
public:  
    Zoo(const Zoo&) = delete;
    Zoo& operator=(const Zoo&) = delete;
    static Zoo& GetObj()
    {
        if(s_obj == nullptr) 
        {
            s_obj = new Zoo();
        }
        return *s_obj;
    }
    void AddAnimal(Animals* animal, int a) 
    {
        if (a >= 0 && a < 3) 
        {
            animals[a] = animal;
        }
    }
};
Zoo* Zoo::s_obj = nullptr;

int main()
{
    Zoo& zoo = Zoo::GetObj();
    Animals* lion = new Lion();
    Animals* bear = new Bear();
    Animals* wolf = new Wolf();
    zoo.AddAnimal(lion,0);
    zoo.AddAnimal(bear,1);
    zoo.AddAnimal(wolf,2);
    return 0;
}
