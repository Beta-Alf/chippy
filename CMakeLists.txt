cmake_minimum_required(VERSION 3.12)

project(chippy VERSION 0.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCES
    src/high_level.cpp
    src/low_level.cpp
)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/355d57d90d9744c41ac7c99f1e960778f1c63040.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(machinery
    STATIC
    ${SOURCES})

add_executable(chippy
    src/main.cpp)

target_link_libraries(chippy
    PRIVATE
    machinery)

enable_testing()

add_executable(tests
    test/main_test.cpp)

target_link_libraries(
    tests
    machinery
    gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)
