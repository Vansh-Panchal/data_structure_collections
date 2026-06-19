# SuperCoders Collections Library
## Professional Design Proposal

---

# 1. Executive Summary

This document presents the design and implementation proposal for a custom C++ Collections Library developed without relying on STL container classes. The library provides three fundamental data structures: **DynamicArray**, **LinkedList**, and **HashMap**.

The objective is to demonstrate a strong understanding of dynamic memory management, templates, object-oriented programming, copy semantics, and algorithmic efficiency.

---

# 2. Project Objectives

- Implement DynamicArray, LinkedList, and HashMap from scratch.
- Apply templates to support generic data types.
- Implement deep copy semantics using the Rule of Three.
- Analyze performance using time complexity.
- Design reusable and maintainable data structure components.

---

# 3. System Architecture

## DynamicArray
Stores elements in contiguous memory and grows dynamically using a growth factor of **1.4x**.

## LinkedList
Stores elements as heap-allocated nodes connected through pointers, enabling efficient insertion and deletion.

## HashMap
Stores key-value pairs using hashing and separate chaining for collision resolution. Rehashing is performed when the load factor exceeds **0.75**.

---

# 4. Public APIs

## DynamicArray<T>

Functions:
- append
- insert
- remove
- get
- set
- clear
- getSize
- getCapacity

| Return Type | Method |
|------------|---------|
| — | DynamicArray() |
| — | DynamicArray(const DynamicArray& other) |
| DynamicArray& | operator=(const DynamicArray& other) |
| — | ~DynamicArray() |
| void | append(const T& value) |
| void | insert(int index, const T& value) |
| void | remove(int index) |
| T& | get(int index) |
| void | set(int index, const T& value) |
| int | getSize() const |
| int | getCapacity() const |
| bool | isEmpty() const |
| void | clear() |

---

## LinkedList<T>

Functions:
- pushFront
- pushBack
- insert
- removeAt
- contains
- get
- clear

| Return Type | Method |
|------------|---------|
| — | LinkedList() |
| — | LinkedList(const LinkedList& other) |
| LinkedList& | operator=(const LinkedList& other) |
| — | ~LinkedList() |
| void | pushFront(const T& value) |
| void | pushBack(const T& value) |
| void | insert(int index, const T& value) |
| bool | removeFront() |
| bool | removeBack() |
| void | removeAt(int index) |
| bool | contains(const T& value) const |
| T& | get(int index) |
| int | getSize() const |
| bool | isEmpty() const |
| void | clear() |

---

## HashMap<K,V>

Functions:
- put
- get
- remove
- containsKey
- loadFactor
- rehash
- clear

| Return Type | Method |
|------------|---------|
| — | HashMap() |
| — | HashMap(const HashMap& other) |
| HashMap& | operator=(const HashMap& other) |
| — | ~HashMap() |
| void | put(const K& key, const V& value) |
| bool | get(const K& key, V& value) const |
| bool | remove(const K& key) |
| bool | containsKey(const K& key) const |
| int | size() const |
| void | clear() |
| double | loadFactor() const |
| void | rehash() |

---

# 5. Design Decisions and Justification

### DynamicArray
Selected for **O(1)** random access and cache-friendly storage.

### LinkedList
Selected for efficient insertion and deletion without shifting elements.

### HashMap
Selected to provide average **O(1)** insertion, lookup, and deletion.

Separate chaining was chosen because it is simple, reliable, and easier to maintain than open addressing.

---

# 6. Memory Management Strategy

All structures manage dynamic memory explicitly.

Deep copy semantics are implemented through:
- Copy Constructor
- Assignment Operator
- Destructor

This prevents:
- Shared ownership issues
- Double deletion
- Dangling pointers
- Accidental modification of copied objects

---

# 7. Complexity Analysis

| Structure | Operation | Best | Average | Worst |
|-----------|-----------|------|---------|--------|
| DynamicArray | Access | O(1) | O(1) | O(1) |
| DynamicArray | Insert | O(1) | O(n) | O(n) |
| DynamicArray | Delete | O(1) | O(n) | O(n) |
| LinkedList | Insert | O(1) | O(1) | O(n) |
| LinkedList | Search | O(1) | O(n) | O(n) |
| HashMap | Insert | O(1) | O(1) | O(n) |
| HashMap | Search | O(1) | O(1) | O(n) |

---

# 8. Conclusion

The proposed Collections Library provides a reusable, type-safe, and efficient foundation for data management in C++.

The design emphasizes:
- Correctness
- Maintainability
- Memory Safety
- Algorithmic Efficiency

while demonstrating core software engineering and data structure principles.

---