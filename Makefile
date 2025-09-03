CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pthread
GTEST_FLAGS = -lgtest -lgtest_main

# Основная программа
program: main.cpp student.cpp student.h
	$(CXX) $(CXXFLAGS) main.cpp student.cpp -o program

# Тесты
test_student: test_student.cpp student.cpp student.h
	$(CXX) $(CXXFLAGS) test_student.cpp student.cpp -o test_student $(GTEST_FLAGS)

# Запуск тестов
test: test_student
	./test_student

# Очистка
clean:
	rm -f program test_student

.PHONY: test clean