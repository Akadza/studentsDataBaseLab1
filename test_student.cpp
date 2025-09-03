#include <gtest/gtest.h>
#include "student.h"
#include <vector>
#include <fstream>

TEST(StudentTest, IsValidMethod) {
    Student validStudent{ "���� ������", 20, "Computer Science", 3.8 };
    EXPECT_TRUE(validStudent.isValid());

    Student invalidAge{ "���� ������", 15, "Math", 3.5 };
    EXPECT_FALSE(invalidAge.isValid());

    Student invalidGPA{ "����� ��������", 22, "Physics", 4.5 };
    EXPECT_FALSE(invalidGPA.isValid());

    Student emptyName{ "", 21, "Chemistry", 3.2 };
    EXPECT_FALSE(emptyName.isValid());
}

TEST(StudentTest, ToStringMethod) {
    Student student{ "���� �������", 19, "Biology", 3.9 };
    std::string expected = "���� ������� (19 ���, Biology, GPA: 3.90)";
    EXPECT_EQ(student.toString(), expected);
}

TEST(StudentFunctionsTest, AddStudentValidation) {
    std::vector<Student> database;
    Student student{ "", 25, "History", 3.0 };

    database.push_back(student);
    EXPECT_FALSE(database.back().isValid());
}

TEST(StudentFunctionsTest, FileOperations) {
    std::vector<Student> database;
    database.push_back({ "���� ������", 20, "CS", 3.8 });
    database.push_back({ "����� �������", 22, "Math", 4.0 });

    std::ofstream out("test_students.txt");
    for (const auto& student : database) {
        out << student.name << "," << student.age << ","
            << student.major << "," << student.gpa << "\n";
    }
    out.close();

    std::ifstream in("test_students.txt");
    EXPECT_TRUE(in.is_open());
    in.close();
}

TEST(StudentFunctionsTest, DatabaseOperations) {
    std::vector<Student> database;

    EXPECT_TRUE(database.empty());
    database.push_back({ "���� �������", 21, "Test", 3.5 });
    EXPECT_FALSE(database.empty());
    EXPECT_EQ(database.size(), 1);

    database.clear();
    EXPECT_TRUE(database.empty());
}

TEST(StudentBoundaryTest, AgeBoundaries) {
    Student minAge{ "�������", 16, "Test", 3.0 };
    Student maxAge{ "�������", 100, "Test", 3.0 };
    Student tooYoung{ "�������", 15, "Test", 3.0 };
    Student tooOld{ "�������", 101, "Test", 3.0 };

    EXPECT_TRUE(minAge.isValid());
    EXPECT_TRUE(maxAge.isValid());
    EXPECT_FALSE(tooYoung.isValid());
    EXPECT_FALSE(tooOld.isValid());
}

TEST(StudentBoundaryTest, GPABoundaries) {
    Student minGPA{ "�������", 20, "Test", 0.0 };
    Student maxGPA{ "�������", 20, "Test", 4.0 };
    Student negativeGPA{ "�������", 20, "Test", -0.1 };
    Student tooHighGPA{ "�������", 20, "Test", 4.1 };

    EXPECT_TRUE(minGPA.isValid());
    EXPECT_TRUE(maxGPA.isValid());
    EXPECT_FALSE(negativeGPA.isValid());
    EXPECT_FALSE(tooHighGPA.isValid());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}