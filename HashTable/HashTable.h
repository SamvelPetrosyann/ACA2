#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "HashNode.h"

template <typename K, typename T>
class HashTable
{
private:    
    std::vector<std::list<HashNode<K, T>>> table;
    
    size_t HashFunc(const K& key, const std::vector<std::list<HashNode<K,T>>>& tab) const ;

    void Resize(int id);

public:
    HashTable();

    ~HashTable();
    
    void Insert(const K& key, const T& value);
    
    void Print() const;
    
    T Find(const K& key);
    
    void Remove(const K& key);
};

#endif // HASHTABLE_H