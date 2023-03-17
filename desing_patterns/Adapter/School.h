#pragma once
#include <memory>
#include <vector>

#include "Adapter/Student.h"
class School {
public:
    using StudentPtr = std::shared_ptr<Student>;
public:
    School(std::string name, std::string address) {}
    std::string Name();
    std::string Address();
    void AddStudent(StudentPtr student) { students.push_back(student); }
    void PrintAllStudents() {
        for (auto student : students) {
            std::cout << student->FirstName() << " " << student->LastName() << " " << student->Age() << std::endl;
        }
    }

private:
    std::vector<StudentPtr> students;
};