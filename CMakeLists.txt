cmake_minimum_required (VERSION 3.14)
project (main LANGUAGES CXX)
add_subdirectory (external/liboperations/)
add_subdirectory (external/libshapes/)
add_executable (myprogram main.cpp)
target_include_directories(
    myprogram
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries (myprogram PUBLIC liboperations libshapes)
