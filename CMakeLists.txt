cmake_minimum_required (VERSION 3.14)
project (shapes LANGUAGES CXX)

# Not specifying library type SHARED|STATIC is deliberate
add_library(
    libshapes
    libshapes/pointy/rectangle.cpp
    libshapes/round/circle.cpp
)

target_include_directories(
    libshapes
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

include(cmake/testing.cmake)
