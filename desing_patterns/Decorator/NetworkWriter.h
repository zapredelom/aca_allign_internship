#pragma once
#include "DataWriter.h"
#include <string>
#include <iostream>

class NetworkWriter : public DataWriter {
public:
    NetworkWriter(){}
    virtual void writeBuffer(const char* data, int length) {
        std::cout<< "sending to network "<< data <<std::endl;
    }
};