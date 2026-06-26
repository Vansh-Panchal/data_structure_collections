# Build Log

## Session 1

**Date:** 26-06-2026

**Duration:** 120 minutes

---

## Goal

The primary objective of this session was to prepare the development environment for the project and begin the implementation of the **HashMap** data structure. This included installing and configuring CMake, reorganizing the project directory into a cleaner structure, implementing the complete HashMap class, and adding support for generic and user-defined hash functions.

---

## Tasks Completed

### Development Environment

* Installed the latest version of **CMake**.
* Configured the CMake executable in the system environment variables.
* Verified the installation using:

```bash
cmake --version
```

* Created a `CMakeLists.txt` file to automate project compilation.
* Successfully generated build files and verified project compilation.

---

### Project Structure Update

Reorganized the project into a modular folder structure for improved readability and maintainability.

Updated project layout:

```text
data_structure_collections/
├── include/
│   ├── DynamicArray/DynamicArray.h
│   ├── LinkedList/LinkedList.h
│   └── HashMap/HahsMap.h
│
├── src/
│   ├── DynamicArray.cpp
│   ├── LinkedList.cpp
│   └── HashMap.cpp
│
├── docs/
│
├── main.cpp
├── CMakeLists.txt
├── README.md
└── .gitignore
```

This organization separates interface files, implementation files, documentation, and build configuration into dedicated directories.

---

### HashMap Implementation

Implemented the complete functionality of the HashMap using **Separate Chaining** with the custom **DynamicArray** and **LinkedList** data structures.

Implemented methods:

* `put()`
* `get()`
* `containsKey()`
* `remove()`
* `clear()`
* `size()`
* `isEmpty()`
* `loadFactor()`
* `rehash()`

Implemented automatic bucket resizing whenever the load factor exceeds **0.75**, ensuring efficient average-case performance.

---

### User-Defined Hash Functions

Implemented specialized hashers for primitive data types:

* `int`
* `char`
* `bool`
* `long`
* `long long`
* `float`
* `double`
* `std::string`

Also implemented a **generic template-based default hasher** capable of hashing user-defined classes by processing their raw byte representation.

---

## Problems Encountered

* CMake was not initially configured in the system PATH.
* Existing folder organization became difficult to maintain as additional modules were added.
* Generic hashing needed to support both built-in and user-defined data types.
* Automatic rehashing required careful reinsertion of existing entries without data loss.
* Collision handling had to integrate correctly with the custom LinkedList implementation.

---

## What I Tried

* Installed and configured the CMake build system.
* Verified compiler detection and build configuration.
* Refactored the project into separate include, source, and documentation directories.
* Implemented all core HashMap operations.
* Added template specialization for primitive hash functions.
* Implemented a generic fallback hasher for custom classes.
* Tested insertion, searching, deletion, collision handling, and automatic rehashing.
* Verified successful compilation after every major implementation milestone.

---

## Design Updates

### Project Structure

Introduced a modular directory organization:

```text
include/
src/
docs/
```

to improve code maintainability.

---

### Build System

Added

```text
CMakeLists.txt
```

to support platform-independent project compilation.

---

### Hash Function Design

Implemented specialized hashing strategies for commonly used primitive data types while preserving a generic template implementation for custom classes.

---

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
* Handling of missing keys.
* Updating values for duplicate keys.
* Removal of existing entries.
* Collision handling through linked lists.
* Automatic bucket expansion after exceeding the load factor threshold.
* Generic support for primitive and user-defined key types.
* Successful compilation using CMake.

---

## Outcome

The objectives for Session 1 were successfully completed.

Achievements include:

* Successfully installed and configured CMake.
* Updated the project folder structure into a modular layout.
* Completed the implementation of the custom HashMap.
* Added support for primitive and user-defined hash functions.
* Implemented automatic rehashing based on the load factor.
* Successfully compiled and tested the project using the CMake build system.
* Established a solid foundation for integrating the remaining data structures and future testing sessions.
