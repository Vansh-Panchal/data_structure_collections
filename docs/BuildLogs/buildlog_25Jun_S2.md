# Session 2

**Date:** 25-06-2026

**Duration:** 120 minutes

---

## Goal

The primary objective of this session was to reorganize the project into a modular structure to improve readability, maintainability, and scalability for future development.

---

## Tasks Completed

### Project Structure Update

Reorganized the project into a modular folder structure for improved readability and maintainability.

Updated project layout:


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
│
├── main.cpp
├── CMakeLists.txt
├── README.md
└── .gitignore
```

This organization separates interface files, implementation files, documentation, and build configuration into dedicated directories.

---

## Problems Encountered

* The existing folder organization became difficult to maintain as additional modules were added.

---

## What I Tried

* Refactored the project into separate include, source, and documentation directories.
* Verified successful project compilation after restructuring.

---

## Design Updates

### Project Structure

Introduced a modular directory organization:

```text
include/
src/
docs/
```

to improve code maintainability and scalability.

---

## Testing Performed

The following functionality was verified:

* Successful project compilation after restructuring.
* Correct project organization with separated header and source files.

---

## Outcome

The objectives for Session 2 were successfully completed.

Achievements include:

* Successfully reorganized the project into a modular directory structure.
* Improved project readability and maintainability.
* Verified successful compilation after restructuring.
* Established a scalable foundation for implementing additional data structures.
