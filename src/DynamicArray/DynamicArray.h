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


template<typename T>
DynamicArray<T>::DynamicArray() {
    size = 0;
    capacity = 4;

    data = (T*)malloc(capacity * sizeof(T));

    if(data == nullptr)
        throw std::bad_alloc();
}

template<typename T>
DynamicArray<T>::~DynamicArray(){
    free(data);
}

template<typename T>
void DynamicArray<T>::resize(int newCapacity){

    T* temp = (T*)realloc(data, newCapacity * sizeof(T));
    if(temp == nullptr)
        throw std::bad_alloc();
    
    data = temp;
    capacity = newCapacity;
}

template<typename T>
void DynamicArray<T>::append(const T& value){
    if(size == capacity)
    {
        int newCapacity = (int) (capacity * 1.4);
        resize(newCapacity);
    }
    data[size++] = value;
}


#endif