#pragma once
class ArmenianStudentAdapterInhereted : public Student, private ArmenianStudent {
public:
    ArmenianStudentAdapterInhereted(ArmenianStudent* student)
     :ArmenianStudent(*student) { };
    ArmenianStudentAdapterInhereted(const std::string& name, const std::string& lastName, int age):
        ArmenianStudent(name.c_str(), lastName.c_str(), age) {
    }
    std::string FirstName() override { return ArmenianStudent::Name(); }
    std::string LastName() override { return ArmenianStudent::Surname(); }
    int Age() override { return ArmenianStudent::Age(); }

};
