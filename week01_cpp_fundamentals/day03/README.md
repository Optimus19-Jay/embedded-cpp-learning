# Day 03 – Arrays and Fixed-Size Sensor Buffers

## Overview

The objective of this exercise is to develop a fixed-size sensor data buffer using modern C++.

The module stores temperature readings in a fixed-size array and provides functionality to insert and retrieve readings safely.

This exercise introduces array handling, bounds validation, references, and fixed-size storage through an embedded software scenario.

## Learning Objectives

- Understand C-style arrays and `std::array`.
- Use fixed-size arrays for predictable memory storage.
- Understand zero-based array indexing.
- Use compile-time constants with `static constexpr`.
- Understand array capacity and bounds validation.
- Pass objects using references and constant references.
- Use reference parameters for returning output values.
- Implement safe buffer operations.
- Write unit tests using GoogleTest.
- Build and validate a C++ project using CMake, Ninja, and sanitizers.

## Requirements

The sensor buffer module contains the following members:

| Member | Type | Description |
|---|---|---|
| `CAPACITY` | `static constexpr std::size_t` | Maximum number of temperature readings (5) |
| `temperature_buffer` | `std::array<float, CAPACITY>` | Stores temperature readings |
| `counter` | `std::uint16_t` | Tracks the number of successfully stored readings |

### Buffer Operations

The module provides two operations:

1. `add_reading()` inserts a temperature reading into the next available position.
2. `get_reading()` retrieves a previously stored temperature reading using its index.

### Validation Rules

For adding a reading:

- The buffer must have available capacity.
- The reading is stored at the index indicated by the counter.
- The counter is incremented only after successful insertion.
- An attempt to insert into a full buffer returns `Status::STATUS_BUFFER_FULL`.

For retrieving a reading:

- The requested index must be within the physical array capacity.
- A reading must already exist at the requested index.
- Invalid requests return `Status::STATUS_INVALID_ARGUMENT`.
- The output temperature remains unchanged when retrieval fails.

## Project Structure

```text
day03/
├── CMakeLists.txt
├── README.md
├── include/
│   └── sensor_buffer.hpp
├── src/
│   └── sensor_buffer.cpp
└── tests/
    └── test_sensor_buffer.cpp
```

The shared status definition is maintained separately:

```text
common/
└── include/
    └── status.hpp
```

## Design and Implementation

### 1. Sensor Buffer Structure

The `SensorBuffer` structure groups the temperature array and its reading counter.

The buffer uses `std::array` to provide fixed-size storage.

The capacity is defined using `static constexpr`, making it available as a compile-time constant.

The counter is initialized to zero.

### 2. Adding Sensor Readings

The function:

```cpp
Status add_reading(SensorBuffer& buffer, float temperature);
```

adds a temperature reading to the buffer.

The function accepts the buffer by reference because it modifies the original object.

The implementation:

- Checks whether the buffer is full.
- Stores the temperature at the next available index.
- Increments the counter after successful insertion.
- Returns the appropriate status.

### 3. Retrieving Sensor Readings

The function:

```cpp
Status get_reading(
    const SensorBuffer& buffer,
    std::size_t index,
    float& temperature
);
```

retrieves a previously stored temperature.

The function uses:

- A constant reference for the input buffer.
- An index to identify the requested reading.
- An output reference to provide the retrieved temperature.

The implementation validates the requested index before accessing the array.

The output parameter is updated only when retrieval succeeds.

## Build System

The lesson uses CMake to define:

- A static library named `sensor_buffer`.
- A GoogleTest executable named `sensor_buffer_tests`.

The root CMake configuration includes this lesson as an active build directory.

### Configure

Run from the repository root:

```bash
cmake -S . -B build -G Ninja
```

### Build

```bash
cmake --build build
```

### Run all unit tests

```bash
ctest --test-dir build --output-on-failure
```

### Run Day03 unit tests

```bash
ctest --test-dir build -R "^SensorBuffer" --output-on-failure
```

## Unit Testing

GoogleTest is used to verify sensor buffer operations.

### Test Coverage

| Test | Expected Result |
|---|---|
| Starts with empty buffer | Counter initialized to zero |
| Stores first reading | `STATUS_OK` |
| Stores readings in order | `STATUS_OK` |
| Rejects extra readings when full | `STATUS_BUFFER_FULL` |
| Reads temperature at valid index | `STATUS_OK` |
| Rejects unpopulated index | `STATUS_INVALID_ARGUMENT` |
| Rejects out-of-capacity index | `STATUS_INVALID_ARGUMENT` |

All seven test cases passed in the normal build.

## Compiler Warnings and Sanitizer Testing

The lesson targets are compiled with:

```text
-Wall -Wextra -Wpedantic
```

A separate build was also tested with:

- AddressSanitizer (ASan)
- UndefinedBehaviorSanitizer (UBSan)

All seven Day03 tests passed in the sanitizer build without reported sanitizer errors.

The complete Week01 test suite also passed all 18 tests.

## Compiler Warnings and Sanitizer Testing

### Compiler Warnings

The project enables the following compiler warnings:

- `-Wall`
- `-Wextra`
- `-Wpedantic`

These options help identify potential coding issues during compilation.

### AddressSanitizer (ASan) and UndefinedBehaviorSanitizer (UBSan)

The project was also validated using AddressSanitizer and UndefinedBehaviorSanitizer to detect memory-safety issues and undefined behavior.

Configure a separate sanitizer build:

```bash
cmake -S . -B build-sanitize -G Ninja \
  -DCMAKE_CXX_FLAGS="-fsanitize=address,undefined -fno-omit-frame-pointer" \
  -DCMAKE_EXE_LINKER_FLAGS="-fsanitize=address,undefined"
```

Build the project:

```bash
cmake --build build-sanitize
```

Run all tests with sanitizers enabled:

```bash
ctest --test-dir build-sanitize --output-on-failure
```

Run only the Day03 sensor buffer tests:

```bash
ctest --test-dir build-sanitize -R "^SensorBuffer" --output-on-failure
```

**Validation Results:**

- Normal build completed successfully.
- All 18 Week01 unit tests passed.
- All 18 tests passed with AddressSanitizer and UndefinedBehaviorSanitizer enabled.
- No sanitizer errors were reported.

The separate `build-sanitize` directory keeps sanitizer build artifacts isolated from the normal build.

## Key Takeaways

Through this exercise, the following concepts were practised:

- Using `std::array` for fixed-size storage.
- Defining compile-time constants using `static constexpr`.
- Understanding zero-based indexing.
- Validating array boundaries.
- Passing objects by reference and constant reference.
- Using output reference parameters.
- Implementing safe buffer operations.
- Testing boundary conditions using GoogleTest.
- Applying compiler warnings and sanitizers.

## Completion Status

**Day 03 – Arrays and Fixed-Size Sensor Buffers: Completed**

The implementation, seven unit tests, full Week01 test suite, and sanitizer validation have been completed. Documentation and final Git review remain part of the repository workflow.