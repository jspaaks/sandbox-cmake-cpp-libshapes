add_library (operations src/addition.cpp src/subtraction.cpp)
target_include_directories (operations PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
