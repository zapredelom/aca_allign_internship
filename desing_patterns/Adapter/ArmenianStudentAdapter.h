#pragma once
#include <memory>
class ArmenianStudentAdapter : public Student {
public:
    ArmenianStudentAdapter(std::shared_ptr<ArmenianStudent>student) { this->_student = student; };
    ArmenianStudentAdapter(const std::string& name, const std::string& lastName, int age) {
        _student =  std::make_shared<ArmenianStudent>(name.c_str(), lastName.c_str(), age);
    }
    std::string FirstName() override { return _student->Name(); }
    std::string LastName() override { return _student->Surname(); }
    int Age() override { return _student->Age(); }

private:
    std::shared_ptr<ArmenianStudent> _student;
};