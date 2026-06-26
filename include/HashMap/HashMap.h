#ifndef HASHMAP_H
#define HASHMAP_H

#include <cmath>
#include <string>
#include <stdexcept>

#include "../DynamicArray/DynamicArray.h"
#include "../LinkedList/LinkedList.h"

template <typename K, typename V>
class Entry
{
public:
    K key;
    V value;

    Entry()
    {
    }

    Entry(const K &newKey, const V &newValue)
    {
        key = newKey;
        value = newValue;
    }
};

template <typename K>
class DefaultHasher
{
public:
    int hash(const K &key, int bucketCount) const
    {
        const unsigned char *bytes = reinterpret_cast<const unsigned char *>(&key);

        unsigned long hash = 0;

        for (size_t i = 0; i < sizeof(K); i++)
        {
            hash = hash * 31 + bytes[i];
        }

        return hash % bucketCount;
    }
};

template <>
class DefaultHasher<int>
{
public:
    int hash(const int &key, int bucketCount) const
    {
        int value = key;

        if (value < 0)
        {
            value = -value;
        }

        return value % bucketCount;
    }
};

template <>
class DefaultHasher<char>
{
public:
    int hash(const char &key, int bucketCount) const
    {
        return static_cast<int>(key) % bucketCount;
    }
};

template <>
class DefaultHasher<bool>
{
public:
    int hash(const bool &key, int bucketCount) const
    {
        return (key ? 1 : 0) % bucketCount;
    }
};

template <>
class DefaultHasher<long>
{
public:
    int hash(const long &key, int bucketCount) const
    {
        long value = key;

        if (value < 0)
        {
            value = -value;
        }

        return value % bucketCount;
    }
};

template <>
class DefaultHasher<long long>
{
public:
    int hash(const long long &key, int bucketCount) const
    {
        long long value = key;

        if (value < 0)
        {
            value = -value;
        }

        return value % bucketCount;
    }
};

template <>
class DefaultHasher<float>
{
public:
    int hash(const float &key, int bucketCount) const
    {
        float value = key;

        if (value < 0)
        {
            value = -value;
        }

        int scaledValue =
            static_cast<int>(
                value * 1000);

        return scaledValue % bucketCount;
    }
};

template <>
class DefaultHasher<double>
{
public:
    int hash(const double &key, int bucketCount) const
    {
        double value = key;

        if (value < 0)
        {
            value = -value;
        }

        long long scaledValue =
            static_cast<long long>(
                value * 1000000);

        return scaledValue % bucketCount;
    }
};

template <>
class DefaultHasher<std::string>
{
public:
    int hash(
        const std::string &key,
        int bucketCount) const
    {
        unsigned long hash = 0;

        for (size_t i = 0; i < key.length(); i++)
        {
            hash = hash * 31 + key[i];
        }

        return hash % bucketCount;
    }
};

template <typename K, typename V>
class HashMap
{
private:
    DynamicArray<LinkedList<Entry<K, V>>> buckets;

    int currentSize;

    int bucketCount;

    DefaultHasher<K> hasher;

    int hashFunction(const K &key) const;

    void rehash();

public:
    HashMap();

    HashMap(const HashMap &other);

    HashMap &operator=(const HashMap &other);

    void put(const K &key, const V &value);

    bool get(const K &key, V &value) const;

    bool containsKey(const K &key) const;

    bool remove(const K &key);

    void clear();

    int size() const;

    bool isEmpty() const;

    double loadFactor() const;
};

#include "../../src/HashMap.cpp"

#endif