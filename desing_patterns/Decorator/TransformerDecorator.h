#pragma once

#include "Decorator.h"
#include <algorithm>
#include <cctype>

class TransformerDecoroator : public Decorator {
public:
    TransformerDecoroator(DataWriter* wrapee) : Decorator(wrapee) {}

    void writeBuffer(const char* data, int length) override {
        std::string str(data, length);
        std::transform(str.begin(), str.end(),str.begin(), std::toupper);
        Decorator::writeBuffer(str.c_str(), str.size());
    }
};

