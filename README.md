# Embedded C++ Learning

A hands-on learning repository for modern C++ with a focus on embedded software development.

The goal of this repository is to build a strong foundation in C++ and gradually apply it to embedded systems concepts, firmware design, testing, and development workflows.

## Learning Goals

This repository is intended to help develop practical skills in:

- Modern C++ fundamentals, starting with C++17.
- Writing readable, maintainable, and testable C++ code.
- Understanding memory, object lifetime, and resource management.
- Applying C++ concepts to embedded firmware scenarios.
- Building and testing projects with CMake and Ninja.
- Debugging and validating code with appropriate development tools.
- Understanding how C++ design choices affect resource-constrained systems.

The exercises are developed incrementally. Each lesson introduces a small set of concepts and applies them in a practical example.

## Learning Roadmap

The roadmap is intended to progress from language fundamentals toward embedded software design. Topics may be adjusted as the exercises develop.

| Stage | Focus |
|---|---|
| Week 1 | C++ fundamentals |
| Week 2 | Classes, objects, and encapsulation |
| Week 3 | Pointers, references, memory, and object lifetime |
| Week 4 | RAII, constructors, destructors, and resource management |
| Week 5 | Move semantics, lambdas, and standard library fundamentals |
| Week 6 | Templates and generic programming |
| Week 7 | Modern C++ features and embedded-oriented applications |
| Week 8 | Embedded software architecture and design |
| Week 9 | Testing, debugging, and concurrency fundamentals |
| Week 10 | Practical embedded C++ exercises and a capstone project |

This is a learning roadmap, not a promise that every topic will be covered in exactly one week.

## Development Environment

The current development environment is:

| Tool | Version / Configuration |
|---|---|
| Operating system | Ubuntu 24.04 on WSL2 |
| Compiler | GCC / G++ 13.3.0 |
| CMake | 3.28.3 |
| Build system | Ninja 1.11.1 |
| Debugger | GDB 15.1 |
| Formatter | clang-format 18.1.3 |
| Unit testing | GoogleTest 1.14.0 |
| IDE / editor | Visual Studio Code with WSL support |
| C++ standard | C++17 baseline |

The project uses C++17 as its current baseline. Newer C++ standards and features can be explored in separate exercises when the compiler and learning objectives justify doing so.

## Repository Structure

```text
embedded-cpp-learning/
├── CMakeLists.txt
├── README.md
├── .gitignore
├── common/
│   └── include/
│       └── status.hpp
└── week01_cpp_fundamentals/
    └── day01/
        ├── CMakeLists.txt
        ├── README.md
        ├── include/
        ├── src/
        └── tests/
```

### Directory Responsibilities

- `common/`: Headers and definitions intended to be reused by multiple lessons. Keep this area small and add shared components only when there is a clear need.
- `weekXX_topic/`: Groups lessons that belong to the same learning area or week.
- `dayXX/`: A self-contained exercise or small project, including its own source, headers, tests, and lesson-level CMake configuration.
- `tests/`: Unit tests for the lesson's implementation.
- `README.md` files: Explain the repository, weekly learning objectives, or the details of an individual exercise depending on their location.

The repository will grow as more lessons are added. The structure above shows the current layout and the intended organization; not every planned directory exists yet.

## Build System Architecture

The project uses CMake to organize the exercises and Ninja to perform the builds.

### Root `CMakeLists.txt`

The root CMake file contains project-wide configuration:

- Declares the minimum supported CMake version.
- Declares the project name and enables the C++ language.
- Sets C++17 as the required language standard.
- Disables compiler-specific C++ language extensions.
- Includes CTest so tests registered by lesson subdirectories can be discovered from the root build.
- Adds the lesson directory that is currently included in the build.

The root file currently adds `week01_cpp_fundamentals/day01`. As more lessons are created, lesson directories can be added deliberately. This keeps the active build focused instead of automatically building every exercise in the repository.

### Lesson-level `CMakeLists.txt`

Each lesson has its own CMake file. It is responsible for defining that lesson's build targets and dependencies, such as:

- Libraries built from the lesson's source files.
- Demo or application executables.
- Include directories required by the lesson and shared headers.
- Unit-test executables and their test framework dependencies.
- Compiler warning options applied to the lesson's targets.
- Registration of unit tests with CTest.

This separation keeps the root CMake file small and lets each lesson describe how its own code is built.

### Build and Test Workflow

Run these commands from the repository root.

**1. Configure the project**

```bash
cmake -S . -B build -G Ninja
```

**2. Build the configured targets**

```bash
cmake --build build
```

**3. Run the registered tests**

```bash
ctest --test-dir build --output-on-failure
```

The `build/` directory contains generated build files and compiled outputs. It is ignored by Git and should not be committed.

To add another lesson to the active build, add its directory to the root `CMakeLists.txt` with `add_subdirectory(...)`.

## Code Quality and Testing

The exercises aim to use compiler diagnostics and automated tests as part of normal development.

Current practices include:

- Compile with `-Wall`, `-Wextra`, and `-Wpedantic` for the Day 01 targets.
- Write unit tests with GoogleTest.
- Run tests through CTest.
- Use AddressSanitizer and UndefinedBehaviorSanitizer in a separate build when appropriate.
- Use GDB when debugging is required.
- Use clang-format to keep formatting consistent.

Sanitizers can help detect certain memory and undefined-behavior issues on the code paths exercised, but passing sanitizer tests does not prove that a program is free of defects.

## Development Workflow

For each exercise:

1. Read the lesson objectives and requirements.
2. Implement the exercise in small steps.
3. Build the code and resolve compiler warnings.
4. Add or update unit tests for expected behavior and boundary conditions.
5. Run the complete test suite for the active build.
6. Use debugging tools or sanitizers when they are relevant.
7. Update the lesson README with implementation details and what was learned.
8. Review the changes before committing them.

The exercises are designed to encourage understanding and independent implementation rather than copying complete solutions.

## Related Learning

This repository complements the Embedded C learning work. Concepts such as status handling, validation, modular source organization, and testing may appear in both repositories. The C++ exercises will use C++ language features and idioms rather than simply translating C code line by line.

## Progress

Progress is tracked in the individual week and lesson directories. The root README describes the overall project and development setup; detailed implementation notes and test coverage belong in the relevant lesson README.