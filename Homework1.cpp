#include <iostream>
#include <string>

class Car
{
private:
    std::string m_model;
    std::string m_color;
    int m_price;

public:
    Car(std::string model, std::string color, int price) :
        m_model(model), m_color(color), m_price(price) {}

    ~Car() {}

    void Print()
    {
        std::cout << " model = " << m_model<< "," << " color = " << m_color
                 << "," << " price = " << m_price << std::endl;
    }
};

class Parking
{
private:
    int m_size;
    int m_occupied;
    Car** m_car;

public:
    Parking(int size) : m_size(size), m_occupied(0) 
    {
        m_car = new Car*[m_size];
    }

    ~Parking()
    {
        for (int i = 0; i < m_occupied; ++i)
        {
            delete m_car[i];
        }
        delete[] m_car;
    }

    Parking(const Parking& other) : m_size(other.m_size), m_occupied(other.m_occupied)
    {
        m_car = new Car*[m_size];
        for (int i = 0; i < m_occupied; ++i)
        {
            m_car[i] = new Car (*other.m_car[i]);
        }
    }

    Parking& operator=(const Parking& other)
    {
        if (this != &other)
        {
            for (int i = 0; i < m_occupied; ++i) 
            {
                delete m_car[i];
            }
            delete[] m_car;

            m_size = other.m_size;
            m_occupied = other.m_occupied;

            m_car = new Car*[m_size];
            
            for (int i = 0; i < m_occupied; ++i)
            {
                m_car[i] = new Car(*other.m_car[i]);
            }
        }
        return *this;
    }

    bool RegisterCar(Car *c)
    {
        if (m_occupied < m_size)
        {
            m_car[m_occupied] = c;
            m_occupied++;
            return true;
        }
        return false;
    }

    bool DeRegisterCar(Car *c)
    {
        for (int i = 0; i < m_occupied; ++i)
        {
            if (m_car[i] == c)
            {
                delete m_car[i];
                m_car[i] = nullptr;
                --m_occupied;
                m_car[i] = m_car[m_occupied];
                return true;
            }
        }
        return false;
    }

    void printCar() const
    {
        for (int i = 0; i < m_occupied; ++i)
        {
            (*m_car[i]).Print();
        }
    }
};

int main()
{
    Parking p(5);
    Car *a = new Car("Mercedes", "blue", 5000);
    Car *b = new Car("BMW", "black", 6000);
    Car *c = new Car("Nissan", "white", 7000);
    p.RegisterCar(a);
    p.RegisterCar(b);
    p.RegisterCar(c);
    p.DeRegisterCar(c);
    p.printCar();
    std::cout << "===============================" << std::endl;
    Parking p2 = p;
    p2.printCar();
    std::cout << "===============================" << std::endl;
    Parking p3(2);
    p3 = p;
    p3.printCar();
    delete a;
    a = nullptr;
    delete b;
    b = nullptr;
    delete c;
    c = nullptr;
    return 0;
}
