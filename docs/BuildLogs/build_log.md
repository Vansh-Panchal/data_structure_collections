# Development Session Log

**Session:** 1  

**Date:** 23-06-2026

**Duration:** 60 min

## Work Completed

- Set up the project directory structure and organized source files.
- Analyzed the project specification and finalized the initial implementation approach.
- Decided to implement the DynamicArray as a generic template-based container.
- Evaluated low-level memory management techniques and chose to use `malloc`, `realloc`, and `free` instead of `new` and `delete`.
- Created the base `DynamicArray` class declaration with core member variables and function prototypes.

## Build Status

- Project structure prepared successfully.
- Compilation has not been executed at this stage.
- No executable generated yet.

## Challenges / Notes

- Investigated how template classes interact with C-style memory allocation.
- Need to ensure proper handling of non-primitive data types when using manual memory management.
- Further research required for object construction and destruction in templated containers.

## Planned Tasks

- Develop the default constructor.
- Implement the destructor and memory cleanup logic.
- Add dynamic resizing functionality.
- Begin implementation of element insertion operations.
- Prepare a basic test program to validate functionality.



**Session:** 2

**Date:** 24-06-2026

**Duration:** 60 min

## Work Completed

* Implemented the default constructor for the `DynamicArray` template class.
* Initialized the internal pointer (`data`) and tracking variables (`size` and `capacity`) with default values.
* Implemented the destructor to properly release allocated memory using `free()`.
* Developed the `resize()` method to dynamically adjust the array capacity when additional storage is required.
* Utilized `realloc()` within the resizing logic to preserve existing elements while expanding memory.
* Implemented the `append()` method to insert new elements at the end of the array.
* Added automatic capacity expansion in `append()` when the current storage becomes full.

## Build Status

* Constructor, destructor, resize, and append functionalities implemented successfully.
* Source code compiles without syntax errors.
* Basic dynamic memory management workflow established.

## Challenges / Notes

* Explored the behavior of `realloc()` and its ability to resize memory blocks while retaining existing data.
* Implemented checks to handle potential memory allocation failures during resizing.
* Noted that `malloc()`, `realloc()`, and `free()` do not automatically invoke constructors or destructors for complex object types.
* Additional work may be required to support non-primitive data types safely in a generic container implementation.

## Planned Tasks

* Implement element access functions (`get()`, `set()`, and `operator[]`).
* Add insertion functionality at specific indices.
* Implement element removal operations.
* Develop copy constructor and copy assignment operator.
* Create a test program to validate append, resize, and memory cleanup behavior.
* Begin testing with multiple data types to evaluate template compatibility.
