#include <iostream>
#include <unordered_map>
#include <string>

class Car 
{
    
private:
    int m_year;
    int m_hp;
    std::string m_name;
public:

    Car(int year, int hp, std::string name) : m_year(year), m_hp(hp), m_name(name)
    {
        
    }
    ~Car()
    {
        
    }
    
    int getYear() const { return m_year; }
    int getHP() const { return m_hp; }
    std::string getName() const { return m_name; }
    
    bool operator==(const Car& other) const
    {
        return m_year == other.m_year && m_hp == other.m_hp && m_name == other.m_name; 
    }
    
    struct Hash
    {
        std::size_t operator()(const Car& car) const
        {
            std::hash<int> yearHash;
            std::hash<int> hpHash;
            std::hash<std::string> nameHash;
            return yearHash(car.getYear()) ^ hpHash(car.getHP()) ^ nameHash(car.getName());
        }
    };
    
};

int main()
{
    Car car1(2010,350,"Mersedes");
    Car car2(2015,400,"Toyota");
    Car car3(2020,450,"BMW");
    
    std::unordered_map<Car,int,Car::Hash> unmap;
   
    
}