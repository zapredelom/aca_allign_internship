#include "Decorator/Compressor.h"
#include "decorator/FileWriter.h"
#include "decorator/NetworkWriter.h"
#include "decorator/TransformerDecorator.h"

int main() {
    DataWriter* fileOutput = new FileWriter("test.txt");
    Decorator*  compressor = new Compressor(fileOutput);
    Decorator*  transform = new TransformerDecoroator(compressor);

    transform->writeBuffer("Hello", 5);

}