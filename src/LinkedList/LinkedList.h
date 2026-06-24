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

template<typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList& other)
{
    head = nullptr;
    tail = nullptr;
    size = 0;

    Node* current = other.head;

    while(current != nullptr)
    {
        pushBack(current->data);
        current = current->next;
    }
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other)
{
    if(this == &other)
        return *this;

    clear();

    Node* current = other.head;

    while(current != nullptr)
    {
        pushBack(current->data);
        current = current->next;
    }

    return *this;
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
        tail = newNode;

    size++;
}

template<typename T>
void LinkedList<T>::pushBack(const T& value)
{
    Node* newNode = new Node(value);

    if(size == 0)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }

    size++;
}

template<typename T>
void LinkedList<T>::insert(int index, const T& value)
{
    if(index < 0 || index > size)
        throw std::out_of_range("Index out of range");

    if(index == 0)
    {
        pushFront(value);
        return;
    }

    if(index == size)
    {
        pushBack(value);
        return;
    }

    Node* prev = head;

    for(int i = 0; i < index - 1; i++)
    {
        prev = prev->next;
    }

    Node* newNode = new Node(value);

    newNode->next = prev->next;
    prev->next = newNode;

    size++;
}

template<typename T>
void LinkedList<T>::removeFront()
{
    if(isEmpty())
        return ;

    Node* temp = head;

    head = head->next;

    delete temp;

    size--;

    if(size == 0)
        tail = nullptr;

    return ;
}

template<typename T>
void LinkedList<T>::removeBack()
{
    if(isEmpty())
        return ;

    if(size == 1)
    {
        delete head;

        head = nullptr;
        tail = nullptr;
        size = 0;

        return ;
    }

    Node* current = head;

    while(current->next != tail)
    {
        current = current->next;
    }

    delete tail;

    tail = current;
    tail->next = nullptr;

    size--;
    
}

template<typename T>
void LinkedList<T>::removeAt(int index)
{
    if(index < 0 || index >= size)
        throw std::out_of_range("Index out of range");

    if(index == 0)
    {
        removeFront();
        return;
    }

    Node* prev = head;

    for(int i = 0; i < index - 1; i++)
    {
        prev = prev->next;
    }

    Node* target = prev->next;

    prev->next = target->next;

    if(target == tail)
        tail = prev;

    delete target;

    size--;
}

template<typename T>
T& LinkedList<T>::get(int index)
{
    if(index < 0 || index >= size)
        throw std::out_of_range("Index out of range");

    Node* current = head;

    for(int i = 0; i < index; i++)
    {
        current = current->next;
    }

    return current->data;
}

template<typename T>
const T& LinkedList<T>::get(int index) const
{
    if(index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of range");
    }

    Node* current = head;

    for(int i = 0; i < index; i++)
    {
        current = current->next;
    }

    return current->data;
}

template<typename T>
bool LinkedList<T>::contains(const T& value) const
{
    Node* current = head;

    while(current != nullptr)
    {
        if(current->data == value)
            return true;

        current = current->next;
    }

    return false;
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