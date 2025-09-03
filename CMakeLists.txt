cmake_minimum_required(VERSION 3.14)
project(StudentDatabase)

set(CMAKE_CXX_STANDARD 17)

# Основная программа
add_executable(program main.cpp student.cpp)

# Тесты
add_executable(test_student test_student.cpp student.cpp)

# Скачиваем и подключаем GoogleTest автоматически
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9fd718599d30c5a80e5b8c3.zip
)
FetchContent_MakeAvailable(googletest)

# Подключаем тесты
target_link_libraries(test_student PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(test_student)