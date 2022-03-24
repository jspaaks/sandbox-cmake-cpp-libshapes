cmake_minimum_required (VERSION 3.14)
project (shapes LANGUAGES CXX)
include(cmake/googletest.cmake)
enable_testing()
include(GoogleTest)

add_executable(CircleTests src/round/circle.test.cpp)
target_link_libraries(CircleTests gtest_main)
gtest_discover_tests(CircleTests)

add_executable(RectangleTests src/pointy/rectangle.test.cpp)
target_link_libraries(RectangleTests gtest_main)
gtest_discover_tests(RectangleTests)

