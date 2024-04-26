#include <iostream>
#include <string>
class Car
{
private:    
    std::string m_color;
    double m_enginevolume;
    std::string m_gearbox;
    std::string m_steeringwheel;
    int m_hp;
public:
    Car(std::string color,double enginevolume,
        std::string gearbox,std::string steeringwheel,int hp) :
             m_color(color),m_enginevolume(enginevolume),
             m_gearbox(gearbox),m_steeringwheel(steeringwheel),m_hp(hp)
        {
            
        }
    ~Car() {}
    void PrintCar()
    {
         std::cout << ",Color: " << m_color << ", Engine Volume: " << m_enginevolume
                   << ", Gearbox: " << m_gearbox << ", Steering Wheel: " << m_steeringwheel
                   << ", Horsepower: " << m_hp;
    }
    
};
class Mersedes: public Car
{
private:
    std::string m_make;
    
public:
    Mersedes(std::string color,double enginevolume,std::string gearbox,
             std::string steeringwheel,int hp,std::string make) : 
                Car(color,enginevolume,gearbox,steeringwheel,hp),m_make(make)
    {
            
    }
    ~Mersedes() {}
     void PrintMersedes()
    {
        std::cout << ", Make: " << m_make;
        Car::PrintCar();
    }
    
};

class BMW: public Car
{
    private:
    std::string m_make;
    
public:
    BMW(std::string color,double enginevolume,std::string gearbox,
             std::string steeringwheel,int hp,std::string make) : 
                Car(color,enginevolume,gearbox,steeringwheel,hp),m_make(make)
    {
            
    }
    ~BMW() {}
     void PrintBMW()
    {
        std::cout << ", Make: " << m_make;
        Car::PrintCar();
    }
   
};

class Toyota: public Car
{
private:
    std::string m_make;
    
public:
    Toyota(std::string color,double enginevolume,std::string gearbox,
             std::string steeringwheel,int hp,std::string make) : 
                Car(color,enginevolume,gearbox,steeringwheel,hp),m_make(make)
    {
            
    }
    ~Toyota() {}
    void PrintToyota()
    {
        std::cout << ", Make: " << m_make;
        Car::PrintCar();
    }    
};    
class E350:public Mersedes
{
private:
    std::string m_model;
    int m_year;
public: 
    E350(std::string color,double enginevolume,std::string gearbox,
             std::string steeringwheel,int hp,std::string make,std::string model, int year) : 
                Mersedes(color,enginevolume,gearbox,steeringwheel,hp, make),m_model(model),m_year(year)
    {
        
    }
    ~E350() {}
    void PrintE350()
    {
        std::cout << "Model: " << m_model << ", Year: " << m_year;
        Mersedes::PrintMersedes();
    }
};
class E60:public BMW
{
    private:
    std::string m_model;
    int m_year;
public: 
    E60(std::string color,double enginevolume,std::string gearbox,
             std::string steeringwheel,int hp,std::string make,std::string model, int year) : 
                BMW(color,enginevolume,gearbox,steeringwheel,hp, make),m_model(model),m_year(year)
    {
        
    }
    ~E60() {}
    void PrintE60()
    {
        std::cout << "Model: " << m_model << ", Year: " << m_year;
        BMW::PrintBMW();
    }
    
};
class Camry:public Toyota
{
    private:
    std::string m_model;
    int m_year;
public: 
    Camry(std::string color,double enginevolume,std::string gearbox,
             std::string steeringwheel,int hp,std::string make,std::string model, int year) : 
                Toyota(color,enginevolume,gearbox,steeringwheel,hp, make),m_model(model),m_year(year)
    {
        
    }
    ~Camry() {}
    void PrintCamry()
    {
        std::cout << "Model: " << m_model << ", Year: " << m_year;
        Toyota::PrintToyota();
    }
    
};
int main()
{
    E350 e350("Black", 3.5, "Automatic", "Left", 317, "Mercedes", "E350", 2022);
    e350.PrintE350();
    
    std::cout << std::endl;
    
    E60 e60("Black", 3.5, "Manual", "Left", 350, "BMW", "E60", 2021);
    e60.PrintE60();
    
    std::cout << std::endl;
    
    Camry camry("Silver", 2.5, "Automatic", "Right", 200, "Toyota", "Camry", 2019);
    camry.PrintCamry();
    
    return 0;
}