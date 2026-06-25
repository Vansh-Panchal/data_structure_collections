# Build Log

## Session 1

**Date:** 23-06-2026

**Duration:** 60 minutes

**Goal:**
Set up project structure and design DynamicArray.

**Problem Encountered:**
Unsure how templates would work with `malloc()` and `free()`.

**What I Tried:**

* Reviewed project requirements.
* Compared `malloc/free` with `new/delete`.
* Designed DynamicArray class structure.

**Outcome:**
Created project structure and finalized the DynamicArray design.

---

## Session 2

**Date:** 23-06-2026

**Duration:** 60 minutes

**Goal:**
Implement constructor, destructor, resize, and append operations.

**Problem Encountered:**
Needed to ensure data remained valid after resizing.

**What I Tried:**

* Implemented constructor and destructor.
* Added resize functionality using `realloc()`.
* Tested append operation.

**Outcome:**
Basic DynamicArray functionality completed and working correctly.

---

## Session 3

**Date:** 23-06-2026

**Duration:** 90 minutes

**Goal:**
Complete DynamicArray implementation and test with different data types.

**Problem Encountered:**
`std::string` values were not stored correctly.

**What I Tried:**

* Tested all methods with primitive types and strings.
* Debugged resize and insertion operations.
* Researched behavior of `malloc()` and `realloc()`.

**Outcome:**
Found that C-style memory allocation does not properly support objects like `std::string`.

---

## Session 4

**Date:** 23-06-2026

**Duration:** 120 minutes

**Goal:**
Fix DynamicArray support for complex data types.

**Problem Encountered:**
The program compiled successfully but produced no output when testing with `DynamicArray<std::string>`.

Terminal output:

```text
PS D:\CQ_STL\data_structure_collections> cd "d:\CQ_STL\data_structure_collections\src\DynamicArray\" ; if ($?) { g++ main.cpp -o main } ; if ($?) { .\main }

PS D:\CQ_STL\data_structure_collections\src\DynamicArray>
```

**What I Tried:**

* Investigated how `malloc()`, `realloc()`, and `free()` interact with C++ objects.
* Removed `realloc()` from the resize implementation.
* Used placement new and explicit destructor calls.
* Retested with strings and primitive data types.

**Outcome:**
Resolved the issue and verified that DynamicArray now works correctly with `std::string` and other complex data types.

---

## Session 5

**Date:** 23-06-2026

**Duration:** 60 minutes

**Goal:**
Start LinkedList implementation.

**Problem Encountered:**
Needed proper memory management for generic node storage.

**What I Tried:**

* Created Node structure.
* Implemented constructor and destructor.
* Added `pushFront()` and `pushBack()`.

**Outcome:**
Basic LinkedList structure completed and tested.

---

## Session 6

**Date:** 23-06-2026

**Duration:** 90 minutes

**Goal:**
Complete LinkedList implementation.

**Problem Encountered:**
Needed to handle copying and edge cases correctly.

**What I Tried:**

* Implemented insert and remove operations.
* Added copy constructor and assignment operator.
* Tested with integers and strings.

**Outcome:**
LinkedList completed successfully and all major operations are working correctly.


## Session 1

**Date:** 24-06-2026

**Duration:** 120 minutes

**Goal:**
Establish the foundation of the HashMap data structure using templates and separate chaining.

**Problem Encountered:**

* Needed a generic hashing mechanism without using `std::hash`.
* Required support for multiple key types while keeping the HashMap implementation generic.
* Faced a compilation error while integrating HashMap with DynamicArray:

```text
../DynamicArray/DynamicArray.h:136:21: error:
expected primary-expression before '>' token

T *newData = <T*>(malloc(newCapacity * sizeof(T)));
```

* The issue occurred because `<T*>` is not valid C++ casting syntax.

**What I Tried:**

* Created the `Entry<K,V>` structure to store key-value pairs.
* Designed a `DefaultHasher` template class to separate hashing logic from the HashMap implementation.
* Implemented specialized hash functions for:

  * `int`
  * `char`
  * `std::string`
* Implemented the HashMap constructor.
* Added copy constructor, assignment operator, and destructor following the Rule of Three.
* Initialized buckets using `DynamicArray<LinkedList<Entry<K,V>>>`.
* Implemented `hashFunction()`, `size()`, and `isEmpty()` methods.
* Investigated the DynamicArray compilation issue and identified that the cast syntax was incorrect.
* Replaced:

```cpp
<T*>(malloc(...))
```

with:

```cpp
static_cast<T*>(malloc(...))
```

throughout the DynamicArray implementation.

**Outcome:**

* HashMap architecture completed successfully.
* Separate chaining bucket structure established using DynamicArray and LinkedList.
* Custom hashing framework implemented without relying on STL hashing utilities.
* Integer, character, and string keys are supported through specialized hashers.
* Rule of Three functionality completed.
* DynamicArray compilation issue resolved by using `static_cast<T*>`.
* HashMap foundation is complete and ready for insertion, retrieval, and search operations in Session 2.


## Session 2

**Date:** 24-06-2026

**Duration:** 90 minutes

**Goal:**  
Implement core HashMap operations using separate chaining and add support for additional primitive data types.

**Problem Encountered:**  

While implementing `get()` and `containsKey()`, compilation errors occurred because const HashMap methods were attempting to call non-const `get()` functions from `DynamicArray` and `LinkedList`.

Important error messages:

```text
passing 'const DynamicArray<...>' as 'this' argument discards qualifiers
```

```text
passing 'const LinkedList<...>' as 'this' argument discards qualifiers
```

A previously encountered DynamicArray issue was also reviewed:

```text
expected primary-expression before '>' token
```

**What I Tried:**

* Implemented `put()` for inserting and updating key-value pairs.
* Implemented `get()` for retrieving values using keys.
* Implemented `containsKey()` for searching keys.
* Implemented `remove()` for deleting entries.
* Implemented `clear()` for removing all stored data.
* Added support for additional primitive key types:
  * `bool`
  * `long`
  * `long long`
  * `float`
  * `double`
  * `unsigned int`
  * `unsigned long`
* Resolved const-correctness issues by updating both **DynamicArray** and **LinkedList** and adding const versions of the `get()` function.
* Verified functionality through testing with multiple primitive data types.

**Outcome:**  

Core HashMap functionality was completed successfully. All major operations (`put`, `get`, `containsKey`, `remove`, and `clear`) are working correctly using separate chaining. The const-related compilation errors were resolved by modifying the DynamicArray and LinkedList implementations, and the HashMap now supports a wider range of primitive key types.


## Session 1

**Date:** 25-06-2026

**Duration:** 120 minutes

**Goal:**
Implement the core HashMap operations and add support for dynamic resizing through rehashing.

**Problems Encountered:**

* Needed a better way to indicate success/failure in `get()` and `remove()`.
* Had to ensure rehashing correctly redistributes existing entries.
* Needed support for both primitive and user-defined data types.

**What I Tried:**

* Implemented:

  * `put()`
  * `get()`
  * `containsKey()`
  * `remove()`
  * `clear()`
  * `loadFactor()`
  * `rehash()`

* Added automatic rehashing when load factor reaches `0.75`.

* Increased bucket count using:

  ```cpp
  ceil(bucketCount * 1.4)
  ```

* Added custom hashers for:

  * int
  * char
  * bool
  * long
  * long long
  * float
  * std::string

* Tested HashMap with primitive and user-defined data types.

**Design Updates:**

* Changed:

  ```cpp
  V get(const K& key) const;
  ```

  to:

  ```cpp
  bool get(const K& key,V& value) const;
  ```

* Changed:

  ```cpp
  void remove(const K& key);
  ```

  to:

  ```cpp
  bool remove(const K& key);
  ```

This allows methods to return success/failure without using exceptions.

**Outcome:**

* Collision handling using separate chaining is working.
* Load factor calculation and automatic rehashing are implemented.
* Primitive data types are distributed across buckets using specialized hashers.
* User-defined types are supported through the default hasher.
* Core HashMap functionality is now completed and ready for further improvements.
