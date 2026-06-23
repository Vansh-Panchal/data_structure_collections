#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <cstdlib>
#include <stdexcept>

template<typename T>
class DynamicArray
{
private:
    T* data;
    int size;
    int capacity;

    void resize(int newCapacity);

public:
    DynamicArray();
    ~DynamicArray();

    void append(const T& value);
    void insert(int index, const T& value);
    void remove(int index);

    T& get(int index);
    void set(int index, const T& value);

    int getSize() const;
    int getCapacity() const;
    bool isEmpty() const;
    void clear();
};

#endif