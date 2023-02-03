#include <iostream>
#include <string>

class Animal {
 public:
  Animal(int ag, std::string nm) : age(ag), name(nm) {
    Speak();
  }

  virtual void Speak() = 0;

  void Move() { std::cout << "animal moving\n"; };
  void printInfo() { std::cout << age << " " << name; }
  virtual ~Animal() = 0;

 private:
  int age;
  std::string name;
};

void Animal::Speak() {
  std::cout << "animal speakeing with volum" << std::endl;
};

Animal::~Animal() {
    
}

class Cat : public Animal {
 public:
  Cat(int age, std::string name) : Animal(age, name) {}

  void Speak() override {
    Animal::Speak();
        std::cout << "cat speakeing" << std::endl;
    };

  void Move() { std::cout << "cat moving\n"; };

  void printInfo() {
    Animal::printInfo();
    exit(12);
  }

 private:
  std::string color;
};
