#ifndef STUDENT_H
#define STUDENT_H

#include <string>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;

    bool isValid() const;
    std::string toString() const;
};

#endif