cmake_minimum_required (VERSION 3.14)
project (shapes LANGUAGES CXX)
include(cmake/googletest.cmake)
enable_testing()
include(GoogleTest)

# ------------------------------ Circle ------------------------------ #

add_executable(
    CircleTests
    libshapes/round/circle.test.cpp
)
target_include_directories(
    CircleTests
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(
    CircleTests
    gtest_main
)
gtest_discover_tests(CircleTests)

# ----------------------------- Rectangle ---------------------------- #

add_executable(
    RectangleTests
    libshapes/pointy/rectangle.test.cpp
)
target_include_directories(
    RectangleTests
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(
    RectangleTests
    gtest_main
)
gtest_discover_tests(RectangleTests)
