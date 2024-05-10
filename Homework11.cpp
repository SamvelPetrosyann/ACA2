#include <iostream>
#include <string>
   
class Animals
{  
    std::string m_name;
    int m_age;
public:
    static int count;

    Animals()
    {
        count++;
    }

    virtual ~Animals() 
    {
        
    }
};

class Lion: public Animals
{
public:
    Lion() {}

    ~Lion() {}

};

class Bear: public Animals
{
public:
    Bear() {}

    ~Bear() {}

};

class Wolf: public Animals
{
public:
    Wolf() {}

    ~Wolf() {}

};

class Dog: public Animals
{
public:
    Dog() {}

    ~Dog() {}

};

class Fish: public Animals
{
public:
    Fish() {}

    ~Fish() {}

};

int Animals::count = 0;

int main()
{
    
    const int size = 5;
    Animals** animal = new Animals* [size];
    animal[0] = new Lion ();
    animal[1] = new Bear ();
    animal[2] = new Wolf ();
    animal[3] = new Dog ();
    animal[4] = new Fish ();
    
    std::cout<< "Total number of Animals: " << Animals::count << std::endl;
    
    for(int i = 0; i < size; ++i)
    {
        delete animal[i];
    }
    delete[] animal;
    
    return 0;
}
