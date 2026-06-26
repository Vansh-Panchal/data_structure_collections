#include "../include/HashMap/HashMap.h"

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
HashMap<K,V>::HashMap(
    const HashMap& other
)
{
    buckets = other.buckets;
    currentSize = other.currentSize;
    bucketCount = other.bucketCount;
}

template<typename K, typename V>
HashMap<K,V>& HashMap<K,V>::operator=(
    const HashMap& other
)
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
int HashMap<K,V>::hashFunction(const K& key) const
{
    return hasher.hash(key,bucketCount);
}

template<typename K, typename V>
void HashMap<K,V>::rehash()
{
    int oldBucketCount = bucketCount;

    DynamicArray<LinkedList<Entry<K,V>>> oldBuckets = buckets;

    bucketCount = static_cast<int>(std::ceil(bucketCount * 1.4));

    DynamicArray<LinkedList<Entry<K,V>>> newBuckets;

    for(int i = 0; i < bucketCount; i++)
    {
        newBuckets.append(LinkedList<Entry<K,V>>());
    }

    buckets = newBuckets;

    currentSize = 0;

    for(int i = 0; i < oldBucketCount; i++)
    {
        LinkedList<Entry<K,V>>& bucket = oldBuckets.get(i);

        for(int j = 0; j < bucket.getSize();j++)
        {
            Entry<K,V> entry = bucket.get(j);

            int index = hasher.hash(entry.key,bucketCount);

            buckets.get(index).pushBack(entry);

            currentSize++;
        }
    }
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
void HashMap<K,V>::put(
    const K& key,
    const V& value
)
{
    int index = hashFunction(key);

    LinkedList<Entry<K,V>>& bucket = buckets.get(index);

    for(int i = 0; i < bucket.getSize(); i++)
    {
        if(bucket.get(i).key == key)
        {
            bucket.get(i).value = value;

            return;
        }
    }

    bucket.pushBack(Entry<K,V>(key,value));

    currentSize++;

    if(loadFactor() >= 0.75)
    {
        rehash();
    }
}

template<typename K, typename V>
bool HashMap<K,V>::get(const K& key,V& value) const
{
    int index = hashFunction(key);

    const LinkedList<Entry<K,V>>& bucket = buckets.get(index);

    for(int i = 0; i < bucket.getSize(); i++)
    {
        if(bucket.get(i).key == key)
        {
            value = bucket.get(i).value;

            return true;
        }
    }

    return false;
}

template<typename K, typename V>
bool HashMap<K,V>::containsKey(const K& key) const
{
    int index = hashFunction(key);

    const LinkedList<Entry<K,V>>& bucket = buckets.get(index);

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
bool HashMap<K,V>::remove(const K& key)
{
    int index = hashFunction(key);

    LinkedList<Entry<K,V>>& bucket = buckets.get(index);

    for(int i = 0; i < bucket.getSize();i++)
    {
        if(bucket.get(i).key == key)
        {
            bucket.removeAt(i);

            currentSize--;

            return true;
        }
    }

    return false;
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

template<typename K, typename V>
double HashMap<K,V>::loadFactor() const
{
    return static_cast<double>(currentSize) / bucketCount;
}