#include "HashTable.h"

template <typename K, typename T>  
size_t HashTable<K,T>::HashFunc(const K& key, const std::vector<std::list<HashNode<K,T>>>& tab) const
{
    return std::hash<K>{}(key) % tab.size();
}

template <typename K, typename T>  
void HashTable<K,T>::Resize(int id)
{
    if(table.size() < table[id].size())
    {
        std::vector<std::list<HashNode<K,T>>> newTable(table.size() * 2);
        for(const auto& list : table)
        {
            for(const auto& node : list)
            {
                int newid = HashFunc(node.key, newTable);
                newTable[newid].emplace_back(node.key, node.value);
            }
        }
        std::swap(table, newTable);
    
    }
}

template <typename K, typename T>  
HashTable<K,T>::HashTable() : table(5)
{
    
}

template <typename K, typename T>  
HashTable<K,T>::~HashTable() {}

template <typename K, typename T>  
void HashTable<K,T>::Insert(const K& key, const T& value)
{
    int id = HashFunc(key, table);
    for(auto& node: table[id])
    {
        if(key == node.key)
        {
            node.value = value;
            return;
        }
        
    }
    table[id].emplace_back(key, value);
    
    Resize(id);
}

template <typename K, typename T>  
void HashTable<K,T>::Print() const
{
    for (size_t i = 0; i < table.size(); ++i)
    {
        std::cout << "List " << i << ": ";
        for (const auto& node : table[i])
        {
            std::cout << "(" << node.key << ", " << node.value << ") ";
        }
        std::cout << std::endl;
    }
}

template <typename K, typename T>  
T HashTable<K,T>::Find(const K& key)
{
    int id = HashFunc(key, table);
    for(const auto& node : table[id])
    {
        if(key == node.key)
        {
            return node.value;
        }
    }
    std::cout << "Key not found " ;
    return -1;
}

template <typename K, typename T>  
void HashTable<K,T>::Remove(const K& key)
{
    int id = HashFunc(key, table);
    auto& list = table[id];
    for(auto it = list.begin(); it != list.end(); ++it)
    {
        if(it->key == key)
        {
            list.erase(it);
            return;
        }
    }
}

template class HashTable<int, int>;
template class HashTable<std::string, int>;
template class HashTable<std::string, double>;