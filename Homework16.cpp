#include <iostream>
#include <string>
#include <algorithm>

class Animals
{

    std::string* m_name;
    int m_age;
public:
    explicit Animals(std::string name, int age) : m_age(age)  
    {
        m_name = new std::string(name);    
    }
    virtual ~Animals() 
    {
        delete m_name;
    }
    Animals(Animals&& other) : m_name(other.m_name), m_age(other.m_age) 
    {
        other.m_name = nullptr;
    }
    virtual std::string GetName()
    {
        return *m_name;
    }
    virtual bool operator>(const Animals& other) const 
    {
        return m_age > other.m_age;
    }

    virtual bool operator<(const Animals& other) const 
    {
        return m_age < other.m_age;
    }

    virtual bool operator==(const Animals& other) const 
    {
        return m_age == other.m_age;
    }
};

class Lion : public Animals 
{
public:
    explicit Lion(const std::string& name, int age) : Animals(name, age) {}
    ~Lion() {}
};

class Bear : public Animals
{
public:
    explicit Bear(const std::string& name, int age) : Animals(name, age) {}
    ~Bear() {}
};

class Wolf : public Animals
{
public:
    explicit Wolf(const std::string& name, int age) : Animals(name, age) {}
    ~Wolf(){}
};

class Dog : public Animals
{
public:
    explicit Dog(const std::string& name, int age) : Animals(name, age) {}
    ~Dog() {}
};

class Fish : public Animals
{
public:
    explicit Fish(const std::string& name, int age) : Animals(name, age) {}
    ~Fish() {}
};
int main()
{
    const int size = 5;
    Animals** animal = new Animals*[size];
    animal[0] = new Lion("lion", 5);
    animal[1] = new Bear("bear", 10);
    animal[2] = new Wolf("wolf", 3);
    animal[3] = new Dog("dog", 7);
    animal[4] = new Fish("fish", 1);
    
    std::sort(animal, animal + size, std::greater<Animals*>());
    
    for (int i = 0; i < 3; ++i) 
    {
        std::cout << animal[i]->GetName() << std::endl;
    }
    
    Animals* movedAnimal = std::move(animal[0]);
    for (int i = 0; i < size; ++i) {
        delete animal[i];
    }
    delete[] animal;
    return 0;
}
