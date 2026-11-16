add_library(sensor_buffer STATIC
    src/sensor_buffer.cpp
)

target_include_directories(sensor_buffer
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/common/include
)

target_compile_options(sensor_buffer
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
)

find_package(GTest REQUIRED)

include(GoogleTest)

add_executable(sensor_buffer_tests
    tests/test_sensor_buffer.cpp
)

target_link_libraries(sensor_buffer_tests
    PRIVATE
        sensor_buffer
        GTest::gtest_main
)

target_compile_options(sensor_buffer_tests
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
)

gtest_discover_tests(sensor_buffer_tests)
