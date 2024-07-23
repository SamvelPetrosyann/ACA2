#include <iostream>
#include <sstream>
#include <vector>
#include <mutex>
#include <thread>

std::recursive_mutex mtx;
std::vector<long long> vec(50, -1);

long long fac(int n)
{
    if(n <= 1)
    {
        return 1;
    }
    
    if(-1 != vec[n])
    {
        return vec[n];
    }
    mtx.lock();
    long long res = vec[n] = fac(n - 1) * n;
    mtx.unlock();
    return res;
}

void control_fac(int n, std::stringstream& stream)
{
    auto start = std::chrono::high_resolution_clock::now();
    stream << "fac (" << n << ") = " << fac(n) << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    stream << "Elapsed time: " << elapsed.count() << " seconds" << std::endl;
}

int main()
{
    std::stringstream str1;
    std::stringstream str2;
    std::stringstream str3;
    std::stringstream str4;
    
    std::thread t1(control_fac, 10, std::ref(str1));
    std::thread t2(control_fac, 8, std::ref(str2));
    std::thread t3(control_fac, 6, std::ref(str3));
    std::thread t4(control_fac, 12, std::ref(str4));
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    
    std::cout << str1.str() << std::endl;
    std::cout << str2.str() << std::endl;
    std::cout << str3.str() << std::endl;
    std::cout << str4.str() << std::endl;
}