add_library(firmware_config STATIC
    src/firmware_config.cpp
)

target_include_directories(firmware_config
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/common/include
)

target_compile_options(firmware_config
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
)

add_executable(firmware_config_demo
    src/main.cpp
)

target_link_libraries(firmware_config_demo
    PRIVATE
        firmware_config
)

target_compile_options(firmware_config_demo
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
)

find_package(GTest REQUIRED)

include(GoogleTest)

add_executable(firmware_config_tests
    tests/test_firmware_config.cpp
)

target_link_libraries(firmware_config_tests
    PRIVATE
        firmware_config
        GTest::gtest_main
)

target_compile_options(firmware_config_tests
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
)

gtest_discover_tests(firmware_config_tests)
