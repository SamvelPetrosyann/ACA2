#include <iostream>
#include <mutex>
#include <vector>
#include <thread>

int fib(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    
    return fib(n - 1) + fib(n - 2);
}

std::mutex mtx;

void fibonacci(std::vector<int>& vec, int n) 
{
   std::lock_guard<std::mutex> lock(mtx);

    if (vec.size() >= n)
    {
        std::cout <<" fibonacci " << n << " = "<<vec[n - 1] << std::endl; 
    }
    else
    {
        for (int i = vec.size(); i < n; ++i)
        {
            vec.push_back(fib(i));
        }
        
        std::cout <<" fibonacci " << n << " = "<<vec[n - 1] << std::endl; 
    }    
}

int main()
{
    std::vector<int> vec;
    
    std::thread t1(fibonacci, std::ref(vec), 5);
    std::thread t2(fibonacci, std::ref(vec), 4);
    std::thread t3(fibonacci, std::ref(vec), 9);
    std::thread t4(fibonacci, std::ref(vec), 6);
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    
    return 0;
}
