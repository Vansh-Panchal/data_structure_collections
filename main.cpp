#include <iostream>
#include <string>

#include "include/DynamicArray/DynamicArray.h"
#include "include/LinkedList/LinkedList.h"
#include "include/HashMap/HashMap.h"

using namespace std;

int main()
{
    cout << "Data Structure Collections Test\n";

    // DynamicArray Test
    DynamicArray<int> arr;
    arr.append(10);
    arr.append(20);
    arr.append(30);

    cout << "\nDynamicArray:\n";
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr.get(i) << " ";
    }
    cout << endl;

    // LinkedList Test
    LinkedList<int> list;

    list.pushBack(100);
    list.pushBack(200);
    list.pushFront(50);

    cout << "\nLinkedList:\n";

    // HashMap Test
    HashMap<string, int> marks;

    marks.put("Math", 95);
    marks.put("Physics", 90);

    cout << "\nHashMap:\n";
    int value;

    if (marks.get("Math", value))
    {
        cout << "Math: " << value << endl;
    }
    else
    {
        cout << "Math not found" << endl;
    }

    if (marks.get("Physics", value))
    {
        cout << "Physics: " << value << endl;
    }
    else
    {
        cout << "Physics not found" << endl;
    }

    return 0;
}