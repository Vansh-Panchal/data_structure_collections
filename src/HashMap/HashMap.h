#ifndef HASHMAP_H
#define HASHMAP_H

#include <string>
#include "../DynamicArray/DynamicArray.h"
#include "../LinkedList/LinkedList.h"

template<typename K, typename V>
struct Entry
{
    K key;
    V value;

    Entry()
    {
    }

    Entry(const K& newKey,const V& newValue)
    {
        key = newKey;
        value = newValue;
    }
};

template<typename K>
class DefaultHasher
{
public:

    int hash(const K& key,int bucketCount) const
    {
        return 0;
    }
};

template<>
class DefaultHasher<int>
{
public:

    int hash(const int& key,int bucketCount) const
    {
        int value = key;

        if(value < 0)
        {
            value = -value;
        }

        return value % bucketCount;
    }
};

template<>
class DefaultHasher<char>
{
public:

    int hash(const char& key,int bucketCount) const
    {
        return ((int)key) % bucketCount;
    }
};

template<>
class DefaultHasher<bool>
{
public:

    int hash(const bool& key,int bucketCount) const
    {
        return (key ? 1 : 0) % bucketCount;
    }
};

template<>
class DefaultHasher<long>
{
public:

    int hash(const long& key,int bucketCount) const
    {
        long value = key;

        if(value < 0)
        {
            value = -value;
        }

        return value % bucketCount;
    }
};

template<>
class DefaultHasher<long long>
{
public:

    int hash(const long long& key,int bucketCount) const
    {
        long long value = key;

        if(value < 0)
        {
            value = -value;
        }

        return value % bucketCount;
    }
};

template<>
class DefaultHasher<float>
{
public:

    int hash(const float& key,int bucketCount) const
    {
        float value = key;
        if(value < 0)
        {
            value = -value;
        }
        int scaledValue = static_cast<int>(value * 1000);

        return scaledValue % bucketCount;
    }
};

template<>
class DefaultHasher<std::string>
{
public:

    int hash(const std::string& key, int bucketCount) const
    {
        unsigned long hash = 0;

        for(int i = 0; i < key.length(); i++)
        {
            hash = hash * 31 + key[i];
        }

        return hash % bucketCount;
    }
};

template<typename K, typename V>
class HashMap
{
private:

    DynamicArray<LinkedList<Entry<K,V>>> buckets;

    int currentSize;

    int bucketCount;

    DefaultHasher<K> hasher;

    int hashFunction(const K& key) const;

public:

    HashMap();

    HashMap(const HashMap& other);

    HashMap& operator=(const HashMap& other);

    ~HashMap();

    void put(const K& key,const V& value);

    V get(const K& key) const;

    bool containsKey(const K& key) const;

    void remove(const K& key);

    void clear();

    int size() const;

    bool isEmpty() const;
};

template<typename K, typename V>
HashMap<K,V>::HashMap()
{
    bucketCount = 4;
    currentSize = 0;

    for(int i = 0; i < bucketCount; i++)
    {
        buckets.append(LinkedList<Entry<K,V>>());
    }
}

template<typename K, typename V>
HashMap<K,V>::HashMap(const HashMap& other)
{
    buckets = other.buckets;
    currentSize = other.currentSize;
    bucketCount = other.bucketCount;
}

template<typename K, typename V>
HashMap<K,V>& HashMap<K,V>::operator=(const HashMap& other)
{
    if(this != &other)
    {
        buckets = other.buckets;
        currentSize = other.currentSize;
        bucketCount = other.bucketCount;
    }

    return *this;
}

template<typename K, typename V>
HashMap<K,V>::~HashMap()
{
}

template<typename K, typename V>
int HashMap<K,V>::hashFunction(const K& key) const
{
    return hasher.hash(key,bucketCount);
}

template<typename K, typename V>
int HashMap<K,V>::size() const
{
    return currentSize;
}

template<typename K, typename V>
bool HashMap<K,V>::isEmpty() const
{
    return currentSize == 0;
}

template<typename K, typename V>
void HashMap<K,V>::put(const K& key,const V& value)
{
    int index = hashFunction(key);

    LinkedList<Entry<K,V>>& bucket =
        buckets.get(index);

    for(int i = 0; i < bucket.getSize(); i++)
    {
        if(bucket.get(i).key == key)
        {
            bucket.get(i).value = value;
            return;
        }
    }

    bucket.pushBack(
        Entry<K,V>(key,value)
    );

    currentSize++;
}

template<typename K, typename V>
V HashMap<K,V>::get(const K& key) const
{
    int index = hashFunction(key);

    const LinkedList<Entry<K,V>>& bucket =
        buckets.get(index);

    for(int i = 0; i < bucket.getSize(); i++)
    {
        if(bucket.get(i).key == key)
        {
            return bucket.get(i).value;
        }
    }

    throw std::runtime_error("Key not found");
}

template<typename K, typename V>
bool HashMap<K,V>::containsKey(
    const K& key
) const
{
    int index = hashFunction(key);

    const LinkedList<Entry<K,V>>& bucket =
        buckets.get(index);

    for(int i = 0; i < bucket.getSize(); i++)
    {
        if(bucket.get(i).key == key)
        {
            return true;
        }
    }

    return false;
}

template<typename K, typename V>
void HashMap<K,V>::remove(
    const K& key
)
{
    int index = hashFunction(key);

    LinkedList<Entry<K,V>>& bucket =
        buckets.get(index);

    for(int i = 0; i < bucket.getSize(); i++)
    {
        if(bucket.get(i).key == key)
        {
            bucket.removeAt(i);

            currentSize--;

            return;
        }
    }
}

template<typename K, typename V>
void HashMap<K,V>::clear()
{
    for(int i = 0; i < bucketCount; i++)
    {
        buckets.get(i).clear();
    }

    currentSize = 0;
}



#endif