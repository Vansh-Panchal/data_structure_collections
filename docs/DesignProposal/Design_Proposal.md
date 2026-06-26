# SuperCoders Collections Library

## Professional Design Proposal

---

# 1. Executive Summary

This document presents the design and implementation proposal for a custom C++ Collections Library developed without relying on STL container classes. The library provides three fundamental data structures: **DynamicArray**, **LinkedList**, and **HashMap**. The objective is to demonstrate a strong understanding of dynamic memory management, templates, object-oriented programming, copy semantics, and algorithmic efficiency.

---

# 2. Project Objectives

* Implement DynamicArray, LinkedList, and HashMap from scratch.
* Apply templates to support generic data types.
* Implement deep copy semantics using the Rule of Three.
* Analyze performance using time complexity.
* Design reusable and maintainable data structure components.

---

# 3. System Architecture

* **DynamicArray** stores elements in contiguous memory and grows dynamically using a growth factor of **1.4×**.
* **LinkedList** stores elements as heap-allocated nodes connected through pointers, enabling efficient insertion and deletion.
* **HashMap** stores key-value pairs using hashing and separate chaining for collision resolution. Rehashing is performed when the load factor exceeds **0.75**.

---

# 4. Folder Structure

```text
data_structure_collections/
├── include/
│   ├── DynamicArray/
│   │   └── DynamicArray.h
│   ├── LinkedList/
│   │   └── LinkedList.h
│   └── HashMap/
│       └── HashMap.h
│
├── src/
│   ├── DynamicArray.cpp
│   ├── LinkedList.cpp
│   └── HashMap.cpp
│
├── docs/
│   └── Design_Proposal.md
│
├── main.cpp
├── README.md
└── .gitignore
```

---

# 5. Public APIs

## DynamicArray

**Operations:** append, insert, remove, get, set, clear, getSize, getCapacity, resize

| Return Type   | Method                                  |
| ------------- | --------------------------------------- |
| —             | DynamicArray()                          |
| —             | DynamicArray(const DynamicArray& other) |
| DynamicArray& | operator=(const DynamicArray& other)    |
| —             | ~DynamicArray()                         |
| void          | append(const T& value)                  |
| void          | insert(int index, const T& value)       |
| void          | remove(int index)                       |
| T&            | get(int index)                          |
| const T&      | get(int index) const                    |
| void          | set(int index, const T& value)          |
| int           | getSize() const                         |
| int           | getCapacity() const                     |
| bool          | isEmpty() const                         |
| void          | clear()                                 |
| void          | resize(int newCapacity)                 |

---

## LinkedList

**Operations:** pushFront, pushBack, insert, removeAt, contains, get, clear

| Return Type | Method                              |
| ----------- | ----------------------------------- |
| —           | LinkedList()                        |
| —           | LinkedList(const LinkedList& other) |
| LinkedList& | operator=(const LinkedList& other)  |
| —           | ~LinkedList()                       |
| void        | pushFront(const T& value)           |
| void        | pushBack(const T& value)            |
| void        | insert(int index, const T& value)   |
| void        | removeFront()                       |
| void        | removeBack()                        |
| void        | removeAt(int index)                 |
| bool        | contains(const T& value) const      |
| T&          | get(int index)                      |
| const T&    | get(int index) const                |
| int         | getSize() const                     |
| bool        | isEmpty() const                     |
| void        | clear()                             |

---

## HashMap

**Operations:** put, get, remove, containsKey, loadFactor, rehash

### Hash Function Strategy

| Key Type         | Hash Method                   |
| ---------------- | ----------------------------- |
| Integer          | `key % bucketCount`           |
| Character        | `ASCII value % bucketCount`   |
| String           | Polynomial Rolling Hash       |
| Boolean          | `(key ? 1 : 0) % bucketCount` |
| Float / Double   | Scaled Numeric Hashing        |
| Long / Long Long | `abs(key) % bucketCount`      |
| Custom Class     | User-defined Hash Function    |

| Return Type | Method                            |
| ----------- | --------------------------------- |
| —           | HashMap()                         |
| —           | HashMap(const HashMap& other)     |
| HashMap&    | operator=(const HashMap& other)   |
| —           | ~HashMap()                        |
| void        | put(const K& key, const V& value) |
| bool        | get(const K& key, V& value) const |
| bool        | remove(const K& key)              |
| bool        | containsKey(const K& key) const   |
| int         | size() const                      |
| bool        | isEmpty() const                   |
| void        | clear()                           |
| double      | loadFactor() const                |
| void        | rehash()                          |

---

# 6. Design Decisions and Justification

### DynamicArray

* Selected for **O(1)** random access.
* Initial capacity of **4** minimizes memory usage.
* Growth factor **1.4×** balances memory usage and resizing overhead.

### LinkedList

* Efficient insertion and deletion.
* Singly linked implementation reduces memory usage.
* Head and tail pointers support constant-time insertion at both ends.

### HashMap

* Provides average **O(1)** insertion, lookup, and deletion.
* Uses **Separate Chaining** for collision resolution.
* Initial bucket count of **4** minimizes memory usage.
* Growth factor **1.4×** balances rehash frequency.
* Load factor **0.75** maintains efficient hashing.

---

# 7. Memory Management Strategy

* Dynamic memory managed explicitly.
* Rule of Three implemented:

  * Copy Constructor
  * Assignment Operator
  * Destructor
* Prevents:

  * Memory leaks
  * Double deletion
  * Dangling pointers
  * Shared ownership problems

Templates are used throughout the library; integer examples are used only for memory illustrations.

DynamicArray Memory Layout

![DynamicArray Memory Layout](Images/DynamicArray_Memory.jpeg)

LinkedList Memory Layout

![LinkedList Memory Layout](Images/LinkedList_Memory.jpeg)

HashMap Memory Layout

![HashMap Memory Layout](Images/HashMap_Memory.jpeg)

---

# 8. Complexity Analysis

| Data Structure | Operation      | Best | Average        | Worst | Reason                  |
| -------------- | -------------- | ---- | -------------- | ----- | ----------------------- |
| DynamicArray   | Get            | O(1) | O(1)           | O(1)  | Direct indexing         |
| DynamicArray   | Append         | O(1) | O(1) amortized | O(n)  | Occasional array resize |
| DynamicArray   | Insert         | O(1) | O(n)           | O(n)  | Element shifting        |
| DynamicArray   | Remove         | O(1) | O(n)           | O(n)  | Element shifting        |
| DynamicArray   | Resize         | O(n) | O(n)           | O(n)  | Copy all elements       |
| LinkedList     | Push Front     | O(1) | O(1)           | O(1)  | Head node insertion     |
| LinkedList     | Push Back      | O(1) | O(1)           | O(1)  | Tail node insertion     |
| LinkedList     | Insert         | O(1) | O(n)           | O(n)  | Node traversal          |
| LinkedList     | Search         | O(1) | O(n)           | O(n)  | Sequential traversal    |
| LinkedList     | Remove         | O(1) | O(n)           | O(n)  | Locate target node      |
| HashMap        | Put            | O(1) | O(1)           | O(n)  | Hash collisions         |
| HashMap        | Get / Contains | O(1) | O(1)           | O(n)  | Bucket traversal        |
| HashMap        | Remove         | O(1) | O(1)           | O(n)  | Collision chain search  |
| HashMap        | Rehash         | O(n) | O(n)           | O(n)  | Reinsert all entries    |
