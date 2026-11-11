# Day 01 – Firmware Configuration Management

## Overview

The objective of this exercise is to develop a basic firmware configuration module using modern C++.

The module represents firmware configuration parameters and validates them before they are used by the application.

This exercise introduces fundamental C++ concepts through an embedded software scenario.

## Learning Objectives

- Define and use structures in C++.
- Work with fixed-width integer types using `<cstdint>`.
- Use scoped enumerations with `enum class`.
- Separate declarations and implementations using header and source files.
- Understand references and `const` correctness.
- Implement input validation.
- Return status values from functions.
- Organize code into reusable modules.
- Build and test a C++ project using CMake, Ninja, and GoogleTest.

## Requirements

The firmware configuration module contains the following parameters:

| Parameter | Type | Description |
|---|---|---|
| `controller_id` | `std::uint32_t` | Unique controller identifier |
| `firmware_version` | `float` | Firmware version |
| `operating_frequency` | `std::uint32_t` | Operating frequency in Hz |
| `communication_enabled` | `bool` | Indicates whether communication is enabled |
| `diagnostics_enabled` | `bool` | Indicates whether diagnostics are enabled |

### Validation Rules

The configuration is considered valid when:

1. The controller ID is nonzero.
2. The firmware version is at least `1.0`.
3. The operating frequency is between 1,000 Hz and 100,000 Hz, inclusive.
4. Communication is enabled.
5. Diagnostics may be either enabled or disabled.

An invalid parameter causes validation to return `Status::STATUS_INVALID_ARGUMENT`.

A valid configuration returns `Status::STATUS_OK`.

## Project Structure

```text
day01/
├── CMakeLists.txt
├── README.md
├── include/
│   └── firmware_config.hpp
├── src/
│   ├── firmware_config.cpp
│   └── main.cpp
└── tests/
    └── test_firmware_config.cpp
```

The shared status definition is maintained separately:

```text
common/
└── include/
    └── status.hpp
```

## Design and Implementation

### 1. Status Enumeration

A scoped enumeration, `enum class Status`, defines the possible function return statuses.

The enumeration uses `std::uint32_t` as its underlying type and follows the status naming and ordering used in the Embedded C learning repository.

### 2. Firmware Configuration Structure

`FirmwareConfig` groups the configuration parameters into one structure.

This provides a single configuration object that can be passed to the validation function.

### 3. Configuration Validation

The function:

```cpp
Status validate_firmware_config(const FirmwareConfig& config);
```

validates the supplied configuration.

The function accepts a constant reference, avoiding an unnecessary copy while preventing modification of the supplied configuration.

Validation uses fail-fast behavior: the function returns as soon as it encounters an invalid parameter.

### 4. Application

The demo application creates a firmware configuration, validates it, and reports whether the configuration is valid.

## Build System

The lesson uses CMake to define:

- A static library named `firmware_config`.
- A demo executable named `firmware_config_demo`.
- A GoogleTest executable named `firmware_config_tests`.

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

### Run the demo

```bash
./build/week01_cpp_fundamentals/day01/firmware_config_demo
```

### Run unit tests

```bash
ctest --test-dir build --output-on-failure
```

## Unit Testing

GoogleTest is used to verify the configuration validation logic.

A test fixture provides a default valid configuration. Individual tests modify one parameter to check specific validation behavior.

### Test Coverage

| Test | Expected Result |
|---|---|
| Valid configuration | `STATUS_OK` |
| Controller ID is zero | `STATUS_INVALID_ARGUMENT` |
| Firmware version below 1.0 | `STATUS_INVALID_ARGUMENT` |
| Operating frequency below minimum | `STATUS_INVALID_ARGUMENT` |
| Operating frequency above maximum | `STATUS_INVALID_ARGUMENT` |
| Minimum operating frequency | `STATUS_OK` |
| Maximum operating frequency | `STATUS_OK` |
| Communication disabled | `STATUS_INVALID_ARGUMENT` |
| Diagnostics disabled | `STATUS_OK` |

All nine test cases passed in the normal build.

## Compiler Warnings and Sanitizer Testing

The lesson targets are compiled with:

```text
-Wall -Wextra -Wpedantic
```

A separate build was also tested with:

- AddressSanitizer (ASan)
- UndefinedBehaviorSanitizer (UBSan)

All nine tests passed in the sanitizer build without reported sanitizer errors.

## Key Takeaways

Through this exercise, the following concepts were practised:

- Using `enum class` for type-safe status handling.
- Grouping related data using structures.
- Passing objects by constant reference.
- Separating interfaces from implementations.
- Implementing fail-fast validation.
- Creating reusable static libraries.
- Organizing a CMake project into independent targets.
- Writing unit tests with GoogleTest fixtures.
- Testing boundary conditions.
- Using compiler warnings and sanitizers during development.

## Completion Status

**Day 01 – Firmware Configuration Management: Completed**

The implementation, normal unit tests, and sanitizer tests have been completed. Documentation and final Git review remain part of the repository workflow.