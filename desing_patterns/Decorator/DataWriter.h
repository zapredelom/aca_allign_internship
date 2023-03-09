#pragma once
class DataWriter {
    public:
    virtual void writeBuffer(const char* data, int length) = 0;
};