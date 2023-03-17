#include "Decorator/Compressor.h"
#include "decorator/FileWriter.h"
#include "decorator/NetworkWriter.h"
#include "decorator/TransformerDecorator.h"
#include "Adapter/School.h"
#include "Adapter/HighSchoolStudent.h"
#include "Adapter/ArmenianStudent.h"
#include "Adapter/ArmenianStudentAdapter.h"
#include "Adapter/ArmenianStudentAdapterInhereted.h"



void testDecoratorPattern()
{
    DataWriter* fileOutput = new FileWriter("test.txt");
    Decorator*  compressor = new Compressor(fileOutput);
    Decorator*  transform = new TransformerDecoroator(compressor);

    transform->writeBuffer("Hello", 5);
}

void testAdapterPattern()
{
    School ysu("YSU", "Yerevan");
    ysu.AddStudent(std::make_shared<HighSchoolStudent>("Armen", "Hovhannisyan", 20));
     auto newAdapter =
                 std::make_shared<ArmenianStudentAdapter>("test", "test", 20);
     ysu.AddStudent(newAdapter);
     
    ysu.PrintAllStudents();
}
int main() {
    testAdapterPattern();

    return 0;

}