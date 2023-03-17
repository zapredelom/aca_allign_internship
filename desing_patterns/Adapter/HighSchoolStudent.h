#include "Adapter/Student.h"

class HighSchoolStudent: public Student {
    public:
    HighSchoolStudent(std::string firstName, std::string lastName, int age) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;
    }
    std::string FirstName() override {
        return firstName;
    }
    std::string LastName() override {
        return lastName;
    }
    int Age() override {
        return age;
    }
    private:
    std::string firstName;
    std::string lastName;
    int age;
};