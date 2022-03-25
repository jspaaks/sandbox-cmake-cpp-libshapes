cmake_minimum_required (VERSION 3.10)
project(operations LANGUAGES CXX)

# Not specifying library type SHARED|STATIC is deliberate
add_library (
    liboperations
    liboperations/addition.cpp
    liboperations/subtraction.cpp
)

set_target_properties(
    liboperations PROPERTIES
    SOVERSION 0
    VERSION 0.1.0
)

target_include_directories (
    liboperations
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
