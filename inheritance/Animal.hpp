#include <string>
#include <iostream>

class Animal{
public:
    Animal(int ag, std::string nm): age(ag), name(nm) {}
    void Speak();
    void Move();
    void printInfo(){
        std::cout<<age<< " "<< name;
    }
    private:
        int age;
        std::string name;
};


class Cat : public Animal{
    public:
    Cat(int age, std::string name) :Animal(age, name){}
    void printInfo(){
        Animal::printInfo();
        exit(12);

    }
    private:
    std::string color;
};
