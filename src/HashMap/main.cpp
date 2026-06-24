#include <iostream>
#include <string>
#include "HashMap.h"

using namespace std;

int main()
{
    // int
    HashMap<int,string> intMap;
    intMap.put(101,"Ali");
    cout << "int: " << intMap.get(101) << endl;

    // char
    HashMap<char,int> charMap;
    charMap.put('A',90);
    cout << "char: " << charMap.get('A') << endl;

    // bool
    HashMap<bool,string> boolMap;
    boolMap.put(true,"Passed");
    cout << "bool: " << boolMap.get(true) << endl;

    // long
    HashMap<long,string> longMap;
    longMap.put(100000L,"Long Value");
    cout << "long: " << longMap.get(100000L) << endl;

    // long long
    HashMap<long long,string> longLongMap;
    longLongMap.put(9999999999LL,"Long Long Value");
    cout << "long long: "
         << longLongMap.get(9999999999LL)
         << endl;

    // float
    HashMap<float,string> floatMap;
    floatMap.put(3.14f,"Pi");
    cout << "float: " << floatMap.get(3.14f) << endl;

    // double
    HashMap<double,string> doubleMap;
    doubleMap.put(2.71828,"Euler");
    cout << "double: "
         << doubleMap.get(2.71828)
         << endl;

    // unsigned int
    HashMap<unsigned int,string> uintMap;
    uintMap.put(50U,"Unsigned Int");
    cout << "unsigned int: "
         << uintMap.get(50U)
         << endl;

    // unsigned long
    HashMap<unsigned long,string> ulongMap;
    ulongMap.put(5000UL,"Unsigned Long");
    cout << "unsigned long: "
         << ulongMap.get(5000UL)
         << endl;

    // string
    HashMap<string,int> stringMap;
    stringMap.put("Ali",101);
    cout << "string: "
         << stringMap.get("Ali")
         << endl;

    return 0;
}