#pragma once

class ArmenianStudent {
    public:
    ArmenianStudent(const char* name, const char* lastName, int age):
        name(strdup(name)), surname(strdup(lastName)), age(age) {
    }

    const char* Name() {
        return name;
    }
    const char* Surname() {
        return surname;
    }
    int Age() {
        return age;
    }
    ~ArmenianStudent() {
        delete [] name;
        delete [] surname;
    }

private:
    char* name;
    char* surname;
    int age;
};