#include <iostream>
#include <string>

class Engine {
private:
    double m_volume;
    int m_cylinders;

public:
    Engine(int volume, int cylinders) : m_volume(volume), m_cylinders(cylinders) {}
    ~Engine() {}

    void PrintEngine() {
        std::cout << " Motor " <<" volume = " << m_volume << "," << " cylinders = " << m_cylinders << ",";
    }
};

class Gearbox {
private:
    std::string m_gtype;
    std::string m_type;

public:
    Gearbox(std::string gtype, std::string type) : m_gtype(gtype), m_type(type) {}
    ~Gearbox() {}

    void PrintGearbox() {
        std::cout << " Gearbox " <<" gearbox type = " << m_gtype << " type = " << m_type;
    }
};

class Car {
private:
    std::string m_model;
    std::string m_color;
    Engine m_motor;
    Gearbox m_gearbox;
    int m_price;

public:
    Car(std::string model, std::string color, Engine motor, Gearbox gearbox, int price) :
        m_model(model), m_color(color), m_motor(motor), m_gearbox(gearbox), m_price(price) {}

    ~Car() {}

    void Print() {
        std::cout << " model = " << m_model << "," << " color = " 
                  << m_color << "," << " price = " << m_price <<",";
        m_motor.PrintEngine();
        m_gearbox.PrintGearbox();
    }
};

int main() {
    Gearbox a("Automatic", "Variator");
    Engine p(3.5, 8);
    Car d("Mersedes", "Blue", p, a, 10000);
    d.Print();
    return 0;
}
