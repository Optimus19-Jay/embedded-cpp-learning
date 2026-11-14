add_library(sensor_data STATIC
    src/sensor_data.cpp
)

target_include_directories(sensor_data
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/common/include
)

target_compile_options(sensor_data
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
)

find_package(GTest REQUIRED)

include(GoogleTest)

add_executable(sensor_data_tests
    tests/test_sensor_data.cpp
)

target_link_libraries(sensor_data_tests
    PRIVATE
        sensor_data
        GTest::gtest_main
)

target_compile_options(sensor_data_tests
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
)

gtest_discover_tests(sensor_data_tests)
