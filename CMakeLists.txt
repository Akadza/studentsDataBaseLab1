cmake_minimum_required(VERSION 3.14)
project(StudentDatabase)

set(CMAKE_CXX_STANDARD 17)

# Основная программа
add_executable(program main.cpp student.cpp)

# Тесты
enable_testing()

add_executable(test_student test_student.cpp student.cpp)
target_link_libraries(test_student PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_student)