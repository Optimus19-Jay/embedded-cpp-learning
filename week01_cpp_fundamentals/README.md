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

## Lessons

| Lesson | Topic | Status |
|---|---|---|
| Day 01 | Firmware Configuration Management | Completed |
| Day 02 | Pointers, References and Pointer Safety | Completed |
| Day 03 | To be defined | Not started |
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

## Development Environment

The development environment and tool versions are documented in the root README.

## Weekly Progress

| Area | Progress |
|---|---|
| Day 01 implementation | Completed |
| Day 01 unit tests | 9 passed |
| Day 02 implementation | Completed |
| Day 02 unit tests | 2 passed |
| Normal build | Successful |
| Total registered tests | 11 passed |

Sanitizer validation is part of the ongoing development workflow.

Progress is tracked through the individual lesson directories. Each lesson has its own README documenting its requirements, implementation, architecture, and test coverage.

## Next Steps

Continue with Day 03 after completing the Day 02 sanitizer validation, documentation review, and Git workflow.
