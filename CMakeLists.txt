cmake_minimum_required(VERSION 3.10)

project(CPU_emulator VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(main main.cpp)
add_subdirectory(stack)

target_link_libraries(main PUBLIC stack)
target_include_directories(main PUBLIC "${PROJECT_BINARY_DIR}") 

enable_testing()
include(GoogleTest)

add_executable(stack_test stack/test.cpp)
target_link_libraries(stack_test stack gtest)

gtest_discover_tests(stack_test)