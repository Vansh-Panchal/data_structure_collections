#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList<int> list;

    list.pushBack(10);
    list.pushBack(20);
    list.pushFront(5);

    std::cout << "Size: " << list.getSize() << std::endl;

    list.clear();

    std::cout << "Size after clear: "
              << list.getSize()
              << std::endl;

    return 0;
}