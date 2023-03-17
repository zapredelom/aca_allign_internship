#pragma once
class Student {
    public:
    virtual std::string FirstName() = 0;
    virtual std::string LastName() = 0;
    virtual int Age() = 0;
};