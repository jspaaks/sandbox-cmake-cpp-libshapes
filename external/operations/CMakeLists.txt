cmake_minimum_required (VERSION 3.10)

project(
    operations
    LANGUAGES CXX
)

add_library (
    operations
    src/addition.cpp
    src/subtraction.cpp
)

set_target_properties(
    operations PROPERTIES
    SOVERSION 0
    VERSION 0.1.0
)

target_include_directories (
    operations
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
)
