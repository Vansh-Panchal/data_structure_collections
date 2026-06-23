#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main()
{
    DynamicArray<string> arr;

    arr.append("10");
    arr.append("20");
    arr.append("30");
    arr.append("40");

    cout <<"Elements are :"<<endl;
    for(int i=0; i<arr.getSize(); i++)
    {
        cout << arr.get(i) <<" " << endl;
    }

    cout << "Size is : " <<arr.getSize() <<endl;
    cout<< "capacity is :" <<arr.getCapacity() <<endl;

    cout<<"After inserting element 35"<<endl;
    arr.insert(3,"35");

    cout <<"Elements are :"<<endl;
    for(int i=0; i<arr.getSize(); i++)
    {
        cout << arr.get(i) <<" " << endl;
    }

    cout << "Size is : " <<arr.getSize() <<endl;
    cout<< "capacity is :" <<arr.getCapacity() <<endl;

    cout<<"After removin element at index 2"<<endl;

    arr.remove(2);
    arr.append("hello");

    cout <<"Elements are :"<<endl;
    for(int i=0; i<arr.getSize(); i++)
    {
        cout << arr.get(i) <<" " << endl;
    }

    cout << "Size is : " <<arr.getSize() <<endl;
    cout<< "capacity is :" <<arr.getCapacity() <<endl;




    



    return 0;
}