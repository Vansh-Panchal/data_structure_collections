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
