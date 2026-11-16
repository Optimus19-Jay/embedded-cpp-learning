# Day 02 – Pointers, References and Pointer Safety

## Overview

The objective of this exercise is to understand pointers, references, and safe pointer handling in modern C++ through a simple sensor data processing module.

The module demonstrates how a function can receive a pointer to a sensor variable, validate the pointer, and update the original value.

## Learning Objectives

- Understand pointers and memory addresses.
- Understand pointer declaration, initialization, and dereferencing.
- Understand the differences between pointers and references.
- Understand `nullptr` and null-pointer safety.
- Use pointers to modify objects through function parameters.
- Understand local constants and `constexpr`.
- Return status values from functions.
- Write unit tests for valid and invalid pointer inputs.
- Organize and build a C++ module using CMake and GoogleTest.

## Requirements

The sensor data module provides a function to update a sensor value.

### Function Interface

```cpp
Status update_sensor_value(std::uint32_t* sensor_value);
```

### Expected Behaviour

1. The function accepts a pointer to a sensor value.
2. If the pointer is `nullptr`, the function returns `Status::STATUS_NULL_POINTER`.
3. If the pointer is valid, the function updates the original sensor value to `250`.
4. A successful update returns `Status::STATUS_OK`.

## Project Structure

```text
day02/
├── CMakeLists.txt
├── README.md
├── include/
│   └── sensor_data.hpp
├── src/
│   └── sensor_data.cpp
└── tests/
    └── test_sensor_data.cpp
```

The shared status definition is maintained separately:

```text
common/
└── include/
    └── status.hpp
```

## Design and Implementation

### 1. Sensor Data Interface

The header file declares the `update_sensor_value()` function.

The function accepts a pointer to `std::uint32_t`, allowing it to modify the original variable supplied by the caller.

### 2. Pointer Validation

Before dereferencing the pointer, the implementation checks whether it is `nullptr`.

This prevents the function from attempting to access an invalid memory address through a null pointer.

### 3. Updating the Sensor Value

A local `constexpr` variable defines the value `250`.

The pointer is dereferenced to update the original sensor variable.

### 4. Status Handling

The function uses the shared `Status` enumeration:

- `STATUS_NULL_POINTER` when the supplied pointer is null.
- `STATUS_OK` when the update succeeds.

## Build System

The lesson uses CMake to define:

- A static library named `sensor_data`.
- A GoogleTest executable named `sensor_data_tests`.

### Configure

Run from the repository root:

```bash
cmake -S . -B build -G Ninja
```

### Build

```bash
cmake --build build
```

### Run Day02 Unit Tests

```bash
ctest --test-dir build -R "^SensorValueUpdateTest" --output-on-failure
```

### Run All Unit Tests

```bash
ctest --test-dir build --output-on-failure
```

## Unit Testing

GoogleTest is used to verify both valid and invalid pointer inputs.

### Test Coverage

| Test | Expected Result |
|---|---|
| Null pointer | `STATUS_NULL_POINTER` |
| Valid pointer | `STATUS_OK` |
| Original sensor value after update | `250` |

Both Day02 test cases passed in the normal build.

## Compiler Warnings and Sanitizer Testing

The lesson targets are compiled with:

```text
-Wall -Wextra -Wpedantic
```

AddressSanitizer (ASan) and UndefinedBehaviorSanitizer (UBSan) are used in a separate build configuration to check for memory errors and undefined behaviour.

## Key Takeaways

Through this exercise, the following concepts were practised:

- Understanding pointers and memory addresses.
- Dereferencing pointers to modify original objects.
- Understanding the difference between pointers and references.
- Using `nullptr` to represent an invalid pointer.
- Performing null checks before dereferencing.
- Using local `constexpr` values.
- Testing valid and invalid function inputs.
- Organizing modules using CMake and GoogleTest.

## Completion Status

**Day 02 – Pointers, References and Pointer Safety: Implementation and normal unit tests completed.**
