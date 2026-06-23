#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>

template<typename T>
class LinkedList
{
private:

    struct Node
    {
        T data;
        Node* next;

        Node(const T& value)
        {
            data = value;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int size;

public:

    LinkedList();
    ~LinkedList();

    void pushFront(const T& value);
    void pushBack(const T& value);

    int getSize() const;
    bool isEmpty() const;

    void clear();
};


template<typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template<typename T>
void LinkedList<T>::pushFront(const T& value)
{
    Node* newNode = new Node(value);

    newNode->next = head;
    head = newNode;

    if(size == 0)
    {
        tail = newNode;
    }

    size++;
}

template<typename T>
void LinkedList<T>::pushBack(const T& value)
{
    Node* newNode = new Node(value);

    if(size == 0)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }

    size++;
}

template<typename T>
int LinkedList<T>::getSize() const
{
    return size;
}

template<typename T>
bool LinkedList<T>::isEmpty() const
{
    return size == 0;
}

template<typename T>
void LinkedList<T>::clear()
{
    Node* current = head;

    while(current != nullptr)
    {
        Node* temp = current;
        current = current->next;

        delete temp;
    }

    head = nullptr;
    tail = nullptr;
    size = 0;
}

#endif