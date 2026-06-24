#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;
int main()
{
    LinkedList<int> list;

    cout << "Is Empty: " << list.isEmpty() << endl;

    list.pushBack(10);
    list.pushBack(20);
    list.pushBack(30);

    list.pushFront(5);

    list.insert(2, 15);

    cout << "\nList Elements:" << endl;

    for (int i = 0; i < list.getSize(); i++)
    {
        cout << list.get(i) << " ";
    }

    cout << endl;

    cout << "\nContains 20: " << list.contains(20) << endl;

    cout << "Contains 100: " << list.contains(100) << endl;

    list.removeFront();
    list.removeBack();
    list.removeAt(1);

    cout << "\nAfter Removals:" << endl;

    for (int i = 0; i < list.getSize(); i++)
    {
        cout << list.get(i) << " ";
    }

    cout << endl;

    cout << "\nSize: " << list.getSize() << endl;

    
    LinkedList<int> copyList(list);

    cout << "\nCopied List:" << endl;

    for (int i = 0; i < copyList.getSize(); i++)
    {
        cout << copyList.get(i) << " ";
    }

    cout << endl;

    
    LinkedList<int> assignedList;
    assignedList = list;

    cout << "\nAssigned List:" << endl;

    for (int i = 0; i < assignedList.getSize(); i++)
    {
        cout << assignedList.get(i) << " ";
    }

    cout << endl;

    
    LinkedList<std::string> names;

    names.pushBack("Ali");
    names.pushBack("Ahmed");
    names.pushFront("John");

    cout << "\nString List:" << endl;

    for (int i = 0; i < names.getSize(); i++)
    {
        cout << names.get(i) << " ";
    }

    cout << endl;

    return 0;
}