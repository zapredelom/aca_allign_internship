#pragma once

#include "DataWriter.h"

class Decorator : public DataWriter {
public:
    Decorator(DataWriter* wrapee) : _wrapee(wrapee) {}
    void writeBuffer(const char* data, int length) override {
        _wrapee->writeBuffer(data, length);
    }
    virtual ~Decorator() = 0;

private:
    DataWriter* _wrapee;
};

Decorator::~Decorator() {

}