#pragma once
#include "DataWriter.h"
#include <string>
#include <iostream>
#include <fstream>


class FileWriter : public DataWriter {
public:
    FileWriter(const std::string& fname) : _fName(fname){}
    virtual void writeBuffer(const char* data, int length) {
        std::cout<< "writing to file"<<std::endl;
        std::ofstream file(_fName, std::ios::out);
        file.write(data, length);
    }

private:
    std::string _fName;
};