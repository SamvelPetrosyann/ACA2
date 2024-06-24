#include  "HashNode.h"
template <typename K, typename T>
HashNode<K,T>::HashNode(const K& key, const T& value) : key(key), value(value)
{
    
}

template class HashNode<int, int>;
template class HashNode<std::string, int>;
template class HashNode<std::string, double>;
    