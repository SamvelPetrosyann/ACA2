#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

std::queue<int> buffer;
const unsigned int maxBufferSize = 10;
std::mutex mtx;
std::condition_variable producer;
std::condition_variable consumer;

void Producer(int id)
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); 

        std::unique_lock<std::mutex> lock(mtx);
        producer.wait(lock, [] { return buffer.size() < maxBufferSize; });

        int data = 20 * id;
        buffer.push(data);
        std::cout << "Producer " << id << " produced " << data << " " << buffer.size() << std::endl;

        consumer.notify_one();
    }
}

void Consumer(int id) 
{
    while (true) 
    {
        std::unique_lock<std::mutex> lock(mtx);
        consumer.wait(lock, [] { return !buffer.empty(); });
        int data = buffer.front();
        buffer.pop();
        std::cout << "Consumer " << id << " consumed " << data << " " << buffer.size() << std::endl;

        producer.notify_one();

        std::this_thread::sleep_for(std::chrono::milliseconds(500)); 
    }
}

int main()
{
    std::thread producers[2];
    std::thread consumers[2];
    
    for (int i = 0; i < 2; ++i) 
    {
        producers[i] = std::thread(Producer, i);
        consumers[i] = std::thread(Consumer, i);
    }

    for (int i = 0; i < 2; ++i) 
    {
        producers[i].join();
        consumers[i].join();
    }

    return 0;
}
