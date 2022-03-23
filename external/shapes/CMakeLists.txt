cmake_minimum_required (VERSION 3.10)
project (shapes LANGUAGES CXX)
#add_library(shapes SHARED src/circle.cpp)


include(cmake/googletest.cmake)

add_executable(circletest src/circle.test.cpp)

enable_testing()
add_test(NAME circletest COMMAND circletest)
