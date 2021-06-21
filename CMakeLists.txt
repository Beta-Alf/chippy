
project(chippy)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCES
    src/main.cpp
    src/low_level.cpp
    src/high_level.cpp)

add_executable(chippy
    ${SOURCES})
