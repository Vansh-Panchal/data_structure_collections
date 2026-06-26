
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
