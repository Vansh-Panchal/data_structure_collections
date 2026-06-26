## Session 3

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
