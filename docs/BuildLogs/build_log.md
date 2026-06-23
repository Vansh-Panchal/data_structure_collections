# Build Log

## Session 1

Date: 23-06-2026

Duration: 60 minutes

Goal:

Set up the project structure and plan the implementation of a template-based DynamicArray using C-style memory management.

Problem Encountered:

Uncertainty about how template classes interact with low-level memory allocation functions such as `malloc()`, `realloc()`, and `free()`.

What I Tried:

* Reviewed project requirements and specifications.
* Explored different memory management approaches.
* Compared the use of `malloc/free` with `new/delete`.
* Designed the initial DynamicArray class structure and member variables.
* Researched template compatibility with manual memory management.

Outcome:

Successfully created the project structure and base DynamicArray class declaration. Chose to use `malloc()`, `realloc()`, and `free()` for memory management and identified the need for further research regarding object construction and destruction for non-primitive data types.

---

## Session 2

Date: 23-06-2026

Duration: 60 minutes

Goal:

Implement the constructor, destructor, dynamic resizing functionality, and append operation for the DynamicArray.

Problem Encountered:

Needed to ensure that memory resizing preserved existing elements and handled allocation failures safely.

What I Tried:

* Implemented the default constructor and initialized internal member variables.
* Implemented the destructor using `free()`.
* Developed the `resize()` method using `realloc()`.
* Added automatic capacity expansion logic.
* Implemented the `append()` method.
* Tested memory allocation and resizing behavior.

Outcome:

Successfully implemented constructor, destructor, resize, and append operations. The DynamicArray correctly expands when capacity is reached and compiles without errors. Also learned that C-style memory allocation does not automatically call constructors or destructors for complex object types.

---

## Session 3

Date: 23-06-2026

Duration: 90 minutes

Goal:

Complete the implementation of all remaining DynamicArray methods and test the container with different data types.

Problem Encountered:

The DynamicArray worked correctly with primitive data types such as `int`, `float`, and `char`, but failed when tested with `std::string`. String values were not stored or displayed correctly after insertion and resizing.

What I Tried:

* Implemented the remaining DynamicArray methods.
* Tested element access, insertion, removal, and copy operations.
* Added debugging statements to track stored values.
* Compared behavior between primitive types and `std::string`.
* Reviewed append(), insert(), remove(), and resize() implementations.
* Researched how `malloc()`, `realloc()`, and `free()` interact with C++ objects and templates.

Outcome:

Successfully completed the DynamicArray implementation and verified that it works correctly for primitive data types. Discovered that `malloc()`, `realloc()`, and `free()` only manage raw memory and do not invoke constructors or destructors. As a result, `std::string` and other non-trivial user-defined types are not properly initialized. Future improvements will require placement new, explicit destructor calls, or switching to `new` and `delete` to support complex object types correctly.


# Session 4

**Date:** 24-06-2026

**Duration:** 120 min

## Goal

Fix the issue where DynamicArray was not working with `std::string` and make it support both primitive and complex data types.

## Work Done

* Tested DynamicArray with `std::string`.
* Found that string values were not being stored correctly.
* Read about how `malloc()`, `realloc()`, and `free()` work in C++.
* Learned about placement new and destructor calls.
* Updated the resize function.
* Removed the use of `realloc()`.
* Tested the DynamicArray again with different data types.
* Implemented copy constructor to create deep copies of DynamicArray objects.
* Implemented copy assignment operator to safely copy data between existing DynamicArray objects.

## Problem Faced

The DynamicArray was working correctly with:

* `int`
* `float`
* `char`

However, when I changed the implementation to:

```cpp
DynamicArray<string> arr;
```

the program compiled successfully but did not produce any output.

Terminal output:

```text
PS D:\CQ_STL\data_structure_collections> cd "d:\CQ_STL\data_structure_collections\src\DynamicArray\" ; if ($?) { g++ main.cpp -o main } ; if ($?) { .\main }

PS D:\CQ_STL\data_structure_collections\src\DynamicArray>
```

The program ended immediately without displaying any values. This made debugging difficult because there were no compilation errors or runtime error messages.

## Analysis

After debugging and researching, I found that:

* `malloc()` only allocates raw memory.
* `free()` only releases memory.
* `realloc()` only moves raw bytes from one memory location to another.
* Constructors and destructors are not called automatically.

Since `std::string` requires proper construction and destruction, storing string objects inside memory allocated only with `malloc()` caused undefined behavior.

## Solution

To solve this issue:

* Used placement new to construct objects inside allocated memory.
* Added explicit destructor calls before freeing memory.
* Removed the use of `realloc()` from the resize function.
* Implemented manual resizing by:

  * Allocating a new memory block.
  * Constructing objects in the new block.
  * Copying existing elements.
  * Destroying old objects.
  * Freeing old memory.

## Result

The DynamicArray now works correctly with:

* `int`
* `float`
* `char`
* User-defined structures
* `std::string`

All major functions were tested successfully:

* append()
* insert()
* remove()
* get()
* set()
* clear()

## Build Status

* Compilation Successful
* String-related issue resolved
* DynamicArray working correctly with primitive and object types


