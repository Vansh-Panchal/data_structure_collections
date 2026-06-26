
## Session 2

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
