cmake_minimum_required(VERSION 4.4)

project(DataStructureCollections)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    include
    include/DynamicArray
    include/LinkedList
    include/HashMap
)

add_executable(
    DynamicArrayTest
    test/DynamicArray.cpp
)

add_executable(
    LinkedListTest
    test/LinkedList.cpp
)

add_executable(
    HashMapTest
    test/HashMap.cpp
)

add_executable(
    MainTest
    main.cpp
)