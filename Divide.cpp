#include <iostream>
#include <cassert>

int Divide(int a, int b)
{
    assert(b != 0);
    if(a < b)
    {
        return 0;
    }
    
    int num1;
    int num2 = 1;
    int temp;
    
    while(b * num2 < a)
    {
        num2 = num2 << 1;
    }
    
    if(num2 == 1)
    {
        return 1; 
    }
    
    num1 = num2 >> 1;  
    
    while(num1 <= num2)
    {
        if(num2 - 1 == num1)
        {
            if(num2 * b > a)
            {
                return num1;
            }
            else
            {
                return num2;
            }
        }
        if(b * ((num2 + num1) >> 1) > a)
        {
            num2 = (num2 + num1) >> 1;
        }
        else if(b * ((num2 + num1) >> 1) < a)
        {
            num1 = (num2 + num1) >> 1;
        }
        else
        {
            return (num2 + num1) >> 1;
        }
    }
    
    return num2;
}

int main()
{
    int a;
    std::cin >> a;
    int b;
    std::cin >> b;
    
    std::cout << Divide(a, b) << std::endl;
    
    return 0;
    
}