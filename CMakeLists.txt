cmake_minimum_required(VERSION 3.14)
project(StudentDatabase)

enable_testing()

set(CMAKE_CXX_STANDARD 17)

# Основная программа
add_executable(program main.cpp student.cpp)

add_executable(test_student test_student.cpp student.cpp)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

target_link_libraries(test_student PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(test_student)
