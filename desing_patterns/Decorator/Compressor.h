#pragma once

#include "DataWriter.h"
#include "Decorator.h"
#include <string>

class Compressor : public Decorator {
public:
    Compressor(DataWriter* wrapee) : Decorator(wrapee) {}
     void writeBuffer(const char* data, int length) override {
        std::string compressed (data, length - 2);
        Decorator::writeBuffer(compressed.c_str(), compressed.size());
     }
};