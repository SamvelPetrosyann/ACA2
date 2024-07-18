#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

void sum(const std::vector<std::vector<int>>& matrix, std::atomic<int>& counter, int col)
{
    int temp = 0;
    for(int i = 0; i < matrix.size(); ++i)
    {
        temp += matrix[i][col];
    }
    counter += temp;
}

int main()
{
    const int size = 1000;
    std::vector<std::vector<int>> matrix(size);
    for(int i = 0; i < size; ++i)
    {
        matrix[i].resize(size,1);
    }
    std::atomic<int> counter(0);
    std::vector<std::thread> threads;
    for(int i = 0; i < size; ++i)
    {
        threads.push_back(std::thread(sum, std::ref(matrix), std::ref(counter), i));
    }
    
    for(auto& thread: threads)
    {
        thread.join();
    }
    std::cout << counter << std::endl;
    return 0;
}