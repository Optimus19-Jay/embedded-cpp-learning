cmake_minimum_required(VERSION 3.20)

project(EmbeddedCppLearning
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

add_subdirectory(week01_cpp_fundamentals/day01)
add_subdirectory(week01_cpp_fundamentals/day02)