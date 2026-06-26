# Session 1

**Date:** 26-06-2026

**Duration:** 120 minutes

---

## Goal

The primary objective of this session was to implement the **HashMap** data structure using the custom **DynamicArray** and **LinkedList** implementations. Additional goals included implementing generic and specialized hash functions, collision handling, automatic rehashing, and comprehensive testing.

---

## Tasks Completed

### HashMap Implementation

Implemented the complete functionality of the HashMap using **Separate Chaining**.

Implemented the following methods:

* `put()`
* `get()`
* `containsKey()`
* `remove()`
* `clear()`
* `size()`
* `isEmpty()`
* `loadFactor()`
* `rehash()`

Implemented automatic bucket resizing whenever the load factor exceeded **0.75** to maintain efficient average-case performance.

---

### Hash Function Implementation

Implemented specialized hashers for common primitive data types:

* `int`
* `char`
* `bool`
* `long`
* `long long`
* `float`
* `double`
* `std::string`

Implemented a generic template-based fallback hasher for user-defined types by hashing the raw byte representation of trivially copyable objects. This provides default hashing support for custom data types that do not define their own specialized hash function.

---

## Problems Encountered

* Designing a generic hashing mechanism capable of supporting both primitive and user-defined data types.
* Understanding the limitations of generic hashing for complex user-defined types containing dynamic memory (such as `std::string`, pointers, or containers).
* Implementing automatic rehashing while ensuring all existing entries were reinserted correctly without data loss.
* Integrating collision handling efficiently with the custom LinkedList implementation.

---

## Errors Encountered & Solutions

### 1. Private Member Access Error

**Error:**
While implementing `HashMap`, compilation failed because `HashMap` attempted to access the private members (`key`, `value`) and constructor of the `Entry` class.

**Solution:**
Modified the access control by exposing the required members (or making them accessible), allowing `HashMap` to read, update, and construct `Entry` objects correctly.

---

### 2. Generic Hashing for User-Defined Types

**Issue:**
Initially, it was unclear how to generate hash values for arbitrary user-defined data types without knowing their members.

**Solution:**
Implemented a generic template-based fallback hasher that processes the raw byte representation of trivially copyable user-defined objects using `reinterpret_cast<const unsigned char*>`. Specialized hashers were retained for primitive data types and `std::string`.

---

### 3. Rehashing Existing Elements

**Issue:**
During bucket resizing, existing entries needed to be redistributed into the new bucket array without losing data.

**Solution:**
Implemented a dedicated `rehash()` routine that allocates a larger bucket array and reinserts every existing key-value pair using the updated bucket count.

---

### 4. Collision Handling

**Issue:**
Multiple keys could map to the same bucket, requiring an efficient collision resolution strategy.

**Solution:**
Implemented **Separate Chaining** using the custom `LinkedList`, allowing multiple entries to be stored safely within a single bucket while maintaining efficient insertion, lookup, and deletion.

---

## What I Tried

* Implemented all core HashMap operations.
* Added template specializations for primitive hash functions.
* Implemented a generic fallback hasher for user-defined types.
* Verified hashing support for both primitive and simple user-defined data types.
* Implemented collision handling using Separate Chaining.
* Added automatic bucket resizing based on the load factor threshold.
* Tested insertion, retrieval, deletion, updating existing keys, collision handling, automatic rehashing, and hashing for custom user-defined structures.
* Verified successful compilation after every major implementation milestone.

---

## Design Updates

### Hash Function Design

* Implemented specialized hashing strategies for primitive data types.
* Added a generic template-based fallback hasher for user-defined types using their raw memory representation.
* Designed the hashing framework so specialized hashers are preferred for built-in types while the generic implementation provides default support for custom types.

### HashMap Design

* Collision resolution uses **Separate Chaining**.
* Bucket storage uses the custom **DynamicArray**.
* Individual buckets are implemented using the custom **LinkedList**.
* Automatic rehashing occurs when the load factor exceeds **0.75**.
* Bucket count increases dynamically using:

```cpp
ceil(bucketCount * 1.4)
```

to balance memory usage and performance.

---

## Testing Performed

The following functionality was verified:

* Successful insertion of key-value pairs.
* Retrieval of existing keys.
* Updating values for duplicate keys.
* Handling of missing keys.
* Removal of existing entries.
* Collision handling using linked lists.
* Automatic bucket expansion after exceeding the load factor threshold.
* Hashing support for primitive data types.
* Hashing support for simple user-defined data types using the generic hasher.
* Successful compilation and execution using CMake.

---

## Outcome

The objectives for **Session 1** were successfully completed.

Achievements include:

* Successfully implemented the custom HashMap.
* Added specialized hashers for primitive data types.
* Implemented a generic template-based hasher for user-defined data types.
* Implemented automatic rehashing based on the load factor.
* Verified collision handling using Separate Chaining.
* Successfully tested all core HashMap operations.
* Established a solid foundation for integrating additional data structures and future testing sessions.
