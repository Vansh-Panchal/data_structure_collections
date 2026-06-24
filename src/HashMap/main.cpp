#include <iostream>
#include "HashMap.h"

using namespace std;

int main()
{
    cout << "Constructor Test" << endl;

    HashMap<int,string> map1;

    cout << "Size: " << map1.size() << endl;
    cout << "Is Empty: "
         << (map1.isEmpty() ? "Yes" : "No")
         << endl;

    cout << "\n Copy Constructor Test " << endl;

    HashMap<int,string> map2(map1);

    cout << "Size: " << map2.size() << endl;
    cout << "Is Empty: "
         << (map2.isEmpty() ? "Yes" : "No")
         << endl;

    cout << "\n Assignment Operator Test " << endl;

    HashMap<int,string> map3;

    map3 = map1;

    cout << "Size: " << map3.size() << endl;
    cout << "Is Empty: "
         << (map3.isEmpty() ? "Yes" : "No")
         << endl;

    cout << "\n Different Template Types " << endl;

    HashMap<char,double> charMap;
    HashMap<string,int> stringMap;

    cout << "charMap Empty: "
         << (charMap.isEmpty() ? "Yes" : "No")
         << endl;

    cout << "stringMap Empty: "
         << (stringMap.isEmpty() ? "Yes" : "No")
         << endl;

    cout << "\nAll Session 1 tests passed." << endl;

    return 0;
}