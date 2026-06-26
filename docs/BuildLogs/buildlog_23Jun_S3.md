
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
