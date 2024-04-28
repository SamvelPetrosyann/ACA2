#include <iostream>
#include <string>
class Head
{
    int m_numear;
    int m_numnose; 
    int m_numeye;
    int m_nummouth;
 public:   
    Head()
    {
        
    }
    ~Head()
    {
        
    }
};
class Body
{
   int m_numpaw;
   int m_numfoot;
public:   
   Body()
   {
       
   }
   ~Body()
   {
       
   }
};    
class Animals
{
    Head m_head;
    Body m_body;
    std::string m_name;
    int m_age;
public:
    Animals()
    {
 
    }
    virtual ~Animals() 
    {

    }
    virtual void voice()
    {
        std::cout << "I am an Animal" << std::endl;
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
    void voice () override
    {
         std::cout << "I am an Lion" << std::endl;    
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
    void voice () override
    {
         std::cout << "I am an Bear" << std::endl;    
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
    void voice () override
    {
         std::cout << "I am an Wolf" << std::endl;    
    }    
};

class Dog: public Animals
{
public:
    Dog()
    {
        
    }
    ~Dog()
    {
        
    }
    void voice () override
    {
        std::cout << "I am an Dog" << std::endl;    
    }    
};

class Fish: public Animals
{
public:
    Fish()
    {
        
    }
    ~Fish()
    {
      
    }
    void voice () override
    {
    std::cout << "I am an Fish" << std::endl;     
    }
};

int main()
{
    const int size = 5;
    Animals** animal = new Animals* [size];
    animal[0] = new Lion ();
    animal[1] = new Bear ();
    animal[2] = new Wolf ();
    animal[3] = new Dog ();
    animal[4] = new Fish ();
    for(int i = 0; i < size; ++i)
    {
        animal[i]->voice();    
    }
    for(int i = 0; i < size; ++i)
    {
        delete animal[i];
    }
    delete[] animal;
    return 0;
}