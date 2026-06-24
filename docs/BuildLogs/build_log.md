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
