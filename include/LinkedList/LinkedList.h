#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>

template<typename T>
class LinkedList
{
private:

    class Node
    {
    public:
        T data;
        Node* next;

        Node(const T& value){
            data = value;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int size;

public:

    LinkedList();
    LinkedList(const LinkedList& other);
    LinkedList& operator=(const LinkedList& other);
    ~LinkedList();

    void pushFront(const T& value);
    void pushBack(const T& value);
    void insert(int index, const T& value);

    void removeFront();
    void removeBack();
    void removeAt(int index);

    T& get(int index);
    const T& get(int index) const;

    bool contains(const T& value) const;

    int getSize() const;
    bool isEmpty() const;
    void clear();
};


#include "../../src/LinkedList.cpp"
#endif