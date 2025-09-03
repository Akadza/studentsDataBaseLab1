#include "student.h"
#include <sstream>
#include <iomanip>

bool Student::isValid() const {
    return !name.empty() &&
        age >= 16 && age <= 100 &&
        !major.empty() &&
        gpa >= 0.0 && gpa <= 4.0;
}

std::string Student::toString() const {
    std::ostringstream oss;
    oss << name << " (" << age << " лет, " << major
        << ", GPA: " << std::fixed << std::setprecision(2) << gpa << ")";
    return oss.str();
}