#include <iostream>
#include <string>
class Car 
{
    std::string make = "Mersedes-benz";
    std::string model = "E-Class" ;
    std::string color = "black";
    double motorvolume = 3.2;
    std::string gearbox = "Automatic";
    std::string steeringwheel = "left";
    public:
    void PrintMakeAndModel()
    {
        std::cout << make <<" "<< model << std::endl;
    }
    void PrintColor()
    {
        std::cout << color;
    }
    
};
int main()
{
    Car a;
    a.PrintMakeAndModel();
    a.PrintColor();
    return 0;
}