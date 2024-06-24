#include "HashTable.cpp"

int main()
{
    HashTable<std::string, int> ht;
    ht.Insert("one", 10);
    ht.Insert("two", 20);
    ht.Insert("three", 30);
    ht.Insert("four", 40);
    ht.Insert("five", 50);
    ht.Insert("six", 60);
    
    int value = ht.Find("five");
    ht.Remove("six");
    std::cout << value << std::endl;
    ht.Print();

    return 0;
}