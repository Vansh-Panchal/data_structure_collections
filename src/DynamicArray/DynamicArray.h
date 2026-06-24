#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <cstdlib>
#include <cmath>
#include <stdexcept>
#include <new>

template <typename T>
class DynamicArray
{
private:
    T *data;
    int size;
    int capacity;

    void resize(int newCapacity);

public:
    DynamicArray();
    ~DynamicArray();

    DynamicArray(const DynamicArray &other);

    DynamicArray &operator=(const DynamicArray &other);

    void append(const T &value);
    void insert(int index, const T &value);
    void remove(int index);

    T &get(int index);
    void set(int index, const T &value);

    int getSize() const;
    int getCapacity() const;
    bool isEmpty() const;
    void clear();
};

template <typename T>
DynamicArray<T>::DynamicArray()
{
    size = 0;
    capacity = 4;

    data = static_cast<T*>(malloc(capacity * sizeof(T)));

    if (data == nullptr)
    {
        throw std::bad_alloc();
    }

    for (int i = 0; i < capacity; i++)
    {
        new (&data[i]) T();
    }
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
    for (int i = 0; i < capacity; i++)
    {
        data[i].~T();
    }

    free(data);
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray &other)
{
    size = other.size;
    capacity = other.capacity;

    data = static_cast<T*>(malloc(capacity * sizeof(T)));

    if (data == nullptr)
    {
        throw std::bad_alloc();
    }

    for (int i = 0; i < capacity; i++)
    {
        new (&data[i]) T();
    }

    for (int i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }
}

template <typename T>
DynamicArray<T> &DynamicArray<T>::operator=(const DynamicArray &other)
{
    if (this == &other)
    {
        return *this;
    }

    for (int i = 0; i < capacity; i++)
    {
        data[i].~T();
    }

    free(data);

    size = other.size;
    capacity = other.capacity;

    data = static_cast<T*>(malloc(capacity * sizeof(T)));

    if (data == nullptr)
    {
        throw std::bad_alloc();
    }

    for (int i = 0; i < capacity; i++)
    {
        new (&data[i]) T();
    }

    for (int i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }

    return *this;
}

template <typename T>
void DynamicArray<T>::resize(int newCapacity)
{
    T* newData =
        static_cast<T*>(malloc(newCapacity * sizeof(T)));

    if (newData == nullptr)
    {
        throw std::bad_alloc();
    }

    for (int i = 0; i < newCapacity; i++)
    {
        new (&newData[i]) T();
    }

    for (int i = 0; i < size; i++)
    {
        newData[i] = data[i];
    }

    for (int i = 0; i < capacity; i++)
    {
        data[i].~T();
    }

    free(data);

    data = newData;
    capacity = newCapacity;
}

template <typename T>
void DynamicArray<T>::append(const T &value)
{
    if (size == capacity)
    {
        int newCapacity = (int)std::ceil(capacity * 1.4);
        resize(newCapacity);
    }
    data[size++] = value;
}

template <typename T>
void DynamicArray<T>::insert(int index, const T &value)
{
    if (index < 0 || index > size)
        throw std::out_of_range("Index out of range");

    if (size == capacity)
    {
        int newCapacity = (int)std::ceil(capacity * 1.4);
        resize(newCapacity);
    }

    for (int i = size; i > index; i--)
    {
        data[i] = data[i - 1];
    }

    data[index] = value;
    size++;
}

template <typename T>
void DynamicArray<T>::remove(int index)
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");

    for (int i = index; i < size - 1; i++)
    {
        data[i] = data[i + 1];
    }
    size--;
}

template <typename T>
T &DynamicArray<T>::get(int index)
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");

    return data[index];
}

template <typename T>
void DynamicArray<T>::set(int index, const T &value)
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");

    data[index] = value;
}

template <typename T>
int DynamicArray<T>::getSize() const
{
    return size;
}

template <typename T>
int DynamicArray<T>::getCapacity() const
{
    return capacity;
}

template <typename T>
bool DynamicArray<T>::isEmpty() const
{
    return size == 0;
}

template <typename T>
void DynamicArray<T>::clear()
{
    for (int i = 0; i < capacity; i++)
    {
        data[i].~T();
    }

    size = 0;
}

#endif