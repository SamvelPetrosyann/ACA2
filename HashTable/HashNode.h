#ifndef HASHNODE_H
#define HASHNODE_H
#include <iostream>
#include <vector>
#include <list>

template <typename K, typename T>
class HashNode
{
public:
    K key;
    T value;
    HashNode(const K& key, const T& value);
};

#endif // HASHNODE_H