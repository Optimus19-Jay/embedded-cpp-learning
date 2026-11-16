# Week 01 – C++ Fundamentals

## Overview

This week focuses on building a foundation in modern C++ through practical exercises related to embedded software development.

The goal is to understand fundamental C++ concepts and apply them to small firmware-oriented examples.

## Learning Objectives

By the end of this week, the objectives are to:

- Understand the basic structure of a C++ program.
- Work with variables, data types, and type safety.
- Understand `enum class` and scoped enumerations.
- Use structures to represent firmware and sensor data.
- Understand pointers, references, and `const` correctness.
- Perform safe pointer handling and null-pointer validation.
- Separate declarations and implementations using header and source files.
- Organize code into reusable modules.
- Build projects using CMake and Ninja.
- Write unit tests using GoogleTest.
- Use compiler warnings and sanitizers for validation.
- Work with C-style arrays and `std::array` for fixed-size data storage.
- Implement safe array indexing and fixed-size buffer operations.

## Lessons

| Lesson | Topic | Status |
|---|---|---|
| Day 01 | Firmware Configuration Management | Completed |
| Day 02 | Pointers, References and Pointer Safety | Completed |
| Day 03 | Arrays and Fixed-Size Sensor Buffers | Completed |
| Day 04 | To be defined | Not started |
| Day 05 | To be defined | Not started |

## Concepts Practised

### C++ Fundamentals

- Structures and member variables.
- Fixed-width integer types using `<cstdint>`.
- Scoped enumerations using `enum class`.
- Functions returning status values.
- References and `const` correctness.
- Pointers, addresses, and dereferencing.
- `nullptr` and null-pointer validation.
- Local constants using `constexpr`.
- C-style arrays and `std::array`.
- Fixed-size storage and compile-time capacity.
- Zero-based array indexing.
- Array size and bounds validation.
- Passing arrays and structures by reference and constant reference.
- Output reference parameters.
- Buffer capacity and boundary checks.

### Project Organization

- Header and source file separation.
- Shared headers under `common/include`.
- Static library creation.
- Executable linking.
- Lesson-level CMake configuration.
- Organizing independent lesson modules.

### Testing and Validation

- GoogleTest fixtures using `TEST_F`.
- GoogleTest test cases using `TEST`.
- Testing valid and invalid inputs.
- Boundary-value testing.
- Pointer safety testing.
- Running tests through CTest.
- Compiler warnings and sanitizer builds.
- Testing fixed-size sensor buffers.
- Testing buffer-full conditions.
- Testing valid, unpopulated, and out-of-capacity indexes.
- Verifying output parameters remain unchanged after failed operations.

## Development Environment

The development environment and tool versions are documented in the root README.

## Weekly Progress

| Area | Progress |
|---|---|
| Day 01 implementation | Completed |
| Day 01 unit tests | 9 passed |
| Day 02 implementation | Completed |
| Day 02 unit tests | 2 passed |
| Day 03 implementation | Completed |
| Day 03 unit tests | 7 passed |
| Normal build | Successful |
| Total registered tests | 18 passed |
| ASan and UBSan validation | Successful |

AddressSanitizer (ASan) and UndefinedBehaviorSanitizer (UBSan) validation was completed successfully for all 18 registered tests.

Progress is tracked through the individual lesson directories. Each lesson has its own README documenting its requirements, implementation, architecture, and test coverage.

## Next Steps

Continue with Day 04 after completing the Day 03 documentation review and Git workflow.